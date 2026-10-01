// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/CharacterActor.h"

// Sets default values
ACharacterActor::ACharacterActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacterActor::BeginPlay()
{
	Super::BeginPlay();
	
}

float ACharacterActor::SimpleTakeDamage(int DamageAmount)
{
	CurrentHealth -= DamageAmount;
	return float(CurrentHealth);
}

void ACharacterActor::HealDamage(int Amount)
{
	CurrentHealth = FMath::Clamp(CurrentHealth, 0, MaxHealth);
}

void ACharacterActor::GainShield(int Amount)
{
	Shield += Amount;
}

void ACharacterActor::IncreaseMaxHealth(int Amount)
{
	CurrentHealth += Amount;
	HealDamage(Amount);
}

void ACharacterActor::ApplyStatusEffect(...)
{
	// TBD
}

// Called every frame
void ACharacterActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

