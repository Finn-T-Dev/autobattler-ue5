// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/ItemActor.h"
#include "BicepCurl.generated.h"

class ACharacterActor;
class UPrimaryDataAsset;

/**
 * 
 */
UCLASS()
class AUTOBATTLER_API ABicepCurl : public AItemActor
{
	GENERATED_BODY()
public:
	ABicepCurl();

protected:
	virtual void BeginPlay() override;

	void Activate(ACharacterActor* OwningCharacter, ACharacterActor* EnemyCharacter) override;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Attributes")
	TObjectPtr<UPrimaryDataAsset> BicepCurlAttributes;
	
};
