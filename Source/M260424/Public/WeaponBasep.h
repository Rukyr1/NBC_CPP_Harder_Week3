// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBasep.generated.h"

UCLASS()
class M260424_API AWeaponBasep : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBasep();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USceneComponent> Root;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UArrowComponent> FirePoint;
	
	UFUNCTION(BlueprintCallable)
	virtual void Fire();

 

protected:

	//소모되는 탄약수
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 AmmoPerFire;
	//남은 탄약수
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	int32 CurrentAmmo;
	//탄약 보유량
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxAmmo;
	//연사속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RoF;
	//유효사거리
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Range;
	//데미지양
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DamagePerHit;
	//쏠수있나
	UPROPERTY(BlueprintReadWrite)
	bool CanFire;
	//연사속도 제어를 위한 핸들
	FTimerHandle TimerFireDelay;
	UFUNCTION()
	void HandleFireDelay();
};
