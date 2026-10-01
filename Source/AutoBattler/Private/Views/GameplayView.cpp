// Fill out your copyright notice in the Description page of Project Settings.


#include "Views/GameplayView.h"
#include "NoesisTypeClass.h"

void UGameplayView::NativeConstruct()
{
	Super::NativeConstruct();
	UE_LOG(LogTemp, Warning, TEXT("Called NativeConstruct on GameplayView"));
}

void UGameplayView::SwitchTopPanelView(UObject* NewDataContext)
{
	Noesis::FrameworkElement* Root = XamlView->GetContent();
	if (Root)
	{
		Noesis::FrameworkElement* TopPanelGrid = Root->FindName<Noesis::FrameworkElement>("TopPanel_Grid");
		if (TopPanelGrid)
		{
			DataContext = Noesis::Ptr<Noesis::BaseComponent>(NoesisCreateComponentForUObject(NewDataContext));
			TopPanelGrid->SetDataContext(DataContext);
			FString DataContextString = DataContext->ToString().Str();
			UE_LOG(LogTemp, Warning, TEXT("Set DataContext on %hs to: %s"), TopPanelGrid->GetName(), *DataContextString);
		}
	}
}