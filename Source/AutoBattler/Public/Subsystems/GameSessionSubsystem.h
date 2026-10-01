// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameSessionSubsystem.generated.h"

class UCharacterData;

/**
 * 
 */
UCLASS()
class AUTOBATTLER_API UGameSessionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SelectedCharacterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCharacterData* SelectedCharacterDataObject;

	UFUNCTION(BlueprintCallable)
	void SetPlayerCharacter(UCharacterData* CharacterObject);

	UFUNCTION(BlueprintCallable)
	UCharacterData* GetPlayerCharacter() const
	{
		return SelectedCharacterDataObject;
	}

	UFUNCTION(BlueprintCallable)
	int32 GetCurrentExerciseIndex() const { return CurrentExerciseIndex;}
	UFUNCTION(BlueprintCallable)
	int32 GetCurrentWorkoutIndex() const { return CurrentWorkoutIndex;}

	UFUNCTION(BlueprintCallable)
	void SetCurrentWorkoutIndex(int32 NewValue);

	UFUNCTION(BlueprintCallable)
	void SetCurrentExerciseIndex(int32 NewValue);

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	int32 CurrentExerciseIndex = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	int32 CurrentWorkoutIndex = 0;

	// TODO need a way of storing progress
	
	
};
