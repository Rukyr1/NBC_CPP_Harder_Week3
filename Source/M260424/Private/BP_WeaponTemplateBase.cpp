// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_WeaponTemplateBase.h"


void ABP_WeaponTemplateBase::Fire()

{

	if (!CanFire) return;

 

	if (CheckAmmo())
	{
		//순서를 여기서 저희 맘대로!!!!!!
		PlayEffects();
		ProcessFiring();
		CheckAmmo();
		Super::Fire();
		return;
	}
}

void ABP_WeaponTemplateBase::Reload_Implementation()
{
	CurrentAmmo = MaxAmmo;
}

bool ABP_WeaponTemplateBase::CheckAmmo_Implementation()
{
	return AmmoPerFire <= CurrentAmmo;
}

void ABP_WeaponTemplateBase::UnRoadAmmo_Implementation()
{
	
}