// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/BTT_Attack.h"

EBTNodeResult::Type UBTT_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Method 1: Using Gameplay static and calling a function
	//AFPSCharacter* player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	//player->Damage(1.0f);

	// Method 2: Using blackboard value
	//AFPSCharacter* player = Cast<AFPSCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName("PlayerTarget")));
	//player->Damage(1.0f);

	// Method 3: Built in damage system
	AFPSCharacter* player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	UGameplayStatics::ApplyDamage(player, 1.0f, OwnerComp.GetAIOwner(), OwnerComp.GetAIOwner()->GetPawn(), UDamageType::StaticClass());

	return EBTNodeResult::Succeeded;
}
