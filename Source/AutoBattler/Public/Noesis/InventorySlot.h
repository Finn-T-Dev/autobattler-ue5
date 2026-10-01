#pragma once
#include <NsCore/Noesis.h>
#include <NsCore/BaseComponent.h>

class UItemDataAsset;

namespace Inventory 
{
	class InventorySlot final : public Noesis::BaseComponent
	{
	public:
		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ItemData")
		UItemDataAsset* Item;

		void StartDragging();
		void EndDragging();
		InventorySlot* GetItem() { return this; };
		UItemDataAsset* GetItemData() { return this->Item; }
	private:
		NS_DECLARE_REFLECTION(InventorySlot, BaseComponent)
	};
}
