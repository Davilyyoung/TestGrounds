// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC/AI/PatrolRouteComponent.h"

TArray<AActor*> UPatrolRouteComponent::GetPatrolPoint() const
{
	return PatrolPoints;
}
