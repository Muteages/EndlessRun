// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObstacleBase.generated.h"

UCLASS()
class ENDLESSRUNNER_API AObstacleBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacleBase();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Obstacle")
		TObjectPtr<USceneComponent> SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Obstacle")
		TObjectPtr<UStaticMeshComponent> ObstacleMesh;


};
