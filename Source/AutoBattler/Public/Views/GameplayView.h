// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NoesisInstance.h"
#include "GameplayView.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class AUTOBATTLER_API UGameplayView : public UNoesisInstance
{
	GENERATED_BODY()
private:
	void NativeConstruct() override;
public:
	UFUNCTION(BlueprintCallable)
	void SwitchTopPanelView(UObject* NewDataContext);
};
