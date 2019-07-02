// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!HasAuthority())
	{
		return;
	}
	auto Location = GetActorLocation();
	Location += FVector(Speed, 0.0f, 0.0f);
	SetActorLocation(Location);
}