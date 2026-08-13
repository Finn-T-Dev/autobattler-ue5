// Fill out your copyright notice in the Description page of Project Settings.


#include "AutoBattlerGameInstance.h"
#include "AutoBattlerGameManager.h"

void UAutoBattlerGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Warning, TEXT("Custom GameInstance Initialised"));

	GameManager = NewObject<UAutoBattlerGameManager>(this);
	UE_LOG(LogTemp, Warning, TEXT("Custom GameManager Initialised"));
}

UAutoBattlerGameManager* UAutoBattlerGameInstance::GetGameManager()
{
	return GameManager;
}
