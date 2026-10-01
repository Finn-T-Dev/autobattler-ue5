// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/ItemActor.h"
//#include "Actors/CharacterActor.h"

// Sets default values
AItemActor::AItemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	StaticMeshComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AItemActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItemActor::Activate(ACharacterActor* OwningCharacter, ACharacterActor* EnemyCharacter)
{

}

// Called every frame
void AItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

