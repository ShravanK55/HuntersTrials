// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "HuntersTrials.h"
#include "HuntersTrialsGameMode.h"
#include "HuntersTrialsHUD.h"

AHuntersTrialsGameMode::AHuntersTrialsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Dynamic/Character/Behaviour/GameCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AHuntersTrialsHUD::StaticClass();
}
