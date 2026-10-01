// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "TopPanelViewModel.generated.h"

/**
 * 
 */
UCLASS()
class AUTOBATTLER_API UTopPanelViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category=ViewModel)
	void RefreshFromEncounterKey(FName EncounterKey)
	{
		UE_MVVM_SET_PROPERTY_VALUE(EncounterDisplayName, ResolveDisplayNameFromKey(EncounterKey));
	}

	UPROPERTY(FieldNotify, BlueprintReadOnly, Category=ViewModel)
	FText EncounterDisplayName;

private:
	UFUNCTION(BlueprintCallable, meta=(AllowPrivateAccess = true))
	FText ResolveDisplayNameFromKey(FName Key) const;
};
