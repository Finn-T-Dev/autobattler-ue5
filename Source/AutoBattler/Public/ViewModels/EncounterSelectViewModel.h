// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "TopPanelViewModel.h"
#include "EncounterSelectViewModel.generated.h"

class UEncounterDefinition;
/**
 * 
 */
UCLASS()
class AUTOBATTLER_API UEncounterSelectViewModel : public UTopPanelViewModel
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, meta = (AllowPrivateAccess))
	TArray<TObjectPtr<UEncounterDefinition>> Encounters;
};
