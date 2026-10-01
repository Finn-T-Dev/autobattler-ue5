// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterActor.generated.h"

class UStaticMeshComponent;
class UPrimaryDataAsset;

UCLASS()
class AUTOBATTLER_API ACharacterActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACharacterActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Static Mesh", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> StaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character State")
	int CurrentHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character State")
	int MaxHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character State")
	int Shield;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character State")
	int Gold;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character State")
	TObjectPtr<UPrimaryDataAsset> CharacterDataAsset;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character State")
	int BoardSlotsInUse;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character State")
	int BoardSlotsAvailable;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character State")
	int XpEarned;

	int PlayerLevel;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual float SimpleTakeDamage(int DamageAmount);
	void HealDamage(int Amount);
	void GainShield(int Amount);
	void IncreaseMaxHealth(int Amount);
	void ApplyStatusEffect(...);

};
