// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/SaveGameSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "SaveGame/AutoBattlerSaveGame.h"
#include "Subsystems/GameSessionSubsystem.h"

void USaveGameSubsystem::SaveGame()
{
	FString SlotName = TEXT("Slot1");

	UAutoBattlerSaveGame* SaveGameInstance = Cast<UAutoBattlerSaveGame>(UGameplayStatics::CreateSaveGameObject(UAutoBattlerSaveGame::StaticClass()));

	if (SaveGameInstance)
	{
		// Gather current game data
		UGameInstance* GameInstance = GetGameInstance();
		UGameSessionSubsystem* GameSessionSubsystem = GameInstance->GetSubsystem<UGameSessionSubsystem>();
		SaveGameInstance->CharacterData = GameSessionSubsystem->SelectedCharacterDataObject;

		UGameplayStatics::SaveGameToSlot(SaveGameInstance, SlotName, 0);
	}
}

void USaveGameSubsystem::LoadGame()
{
	FString SlotName = TEXT("Slot1");
	if (UGameplayStatics::DoesSaveGameExist(SlotName, 0))
	{
		UAutoBattlerSaveGame* LoadedGame = Cast<UAutoBattlerSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));
		if (LoadedGame)
		{
			UGameInstance* GameInstance = GetGameInstance();
			UGameSessionSubsystem* GameSessionSubsystem = GameInstance->GetSubsystem<UGameSessionSubsystem>();
			GameSessionSubsystem->SelectedCharacterDataObject = LoadedGame->CharacterData;
		}

	}
}
