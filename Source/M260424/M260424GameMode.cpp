// Copyright Epic Games, Inc. All Rights Reserved.

#include "M260424GameMode.h"
#include "M260424Character.h"
#include "UObject/ConstructorHelpers.h"

AM260424GameMode::AM260424GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
