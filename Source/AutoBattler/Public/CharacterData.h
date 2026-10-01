// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataStructures.h"
#include "CharacterData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FCharacterIdentity
{
	GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FString Name;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTexture2D> Image;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PrimaryColour;

	// redundant?
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPlayerCharacter Enum;
};

USTRUCT(BlueprintType)
struct FCharacterStats
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 StartingHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 Income;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 Gold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 XP;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 PlayerLevel;


};

UCLASS()
class UCharacterData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FName CharacterId;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FCharacterIdentity Identity;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("CharacterData", CharacterId);
	}

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FCharacterStats Stats;

};
