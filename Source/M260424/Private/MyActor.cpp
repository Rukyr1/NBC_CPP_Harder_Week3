// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	
	//UGameplayStatics::ApplyDamage()
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//StartSingleTrace();
}

// UWorld에서 가져오는 방식(매우 자유로움)
void AMyActor::StartAsyncTrace()
{
	FTraceDelegate TraceDelegate;
	TraceDelegate.BindUObject(this, &AMyActor::OnAsyncTraceCompleted);
	
	FCollisionResponseParams ResponseParams;
	ResponseParams.CollisionResponse.WorldDynamic = ECR_Overlap;
	
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);
	QueryParams.bTraceComplex = false;
	
	// GetWorld()->AsyncLineTraceByChannel(
	// 	EAsyncTraceType::Multi, 
	// 	GetActorLocation(), 
	// 	GetActorForwardVector() * 1000.0f + GetActorLocation(),
	// 	ECC_Visibility,
	// 	QueryParams,
	// 	&TraceDelegate,
	// 	)
}

void AMyActor::OnAsyncTraceCompleted(const FTraceHandle& Handle, FTraceDatum& Data)
{
	for (const FHitResult& Hit : Data.OutHits)
	{
		AActor* HitActor = Hit.GetActor();
		
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Green, FString::Printf(TEXT("Hit Actor: %s"), *HitActor->GetName()));
		
		DrawDebugSphere(GetWorld(), Hit.ImpactPoint, 20.0f, 12, FColor::Green, false, 2.0f);
	}
}

void AMyActor::StartSingleTrace()
{
	TArray<FHitResult> HitResult;
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);
	
	// UKismetSystemLibrary::LineTraceSingle(
	// 	GetWorld(), 
	// 	GetActorLocation(), 
	// 	GetActorForwardVector() * 1000.0f + GetActorLocation(), 
	// 	UEngineTypes::ConvertToTraceType(ECC_Visibility), 
	// 	false,
	// 	ActorsToIgnore, 
	// 	EDrawDebugTrace::ForOneFrame, 
	// 	HitResult, 
	// 	true, 
	// 	FLinearColor::Red, 
	// 	FLinearColor::Green);
	
	UKismetSystemLibrary::LineTraceMulti(
		GetWorld(), 
		GetActorLocation(), 
		GetActorForwardVector() * 1000.0f + GetActorLocation(), 
		UEngineTypes::ConvertToTraceType(ECC_Visibility), 
		false,
		ActorsToIgnore, 
		EDrawDebugTrace::ForOneFrame, 
		HitResult, 
		true, 
		FLinearColor::Red, 
		FLinearColor::Green);
	
	// UKismetSystemLibrary::LineTraceMulti(
	// 	GetWorld(),
	// 	GetActorLocation(),
	// 	GetActorForwardVector() * 1000.f + GetActorLocation(),
	// 	UEngineTypes::ConvertToTraceType(ECC_Visibility),
	// 	false,
	// 	ActorsToIgnore,
	// 	EDrawDebugTrace::ForOneFrame,
	// 	HitResult,
	// 	true,
	// 	FLinearColor::Red,
	// 	FLinearColor::Green);
}

