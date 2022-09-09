// Fill out your copyright notice in the Description page of Project Settings.



#include "NPC/AI/ChooseNextWaypoint.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Engine/TargetPoint.h"
#include "NPC/AI/PatrolRouteComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// BP 1 : Get The Partrol Route
	auto ControllerPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolRoute = ControllerPawn->FindComponentByClass<UPatrolRouteComponent>();
	if (!ensure(PatrolRoute)){return  EBTNodeResult::Failed;}

	// Warn about empty patrol routes
	auto Patrolpoints = PatrolRoute->GetPatrolPoint();
	if (Patrolpoints.Num() == 0)
	{
		UE_LOG(LogTemp,Warning,TEXT("A guard is missing Patrol points"));
		return  EBTNodeResult::Failed;
	}
	
	// BP 2 : Set next WayPoint 
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName,Patrolpoints[Index]);
	
	// BP 3 : Cycle the index
	auto NextIndex = (Index + 1) % Patrolpoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName,NextIndex);
	
	//UE_LOG(LogTemp,Warning,TEXT("Index %i"),Index);
	//UE_LOG(LogTemp,Warning,TEXT("AI In C++"));
	
	return EBTNodeResult::Succeeded;
}
