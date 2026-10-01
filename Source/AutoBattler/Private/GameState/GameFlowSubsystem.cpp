// Fill out your copyright notice in the Description page of Project Settings.


#include "GameState/GameFlowSubsystem.h"

void UGameFlowSubsystem::SetGameState(EGameFlowState NewState)
{
    if (bHasInitialised && CurrentState == NewState) return;
    bHasInitialised = true;

    CurrentState = NewState;
    UE_LOG(LogTemp, Warning, TEXT("UGameFlowSubsystem::SetGameState(%s)"), *UEnum::GetValueAsString(NewState));
    OnStateChanged.Broadcast(CurrentState);
}