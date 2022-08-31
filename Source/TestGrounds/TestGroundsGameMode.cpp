// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestGroundsGameMode.h"
#include "TestGroundsHUD.h"
#include "TestGroundsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestGroundsGameMode::ATestGroundsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATestGroundsHUD::StaticClass();
}
