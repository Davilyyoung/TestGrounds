// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestGroundsGameMode.h"
#include "TestGroundsHUD.h"
#include "UObject/ConstructorHelpers.h"

ATestGroundsGameMode::ATestGroundsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("Blueprint'/Game/Player/FPP_Blueprints/BP_FirstPersonCharacter.BP_FirstPersonCharacter_C'"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATestGroundsHUD::StaticClass();
}
