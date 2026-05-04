// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponBasep.h"
#include "BP_WeaponTemplateBase.generated.h"

/**
 * 
 */
UCLASS()
class M260424_API ABP_WeaponTemplateBase : public AWeaponBasep
{
	GENERATED_BODY()
	
public:
	virtual void Fire() override;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Reload();
	
protected:
	UFUNCTION(BlueprintNativeEvent)
	bool CheckAmmo();
	
	// BP 위임
	// 총을 어떻게 쏠지
	UFUNCTION(BlueprintImplementableEvent)
	void ProcessFiring();
	// 이펙트 실행
	UFUNCTION(BlueprintImplementableEvent)
	void PlayEffects();
	
	UFUNCTION(BlueprintNativeEvent)
	void UnRoadAmmo();
};
