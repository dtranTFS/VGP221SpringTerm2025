// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "NavigationSystem.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BTT_GetRandomPatrolLocation.generated.h"

/**
 * 
 */
UCLASS()
class VGP221SPRINGTERM2025_API UBTT_GetRandomPatrolLocation : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	FVector  RandomLocation;
	UNavigationSystemV1* NavArea;
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
