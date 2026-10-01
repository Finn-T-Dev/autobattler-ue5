#include "ViewModels/CharacterViewModel.h"
#include "CharacterData.h"
#include "ViewModels/InventoryViewModel.h"

void UCharacterViewModel::Initialize(UCharacterData* InCharacterData)
{
    if (!InCharacterData)
    {
        return;
    }

    CharacterData = InCharacterData;

    UE_MVVM_SET_PROPERTY_VALUE(CharacterName, InCharacterData->Identity.Name);
    UE_MVVM_SET_PROPERTY_VALUE(Income, InCharacterData->Stats.Income);
    UE_MVVM_SET_PROPERTY_VALUE(Gold, InCharacterData->Stats.Gold);
    UE_MVVM_SET_PROPERTY_VALUE(Portrait, InCharacterData->Identity.Image);
    UE_MVVM_SET_PROPERTY_VALUE(CurrentHealth, InCharacterData->Stats.StartingHealth);
    UE_MVVM_SET_PROPERTY_VALUE(MaxHealth, InCharacterData->Stats.StartingHealth);

    if (!Inventory)
    {
        Inventory = NewObject<UInventoryViewModel>(this);
    }
    UE_MVVM_SET_PROPERTY_VALUE(Inventory, Inventory);
}