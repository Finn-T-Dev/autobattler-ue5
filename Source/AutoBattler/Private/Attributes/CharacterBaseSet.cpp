// Fill out your copyright notice in the Description page of Project Settings.


#include "Attributes/CharacterBaseSet.h"

UCharacterBaseSet::UCharacterBaseSet() : Health(300.0f), MaxHealth(300.0f), Shield(0.0f), Burn(0.0f), Regen(0.0f), Poison(0.0f)
{

}

void UCharacterBaseSet::ClampAttributeOnChange(const FGameplayAttribute& Attribute, float& newValue) const
{

}

void UCharacterBaseSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& newValue) const
{
	Super::PreAttributeBaseChange(Attribute, newValue);

	ClampAttributeOnChange(Attribute, newValue);
}

void UCharacterBaseSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeBaseChange(Attribute, NewValue);

	ClampAttributeOnChange(Attribute, NewValue);
}
