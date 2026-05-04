// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBasep.h"
#include "LandscapeDataAccess.h"
#include "Components/ArrowComponent.h"

// Sets default values
AWeaponBasep::AWeaponBasep()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	FirePoint = CreateDefaultSubobject<UArrowComponent>(TEXT("FirePoint"));
	FirePoint->SetupAttachment(RootComponent);
	
	AmmoPerFire = 1;
	CurrentAmmo = 0;
	MaxAmmo = 12;
	RoF = 1.f;
	CanFire = true;
	Range = 1000.f;
	DamagePerHit = 100.f;
}

// Called when the game starts or when spawned
void AWeaponBasep::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentAmmo = MaxAmmo;
	
}

void AWeaponBasep::Fire()
{
	CanFire = false;
	
	GetWorld()->GetTimerManager().SetTimer(TimerFireDelay, this, &AWeaponBasep::HandleFireDelay, 1.f/RoF, false);
}

void AWeaponBasep::HandleFireDelay()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerFireDelay);
	CanFire = true;
}
