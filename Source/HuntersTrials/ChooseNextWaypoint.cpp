// Fill out your copyright notice in the Description page of Project Settings.

#include "HuntersTrials.h"
#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	int WaypointIndex = BlackboardComponent->GetValueAsInt(IndexKey.SelectedKeyName);

	UE_LOG(LogTemp, Warning, TEXT("Waypoint Index: %i"), WaypointIndex)

	return EBTNodeResult::Succeeded;
}
