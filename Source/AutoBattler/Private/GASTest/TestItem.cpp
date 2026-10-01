// Fill out your copyright notice in the Description page of Project Settings.


#include "GASTest/TestItem.h"

// Sets default values
ATestItem::ATestItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestItem::BeginPlay()
{
	Super::BeginPlay();
	
}

UAbilitySystemComponent* ATestItem::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

// Called every frame
void ATestItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

