// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Collectibles/Collectibles.h"
#include "Kismet/GameplayStatics.h"
#include "HUD/FPSHud.h"
#include "Coin.generated.h"

/**
 * 
 */
UCLASS()
class VGP221SPRINGTERM2025_API ACoin : public ACollectibles
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ACoin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnCollect() override;

	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* CoinMeshComponent;

	UPROPERTY(EditAnywhere)
	float Points = 1;
	UPROPERTY(EditAnywhere)
	float RotationRate = 100;
	UPROPERTY(EditAnywhere)
	float OnCollectRotationRate = 1500;

	FTimerHandle DeadTimerHandle;
	void DeathTimerComplete();
};
