// Fill out your copyright notice in the Description page of Project Settings.


#include "Attributes/ItemBaseSet.h"

void UItemBaseSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& newValue) const
{
	Super::PreAttributeBaseChange(Attribute, newValue);

	ClampAttributeOnChange(Attribute, newValue);
}

void UItemBaseSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeBaseChange(Attribute, NewValue);

	ClampAttributeOnChange(Attribute, NewValue);
}

void UItemBaseSet::ClampAttributeOnChange(const FGameplayAttribute& Attribute, float& newValue) const
{

}
