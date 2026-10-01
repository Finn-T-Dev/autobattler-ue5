// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "GameplayViewModel.generated.h"

/**
 * 
 */
class UGameSessionData;
class UTopPanelViewModel;
class UPlayerCharacterViewModel;
class UGameStateViewModel;

UCLASS()
class AUTOBATTLER_API UGameplayViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	void Initialize(UGameSessionData* GameSessionData);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	TObjectPtr<UPlayerCharacterViewModel> PlayerCharacterViewModel = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	TObjectPtr<UTopPanelViewModel> TopPanelViewModel = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	TObjectPtr<UGameStateViewModel> GameStateViewModel = nullptr;
	
};
