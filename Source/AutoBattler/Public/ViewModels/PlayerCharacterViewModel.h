// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ViewModels/CharacterViewModel.h"
#include "PlayerCharacterViewModel.generated.h"

/**
 * 
 */

UCLASS()
class AUTOBATTLER_API UPlayerCharacterViewModel : public UCharacterViewModel
{
	GENERATED_BODY()
private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, meta = (AllowPrivateAccess))
	int32 PlayerLevel = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, meta = (AllowPrivateAccess))
	int32 XP = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, meta = (AllowPrivateAccess))
	int32 XPPerLevel = 8; // TODO put this in a universal config file?? along with starting xp and starting player level

};
