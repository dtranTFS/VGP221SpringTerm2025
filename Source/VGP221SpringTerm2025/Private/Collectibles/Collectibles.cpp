// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectibles/Collectibles.h"

// Sets default values
ACollectibles::ACollectibles()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!CollisionComponent) {
		CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
		CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ACollectibles::BeginOverlap);
		CollisionComponent->InitSphereRadius(50.0f);
		RootComponent = CollisionComponent;
	}
}

// Called when the game starts or when spawned
void ACollectibles::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollectibles::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACollectibles::BeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OnCollect();
}

void ACollectibles::OnCollect()
{
	UE_LOG(LogTemp, Warning, TEXT("Collectible OnCollect Called"));
}

