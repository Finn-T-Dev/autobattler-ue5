// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DataStructures.h"
#include "EncounterSubsystem.generated.h"
/**
 * 
 */

USTRUCT(BlueprintType)
struct FEncounterList
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Encounter)
	TArray<EEncounterType> Encounters;
};

UCLASS()
class AUTOBATTLER_API UEncounterSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = Encounter)
	EEncounterType GetCurrentEncounterType() const { return CurrentEncounterKey; }

	UFUNCTION(BlueprintCallable, Category = Encounter)
	void SetCurrentEncounterKey(EEncounterType NewKey);

	UFUNCTION(BlueprintCallable, Category = Encounter)
	EEncounterType GetNextEncounterInSequence();

	UFUNCTION(BlueprintCallable, Category = Encounter)
	void SetEncounterTypesForWorkout(int WorkoutNumber);
	UFUNCTION(BlueprintCallable, Category = Encounter)
	TArray<EEncounterType> GetEncounterTypesForWorkout(int WorkoutNumber);

	//UFUNCTION(BlueprintCallable, Category = Encounter)
	//TArray<EEncounterType> GetEncounterOptionsForCurrentExercise(int WorkoutNumber, int ExerciseNumber);

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = true))
	EEncounterType CurrentEncounterKey;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = true))
	int8 EncounterIndex;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = true))
	int8 WorkoutIndex;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = true))
	TArray<EEncounterType> Encounters;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = true))
	TArray<FEncounterList> Workouts;
};
