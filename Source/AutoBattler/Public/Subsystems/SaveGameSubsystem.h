// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SaveGameSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class AUTOBATTLER_API USaveGameSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	void SaveGame();
	void LoadGame();

};
