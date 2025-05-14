// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Kismet/GameplayStatics.h"
#include "Character/FPSCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "BTT_Attack.generated.h"

/**
 * 
 */
UCLASS()
class VGP221SPRINGTERM2025_API UBTT_Attack : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
