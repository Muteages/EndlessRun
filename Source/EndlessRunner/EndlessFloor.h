// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ObstacleBase.h"
#include "EndlessFloor.generated.h"

class AEndlessRunnerGameModeBase;

UCLASS()
class ENDLESSRUNNER_API AEndlessFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEndlessFloor();

	FORCEINLINE const FTransform GetAttachPointTransform() const
	{
		return AttachPoint->GetComponentTransform();
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleInstanceOnly)
		AEndlessRunnerGameModeBase* GameMode;

	UPROPERTY()
		FTimerHandle DestoryHandle;

	UFUNCTION()
		void OnTriggerBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void DestoryOldFloor();

	UFUNCTION()
		void ChooseLaneToSpawnObstacle(UArrowComponent* Lane);


public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Floor")
		class USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Floor")
		class UStaticMeshComponent* FloorMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Floor")
		class UArrowComponent* AttachPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Floor")
		class UArrowComponent* CenterLane;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Floor")
		class UArrowComponent* RightLane;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Floor")
		class UArrowComponent* LeftLane;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Floor")
		class UBoxComponent* FloorTrigger;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config")
		TSubclassOf<AObstacleBase> ObstacleClass;

	UFUNCTION(BlueprintCallable)
		void SpawnObstacle();


};
