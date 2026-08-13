// Fill out your copyright notice in the Description page of Project Settings.


#include "AutoBattlerGameManager.h"
#include "AutoBattlerGameInstance.h"

void UAutoBattlerGameManager::InitialiseGame(UCharacterData* SelectedCharacter)
{
	UE_LOG(LogTemp, Warning, TEXT("InitialiseGame with character: %s"), *SelectedCharacter->Name);
	//UAutoBattlerGameInstance* GameInstance = GetWorld()->GetGameInstance<UAutoBattlerGameInstance>();

}
