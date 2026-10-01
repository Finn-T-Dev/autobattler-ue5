// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CharacterData.h"
#include "AutoBattlerGameManager.generated.h"


class UCharacterData;
/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class AUTOBATTLER_API UAutoBattlerGameManager : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void InitialiseGame(UCharacterData* SelectedCharacter);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<FName, TObjectPtr<UCharacterData>> CharacterDataMap;
};
