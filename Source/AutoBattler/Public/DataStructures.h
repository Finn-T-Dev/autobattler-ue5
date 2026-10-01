// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../AutoBattler.h"
#include "DataStructures.generated.h"

/**
 * 
 */
//class AUTOBATTLER_API DataStructures
//{
//public:
//	DataStructures();
//	~DataStructures();
//};

UENUM(BlueprintType)
enum class EPlayerCharacter : uint8 {
	None,
	GymBro,
	ScienceBasedLifter,
	Strongman
};

UENUM(BlueprintType)
enum class EItemTag : uint8 {
	Freeweight,
	Supplement,
	Cardio,
	Machine,
};

UENUM(BlueprintType)
enum class EItemSize : uint8 {
	Small,
	Medium,
	Large
};

UENUM(BlueprintType)
enum class EItemTier : uint8 {
	Bronze,
	Silver,
	Gold,
	Diamond,
	Legendary
};

UENUM(BlueprintType)
enum class EItemEnhancement : uint8 {
	None,
	Laced,
	Heavy,
	Assisted,
	Raw,
};

//--------------------------------ENCOUNTERS-------------------------------//
UENUM(BlueprintType)
enum class EEncounterType : uint8 {
	// This enum needs to correspond to the ViewModel types for the TopPanelViewModel
	EncounterSelect,
	CombatEncounter,
	FreeItemEncounter,
	GamblingEncounter,
	MerchantEncounter,
	SpecialEncounter,
};

UENUM(BlueprintType)
enum class EEncounterTier : uint8 {
	// This enum needs to correspond to the ViewModel types for the TopPanelViewModel
	Bronze,
	Silver, 
	Gold,
	Diamond,
	Legendary
};

USTRUCT(BlueprintType)
struct FEncounterData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EEncounterType EncounterType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int32, float> EncounterProbabilityMap;
};

//--------------------------------GAMESTATE/STRUCTURE-------------------------------//
