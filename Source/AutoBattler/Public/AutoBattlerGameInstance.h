// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AutoBattlerGameInstance.generated.h"

class UAutoBattlerGameManager;

/**
 * 
 */
UCLASS()
class AUTOBATTLER_API UAutoBattlerGameInstance : public UGameInstance
{
	GENERATED_BODY()

private:
	void Init();

	UPROPERTY()
	TObjectPtr<UAutoBattlerGameManager> GameManager;

	UFUNCTION(BlueprintCallable)
	UAutoBattlerGameManager* GetGameManager();
	
};
