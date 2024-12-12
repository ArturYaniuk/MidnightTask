// Copyright Epic Games, Inc. All Rights Reserved.

#include "MidnightTaskGameMode.h"
#include "MidnightTaskCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMidnightTaskGameMode::AMidnightTaskGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
