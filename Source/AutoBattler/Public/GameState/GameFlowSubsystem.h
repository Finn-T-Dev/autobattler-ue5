// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DataStructures.h"
#include "GameFlowSubsystem.generated.h"

//enum class EPlayerCharacter;

UENUM(BlueprintType)
enum class EGameFlowState : uint8 {
	MainMenuState,
	CharacterSelectState,
	SettingsState,
	GameplayState
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameFlowStateChanged, EGameFlowState, NewState);

/**
 * 
 */
UCLASS()
class AUTOBATTLER_API UGameFlowSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetGameState(EGameFlowState NewState);	// add StateData as a function arg at some point when persistent data is a thing

	UPROPERTY(BlueprintAssignable)
	FOnGameFlowStateChanged OnStateChanged;

	EGameFlowState GetGameState() const { return CurrentState; }

	UPROPERTY()
	EPlayerCharacter CharacterEnum;
	
private:
	EGameFlowState CurrentState = EGameFlowState::MainMenuState;
	bool bHasInitialised = false;

};
