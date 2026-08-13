// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "../CoreMinimal.h"

#include "../AutoBattler.h"

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
enum class EItemTags : uint8 {
	Freeweight,
	Supplement,
	Cardio,
	Machine,
};
