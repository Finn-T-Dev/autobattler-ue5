// Copyright Epic Games, Inc. All Rights Reserved.

#include "AutoBattler.h"
#include "Modules/ModuleManager.h"

#include "Noesis/DragItemBehavior.h"
#include "Noesis/DropItemBehavior.h"
#include "Noesis/InventorySlot.h"

class FAutoBattlerModule : public FDefaultGameModuleImpl
{
public:
	virtual void StartupModule() override
	{
		Noesis::RegisterComponent<Inventory::DragItemBehavior>();
		Noesis::RegisterComponent<Inventory::InventorySlot>();
		Noesis::RegisterComponent<Inventory::DropItemBehavior>();
	}

	virtual void ShutdownModule() override
	{
		Noesis::UnregisterComponent<Inventory::DragItemBehavior>();
		Noesis::UnregisterComponent<Inventory::InventorySlot>();
		Noesis::UnregisterComponent<Inventory::DropItemBehavior>();
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE(FAutoBattlerModule, AutoBattler, "AutoBattler");
