////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "Inventory/DragItemBehaviour.h"

#include <NsCore/ReflectionImplement.h>
#include <NsCore/Delegate.h>
#include <NsGui/DragDrop.h>
#include <NsGui/UIElementData.h>
#include <NsGui/PropertyMetadata.h>
#include <NsGui/BaseCommand.h>
#include <NsDrawing/Point.h>


using namespace Inventory;
using namespace Noesis;


////////////////////////////////////////////////////////////////////////////////////////////////////
DragItemBehaviour::DragItemBehaviour() : _mouseClicked(false)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::Point& DragItemBehaviour::GetDragStartOffset() const
{
    return GetValue<Noesis::Point>(DragStartOffsetProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DragItemBehaviour::SetDragStartOffset(const Noesis::Point& offset)
{
    SetValue<Noesis::Point>(DragStartOffsetProperty, offset);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
BaseCommand* DragItemBehaviour::GetStartDragCommand() const
{
    return GetValue<Noesis::Ptr<BaseCommand>>(StartDragCommandProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DragItemBehaviour::SetStartDragCommand(BaseCommand* command)
{
    SetValue<Noesis::Ptr<BaseCommand>>(StartDragCommandProperty, command);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
BaseCommand* DragItemBehaviour::GetEndDragCommand() const
{
    return GetValue<Noesis::Ptr<BaseCommand>>(EndDragCommandProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DragItemBehaviour::SetEndDragCommand(BaseCommand* command)
{
    SetValue<Noesis::Ptr<BaseCommand>>(EndDragCommandProperty, command);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
Noesis::Ptr<Freezable> DragItemBehaviour::CreateInstanceCore() const
{
    return *new DragItemBehaviour();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DragItemBehaviour::OnAttached()
{
    ParentClass::OnAttached();

    FrameworkElement* element = GetAssociatedObject();
    element->GiveFeedback() += MakeDelegate(this, &DragItemBehaviour::OnGiveFeedback);
    element->PreviewMouseLeftButtonDown() += MakeDelegate(this, &DragItemBehaviour::OnMouseDown);
    element->PreviewMouseLeftButtonUp() += MakeDelegate(this, &DragItemBehaviour::OnMouseUp);
    element->PreviewMouseMove() += MakeDelegate(this, &DragItemBehaviour::OnMouseMove);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DragItemBehaviour::OnDetaching()
{
    FrameworkElement* element = GetAssociatedObject();
    element->GiveFeedback() -= MakeDelegate(this, &DragItemBehaviour::OnGiveFeedback);
    element->PreviewMouseLeftButtonDown() -= MakeDelegate(this, &DragItemBehaviour::OnMouseDown);
    element->PreviewMouseLeftButtonUp() -= MakeDelegate(this, &DragItemBehaviour::OnMouseUp);
    element->PreviewMouseMove() -= MakeDelegate(this, &DragItemBehaviour::OnMouseMove);

    ParentClass::OnAttached();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DragItemBehaviour::OnGiveFeedback(BaseComponent*, const GiveFeedbackEventArgs& e)
{
    e.useDefaultCursors = false;
    e.handled = true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DragItemBehaviour::OnMouseDown(BaseComponent*, const MouseButtonEventArgs&)
{
    _mouseClicked = true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DragItemBehaviour::OnMouseUp(BaseComponent*, const MouseButtonEventArgs&)
{
    _mouseClicked = false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DragItemBehaviour::OnMouseMove(BaseComponent*, const MouseEventArgs& e)
{
    if (!_mouseClicked)
    {
        return;
    }

    _mouseClicked = false;

    FrameworkElement* element = GetAssociatedObject();
    BaseComponent* item = element->GetDataContext();
    if (item != 0)
    {
        BaseCommand* startDrag = GetStartDragCommand();
        if (startDrag != 0 && startDrag->CanExecute(item))
        {
            SetDragStartOffset(element->PointFromScreen(e.position));

            startDrag->Execute(item);

            DragDrop::DoDragDrop(element, item, DragDropEffects_Move, [this](DependencyObject*,
                BaseComponent*, UIElement*, const Noesis::Point&, uint32_t effects)
                {
                    Noesis::Ptr<BaseComponent> dragSuccess = Boxing::Box<bool>(effects != DragDropEffects_None);
                    BaseCommand* endDrag = GetEndDragCommand();
                    if (endDrag != 0 && endDrag->CanExecute(dragSuccess))
                    {
                        endDrag->Execute(dragSuccess);
                    }
                });
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION(DragItemBehaviour, "Inventory.DragItemBehaviour")
{
    UIElementData* data = NsMeta<UIElementData>(TypeOf<SelfClass>());
    data->RegisterProperty<Noesis::Point>(DragStartOffsetProperty, "DragStartOffset",
        PropertyMetadata::Create(Noesis::Point(0.0f, 0.0f)));
    data->RegisterProperty<Noesis::Ptr<BaseCommand>>(StartDragCommandProperty, "StartDragCommand",
        PropertyMetadata::Create(Noesis::Ptr<BaseCommand>()));
    data->RegisterProperty<Noesis::Ptr<BaseCommand>>(EndDragCommandProperty, "EndDragCommand",
        PropertyMetadata::Create(Noesis::Ptr<BaseCommand>()));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* DragItemBehaviour::DragStartOffsetProperty;
const Noesis::DependencyProperty* DragItemBehaviour::StartDragCommandProperty;
const Noesis::DependencyProperty* DragItemBehaviour::EndDragCommandProperty;