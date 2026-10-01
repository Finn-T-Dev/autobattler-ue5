// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "CharacterViewModel.generated.h"

/**
 * 
 */

class UCharacterData;
class UInventoryViewModel;

UCLASS()
class AUTOBATTLER_API UCharacterViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()
public:
	void Initialize(UCharacterData* InCharacterData);
private:
	UPROPERTY()
	TObjectPtr<UCharacterData> CharacterData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, meta = (AllowPrivateAccess))
	FString CharacterName = "PLACEHOLDERNAME";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, meta = (AllowPrivateAccess))
	int32 Income = 6767;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, meta = (AllowPrivateAccess))
	int32 Gold = 6767;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, meta = (AllowPrivateAccess))
	int32 CurrentHealth = 6767;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, meta = (AllowPrivateAccess))
	int32 MaxHealth = 6767;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, meta = (AllowPrivateAccess))
    UTexture2D* Portrait = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, meta = (AllowPrivateAccess))
	TObjectPtr<UInventoryViewModel> Inventory = nullptr;
};
