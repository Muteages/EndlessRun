// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstacleBase.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AObstacleBase::AObstacleBase()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = SceneComponent;

	ObstacleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Obstacle"));
	ObstacleMesh->SetupAttachment(SceneComponent);
}

