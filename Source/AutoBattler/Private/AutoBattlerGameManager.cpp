// Fill out your copyright notice in the Description page of Project Settings.


#include "AutoBattlerGameManager.h"
#include "AutoBattlerGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/AssetManager.h"
#include "GameState/GameFlowSubsystem.h"

void UAutoBattlerGameManager::InitialiseGame(UCharacterData* SelectedCharacter)
{
	//UE_LOG(LogTemp, Warning, TEXT("InitialiseGame with character: %s"), *SelectedCharacter.Identity.Name);
	//UAutoBattlerGameInstance* GameInstance = GetWorld()->GetGameInstance<UAutoBattlerGameInstance>();

	//FName GameplayLevelName = TEXT("GameplayLevel");
	//UWorld* World = GetWorld();
	//if (World)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Opening main gameplay level with name %s"), *GameplayLevelName.ToString());
	//	UGameplayStatics::OpenLevel(World, GameplayLevelName, true);
	//}

	UAssetManager& AssetManager = UAssetManager::Get();
	const FPrimaryAssetId CharacterAssetId("CharacterData", SelectedCharacter->CharacterId);

	AssetManager.LoadPrimaryAsset(
		CharacterAssetId,
		TArray<FName>(),
		FStreamableDelegate::CreateLambda([this, CharacterAssetId]
			{
				UObject* LoadedAsset = UAssetManager::Get().GetPrimaryAssetObject(CharacterAssetId);
				if (const UCharacterData* CharacterData = Cast<UCharacterData>(LoadedAsset))
				{
					const FString& CharacterName = CharacterData->Identity.Name;
					UE_LOG(LogTemp, Warning, TEXT("CharacterData->Name = %s"), *CharacterName);
				}
			}));

	if (UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(GetWorld()))
	{
		UGameFlowSubsystem* GameFlowSubsystem = GameInstance->GetSubsystem<UGameFlowSubsystem>();

		if (GameFlowSubsystem)
		{
			GameFlowSubsystem->SetGameState(EGameFlowState::GameplayState);
		}
	}

}
