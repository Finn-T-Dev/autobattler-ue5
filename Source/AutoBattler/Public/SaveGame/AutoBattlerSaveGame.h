// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "AutoBattlerSaveGame.generated.h"

class UCharacterData;
/**
 * 
 */
UCLASS()
class AUTOBATTLER_API UAutoBattlerSaveGame : public USaveGame
{
	GENERATED_BODY()
public:

	UPROPERTY(VisibleAnywhere, Category="SaveData")
	UCharacterData* CharacterData;
	
};
