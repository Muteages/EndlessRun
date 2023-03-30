// Copyright Epic Games, Inc. All Rights Reserved.


#include "EndlessRunnerGameModeBase.h"

void AEndlessRunnerGameModeBase::CreateInitialFloors()
{
	auto Tile = AddFloors(false);

	if (Tile)
	{
		LaneList.Add(Tile->LeftLane->GetComponentLocation().Y);
		LaneList.Add(Tile->CenterLane->GetComponentLocation().Y);
		LaneList.Add(Tile->RightLane->GetComponentLocation().Y);
	}



	for (int i = 0; i < NumInitialFloors; i++)
	{
		AddFloors(true);
	}
}

AEndlessFloor* AEndlessRunnerGameModeBase::AddFloors(const bool bSpawn)
{
	auto World = GetWorld();
	if (World)
	{
		AEndlessFloor* Tile = World->SpawnActor<AEndlessFloor>(FloorTileClass, NextSpawnPoint);

		if (Tile)
		{
			if (bSpawn)
			{
				
			}
			NextSpawnPoint = Tile->GetAttachPointTransform();
		}
		return Tile;
	}

	return nullptr;
}

void AEndlessRunnerGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	CreateInitialFloors();
}
