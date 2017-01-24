// Fill out your copyright notice in the Description page of Project Settings.

#include "HuntersTrials.h"
#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	APawn* ControlledPawn = OwnerComp.GetAIOwner()->GetControlledPawn();

	// Get patrol points of the patrolling character.
	UPatrolRoute* PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();
	if (!ensure(PatrolRoute))
	{
		return EBTNodeResult::Failed;
	}
	TArray<AActor*> PatrolPoints = PatrolRoute->GetPatrolPoints();

	// Sets the next waypoint and cycles the index.
	if (PatrolPoints.Num() != 0)
	{
		int WaypointIndex = BlackboardComponent->GetValueAsInt(IndexKey.SelectedKeyName);
		BlackboardComponent->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[WaypointIndex]);

		int NextIndex = (WaypointIndex + 1) % PatrolPoints.Num();
		BlackboardComponent->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
	}
	else
	{
		return EBTNodeResult::Failed;
	}

	return EBTNodeResult::Succeeded;
}
