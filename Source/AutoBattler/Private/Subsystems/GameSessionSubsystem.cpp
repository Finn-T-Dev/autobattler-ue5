// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/GameSessionSubsystem.h"

const int32 EXERCISES_PER_WORKOUT = 8;

void UGameSessionSubsystem::SetPlayerCharacter(UCharacterData* CharacterObject)
{
	SelectedCharacterDataObject = CharacterObject;
}

void UGameSessionSubsystem::SetCurrentWorkoutIndex(int32 NewValue)
{
	CurrentWorkoutIndex = NewValue;
}

void UGameSessionSubsystem::SetCurrentExerciseIndex(int32 NewValue)
{
	UE_LOGFMT(LogTemp, Warning, "Exercise index before new value set: {x}", ("x", CurrentExerciseIndex));
	if (NewValue == (CurrentExerciseIndex + 1) && NewValue >= EXERCISES_PER_WORKOUT) 
	{
		CurrentExerciseIndex = 0;
		SetCurrentWorkoutIndex(CurrentWorkoutIndex + 1);
		// TODO broadcast event "on workout changed" for new workout
	}
	else 
	{
		CurrentExerciseIndex = NewValue;
	}
	UE_LOGFMT(LogTemp, Warning, "New exercise index: {x}", ("x", CurrentExerciseIndex));
}
