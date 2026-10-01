// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataStructures.h"
//#include "Abilities/GameplayAbility.h"
#include "ItemDataAsset.generated.h"

/**
 * 
 */
class UGameplayAbility;

USTRUCT(BlueprintType)
struct FItemIdentity
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FName ItemID;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FText Name;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FString Description;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UTexture2D* Icon;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EItemSize Size;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EPlayerCharacter AssociatedCharacter;
};

USTRUCT(BlueprintType)
struct FItemClassification
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TArray<EItemTag> Tags;

    bool CanUpgrade;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EItemTier UpgradeTier;

    bool IsEnchanted;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EItemEnhancement Enchantment;
};

USTRUCT(BlueprintType)
struct FItemStat
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    float Cooldown;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int Damage;
};

UCLASS()
class AUTOBATTLER_API UItemDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Identity")
    FItemIdentity Identity;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Classification")
    FItemClassification Classification;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
    FItemStat Stats;
    //UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Abilities")
    //TArray<TSubclassOf<UGameplayAbility>> AbilitiesToGrant;

    virtual FPrimaryAssetId GetPrimaryAssetId() const override
    {
        return FPrimaryAssetId("ItemData", Identity.ItemID);
    }
	
};
