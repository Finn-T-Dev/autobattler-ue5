// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/EncounterSubsystem.h"
#include "Subsystems/GameSessionSubsystem.h"
#include "Math/UnrealMathUtility.h"

const int8 ENCOUNTERS_PER_DAY = 8;

void UEncounterSubsystem::SetCurrentEncounterKey(EEncounterType NewKey)
{
	CurrentEncounterKey = NewKey;
}

EEncounterType UEncounterSubsystem::GetNextEncounterInSequence()
{
	// increment the index tracker
	auto GI = GetWorld()->GetGameInstance();
	if (GI != nullptr)
	{
		UGameSessionSubsystem* GSS = GI->GetSubsystem<UGameSessionSubsystem>();
		int32 CurrentExerciseIndex = GSS->GetCurrentExerciseIndex();
		int32 CurrentWorkoutIndex = GSS->GetCurrentWorkoutIndex();
		UE_LOGFMT(LogTemp, Warning, "Exercise and workout indices before getting next encounter: {x}, {y}",
			("x", CurrentExerciseIndex),
			("y", CurrentWorkoutIndex));
		GSS->SetCurrentExerciseIndex(CurrentExerciseIndex+1);
		UE_LOGFMT(LogTemp, Warning, "Exercise and workout indices after incrementing exercise index: {x}, {y}",
			("x", CurrentExerciseIndex),
			("y", CurrentWorkoutIndex));
		if (GSS->GetCurrentExerciseIndex() > ENCOUNTERS_PER_DAY)
		{
			WorkoutIndex++;
			EncounterIndex = 0;
		}

	}
	return Encounters[EncounterIndex];
}

void UEncounterSubsystem::SetEncounterTypesForWorkout(int WorkoutNumber)
{
	for (int i = 0; i < ENCOUNTERS_PER_DAY; i++)
	{
		EEncounterType EncounterToAdd;
		float RandomFloat = FMath::RandRange(0.0f, 1.0f);
		if (RandomFloat > 0.5)
		{
			EncounterToAdd = EEncounterType::MerchantEncounter;
		}
		else
		{
			EncounterToAdd = EEncounterType::GamblingEncounter;

		}
		UE_LOGFMT(LogTemp, Warning, "Added {Encounter} to Encounters", ("Encounter", UEnum::GetValueAsString(EncounterToAdd)));
		Encounters.Add(EncounterToAdd);
	}
}

TArray<EEncounterType> UEncounterSubsystem::GetEncounterTypesForWorkout(int WorkoutNumber)
{
	if (Workouts.IsValidIndex(WorkoutNumber))
	{
		return Workouts[WorkoutNumber].Encounters;
	}
	return TArray<EEncounterType>();
}

//TArray<EEncounterType> UEncounterSubsystem::GetEncounterOptionsForCurrentExercise(int WorkoutNumber, int ExerciseNumber)
//{
//
//}
