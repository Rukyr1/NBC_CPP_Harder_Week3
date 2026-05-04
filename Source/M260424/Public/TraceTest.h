// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldCollision.h"
#include "TraceTest.generated.h"

UCLASS()
class M260424_API ATraceTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATraceTest();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PelletCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Spread = 5.f;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void StartAsyncTrace();
	
	void OnAsyncTraceCompleted(const FTraceHandle& TraceHandle, FTraceDatum& Datum);
};
