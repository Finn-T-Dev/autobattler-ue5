////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "Inventory/DropItemBehaviour.h"

#include <NsCore/ReflectionImplement.h>
#include <NsCore/Delegate.h>
#include <NsGui/BaseCommand.h>
#include <NsGui/DragDrop.h>
#include <NsGui/UIElementData.h>
#include <NsGui/PropertyMetadata.h>


using namespace Inventory;
using namespace Noesis;


////////////////////////////////////////////////////////////////////////////////////////////////////
bool DropItemBehaviour::GetIsDragOver() const
{
    return GetValue<bool>(IsDragOverProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DropItemBehaviour::SetIsDragOver(bool value)
{
    SetValue<bool>(IsDragOverProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
BaseCommand* DropItemBehaviour::GetDropCommand() const
{
    return GetValue<Noesis::Ptr<BaseCommand>>(DropCommandProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DropItemBehaviour::SetDropCommand(BaseCommand* value)
{
    SetValue<Noesis::Ptr<BaseCommand>>(DropCommandProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
Noesis::Ptr<Freezable> DropItemBehaviour::CreateInstanceCore() const
{
    return *new DropItemBehaviour();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DropItemBehaviour::OnAttached()
{
    ParentClass::OnAttached();

    FrameworkElement* element = GetAssociatedObject();
    element->SetAllowDrop(true);
    element->PreviewDragEnter() += MakeDelegate(this, &DropItemBehaviour::OnDragEnter);
    element->PreviewDragLeave() += MakeDelegate(this, &DropItemBehaviour::OnDragLeave);
    element->PreviewDrop() += MakeDelegate(this, &DropItemBehaviour::OnDrop);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DropItemBehaviour::OnDetaching()
{
    FrameworkElement* element = GetAssociatedObject();
    element->ClearLocalValue(UIElement::AllowDropProperty);
    element->PreviewDragEnter() -= MakeDelegate(this, &DropItemBehaviour::OnDragEnter);
    element->PreviewDragLeave() -= MakeDelegate(this, &DropItemBehaviour::OnDragLeave);
    element->PreviewDrop() -= MakeDelegate(this, &DropItemBehaviour::OnDrop);

    ParentClass::OnDetaching();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DropItemBehaviour::OnDragEnter(BaseComponent*, const DragEventArgs& e)
{
    SetIsDragOver(true);
    e.handled = true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DropItemBehaviour::OnDragLeave(BaseComponent*, const DragEventArgs& e)
{
    SetIsDragOver(false);
    e.handled = true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DropItemBehaviour::OnDrop(BaseComponent*, const DragEventArgs& e)
{
    SetIsDragOver(false);

    BaseComponent* item = GetAssociatedObject()->GetDataContext();
    BaseCommand* drop = GetDropCommand();
    if (item != 0 && drop != 0 && drop->CanExecute(item))
    {
        drop->Execute(item);
    }
    else
    {
        e.effects = DragDropEffects_None;
    }

    e.handled = true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION(DropItemBehaviour, "Inventory.DropItemBehaviour")
{
    UIElementData* data = NsMeta<UIElementData>(TypeOf<SelfClass>());
    data->RegisterProperty<bool>(IsDragOverProperty, "IsDragOver",
        PropertyMetadata::Create(false));
    data->RegisterProperty<Noesis::Ptr<BaseCommand>>(DropCommandProperty, "DropCommand",
        PropertyMetadata::Create(Noesis::Ptr<BaseCommand>()));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* DropItemBehaviour::IsDragOverProperty;
const Noesis::DependencyProperty* DropItemBehaviour::DropCommandProperty;