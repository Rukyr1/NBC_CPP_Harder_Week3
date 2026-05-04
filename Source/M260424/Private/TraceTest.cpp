// Fill out your copyright notice in the Description page of Project Settings.


#include "TraceTest.h"

#include "MyTestDamageType.h"
#include "DSP/LFO.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"



// Sets default values
ATraceTest::ATraceTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	PelletCount = 8;
	Spread = 5.f;
}

// Called when the game starts or when spawned
void ATraceTest::BeginPlay()
{
	Super::BeginPlay();
	
	//StartAsyncTrace();
	
}

// Called every frame
void ATraceTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	StartAsyncTrace();
	
}

void ATraceTest::StartAsyncTrace()
{
	FCollisionResponseParams ResponseParams; // 기본 생성만
	//ResponseParams.CollisionResponse.WorldDynamic = ECR_Overlap;
	
	// -----
	// 분리
	FVector Start = GetActorLocation();
	
	for (int i = 0; i < PelletCount; i++)
	{
		// 랜덤 퍼짐 방향
		FVector RandomDirection = GetActorForwardVector();
		RandomDirection = FMath::VRandCone(RandomDirection, FMath::DegreesToRadians(Spread));
	
		FVector End = Start + RandomDirection * 1000.f;
	
		// 총알마다 Delegate 생성
		FTraceDelegate TraceDelegate;
		TraceDelegate.BindUObject(this, &ATraceTest::OnAsyncTraceCompleted);
	
		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(this);
		QueryParams.bTraceComplex = false;
	
		GetWorld()->AsyncLineTraceByChannel(
			EAsyncTraceType::Multi,
			GetActorLocation(),
			GetActorForwardVector() * 1000.f + GetActorLocation(),
			ECC_Visibility,
			QueryParams,
			ResponseParams,
			&TraceDelegate
			);
	
		// 발사 방향 확인
		DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, .1f, 0, 1.f);
	}
}

void ATraceTest::OnAsyncTraceCompleted(const FTraceHandle& TraceHandle, FTraceDatum& Datum)
{
	for (const FHitResult& Hit : Datum.OutHits)
	{
		AActor* HitActor = Hit.GetActor();
		
		// 크래시 방지
		if (!HitActor)
		{
			continue;
		}
		
		GEngine->AddOnScreenDebugMessage(
			-1, 
			0.0f, 
			FColor::Green, 
			FString::Printf(
				TEXT("Hit Actor: %s"), *HitActor->GetName())
				);
		
		DrawDebugSphere(
			GetWorld(), 
			Hit.ImpactPoint, 
			20.f, 
			12, 
			FColor::Green, 
			false, 
			2.f
			);
		
		UGameplayStatics::ApplyPointDamage(
			HitActor,
			50.f,
			Hit.TraceStart - Hit.TraceStart,
			Hit,
			GetInstigatorController(),
			this,
			UMyTestDamageType::StaticClass()
			);
	}
}
