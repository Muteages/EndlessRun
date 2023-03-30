// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EndlessFloor.h"
#include "EndlessRunnerGameModeBase.generated.h"


/**
 * 
 */
UCLASS()
class ENDLESSRUNNER_API AEndlessRunnerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Config")
		int NumInitialFloors = 10;

	UPROPERTY(EditAnywhere, Category = "Config")
		TSubclassOf<AEndlessFloor> FloorTileClass;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		FTransform NextSpawnPoint;


	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		TArray<float> LaneList;

	UFUNCTION(BlueprintCallable)
		void CreateInitialFloors();

	UFUNCTION(BlueprintCallable)
		AEndlessFloor* AddFloors(const bool bSpawn);

protected:
	virtual void BeginPlay() override;
	
};
