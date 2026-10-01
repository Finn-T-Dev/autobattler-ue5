// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataStructures.h"
#include "EncounterDefinition.generated.h"

/**
 * 
 */
UCLASS()
class AUTOBATTLER_API UEncounterDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Encounter")
	EEncounterType Type;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Encounter")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Encounter")
	FText Description;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Encounter")
	TObjectPtr<UTexture2D> Icon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Encounter")
	EItemTier Tier;
	
};
