// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Items/BicepCurl.h"
#include "Actors/CharacterActor.h"
//#include "Engine/DataAsset.h"

ABicepCurl::ABicepCurl()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABicepCurl::BeginPlay()
{
	Super::BeginPlay();
}

void ABicepCurl::Activate(ACharacterActor* OwningCharacter, ACharacterActor* EnemyCharacter)
{
	if (BicepCurlAttributes == nullptr) return;

	//int32 DamageValue = BicepCurlAttributes->BaseDamage;
	//EnemyCharacter->TakeDamage(DamageValue);
}

void ABicepCurl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
