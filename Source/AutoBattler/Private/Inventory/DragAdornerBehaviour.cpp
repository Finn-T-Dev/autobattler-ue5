////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "Inventory/DragAdornerBehaviour.h"

#include <NsCore/ReflectionImplement.h>
#include <NsCore/Delegate.h>
#include <NsGui/DragDrop.h>
#include <NsGui/UIElementData.h>
#include <NsGui/PropertyMetadata.h>
#include <NsDrawing/Point.h>


using namespace Inventory;
using namespace Noesis;


////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::Point& DragAdornerBehaviour::GetDragStartOffset() const
{
    return GetValue<Noesis::Point>(DragStartOffsetProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DragAdornerBehaviour::SetDragStartOffset(const Noesis::Point& offset)
{
    SetValue<Noesis::Point>(DragStartOffsetProperty, offset);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float DragAdornerBehaviour::GetDraggedItemX() const
{
    return GetValue<float>(DraggedItemXProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DragAdornerBehaviour::SetDraggedItemX(float x)
{
    SetReadOnlyProperty<float>(DraggedItemXProperty, x);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float DragAdornerBehaviour::GetDraggedItemY() const
{
    return GetValue<float>(DraggedItemYProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DragAdornerBehaviour::SetDraggedItemY(float y)
{
    SetReadOnlyProperty<float>(DraggedItemYProperty, y);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
Noesis::Ptr<Freezable> DragAdornerBehaviour::CreateInstanceCore() const
{
    return *new DragAdornerBehaviour();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DragAdornerBehaviour::OnAttached()
{
    ParentClass::OnAttached();

    FrameworkElement* element = GetAssociatedObject();
    element->SetAllowDrop(true);
    element->DragOver() += MakeDelegate(this, &DragAdornerBehaviour::OnDragOver);
    element->Drop() += MakeDelegate(this, &DragAdornerBehaviour::OnDrop);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DragAdornerBehaviour::OnDetaching()
{
    FrameworkElement* element = GetAssociatedObject();
    element->ClearLocalValue(UIElement::AllowDropProperty);
    element->DragOver() -= MakeDelegate(this, &DragAdornerBehaviour::OnDragOver);
    element->Drop() -= MakeDelegate(this, &DragAdornerBehaviour::OnDrop);

    ParentClass::OnDetaching();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DragAdornerBehaviour::OnDragOver(BaseComponent*, const DragEventArgs& e)
{
    Noesis::Point position = e.GetPosition(GetAssociatedObject());
    Noesis::Point offset = GetDragStartOffset();
    SetDraggedItemX(position.x - offset.x);
    SetDraggedItemY(position.y - offset.y);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DragAdornerBehaviour::OnDrop(BaseComponent*, const DragEventArgs& e)
{
    e.effects = DragDropEffects_None;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION(DragAdornerBehaviour, "Inventory.DragAdornerBehaviour")
{
    UIElementData* data = NsMeta<UIElementData>(TypeOf<SelfClass>());
    data->RegisterProperty<Noesis::Point>(DragStartOffsetProperty, "DragStartOffset",
        PropertyMetadata::Create(Noesis::Point(0.0f, 0.0f)));
    data->RegisterPropertyRO<float>(DraggedItemXProperty, "DraggedItemX",
        PropertyMetadata::Create(0.0f));
    data->RegisterPropertyRO<float>(DraggedItemYProperty, "DraggedItemY",
        PropertyMetadata::Create(0.0f));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* DragAdornerBehaviour::DragStartOffsetProperty;
const Noesis::DependencyProperty* DragAdornerBehaviour::DraggedItemXProperty;
const Noesis::DependencyProperty* DragAdornerBehaviour::DraggedItemYProperty;