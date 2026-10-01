// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CharacterBaseSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class AUTOBATTLER_API UCharacterBaseSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UCharacterBaseSet();
	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& newValue) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	UPROPERTY(BlueprintReadOnly, Category="Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UCharacterBaseSet, Health);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UCharacterBaseSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, Category="Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Shield;
	ATTRIBUTE_ACCESSORS(UCharacterBaseSet, Shield);

	UPROPERTY(BlueprintReadOnly, Category="Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Burn;
	ATTRIBUTE_ACCESSORS(UCharacterBaseSet, Burn);

	UPROPERTY(BlueprintReadOnly, Category="Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Regen;
	ATTRIBUTE_ACCESSORS(UCharacterBaseSet, Regen);

	UPROPERTY(BlueprintReadOnly, Category="Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Poison;
	ATTRIBUTE_ACCESSORS(UCharacterBaseSet, Poison);

protected:
	virtual void ClampAttributeOnChange(const FGameplayAttribute& Attribute, float& newValue) const;
	
	
};
