#include "Noesis/InventorySlot.h"
#include <NsCore/ReflectionImplement.h>

using namespace Inventory;

void InventorySlot::StartDragging()
{
	UE_LOG(LogTemp, Warning, TEXT("InventorySlot->StartDragging"));
}

void InventorySlot::EndDragging()
{
	UE_LOG(LogTemp, Warning, TEXT("InventorySlot->EndDragging"));
}

NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION(InventorySlot, "Inventory.InventorySlot")
{
}