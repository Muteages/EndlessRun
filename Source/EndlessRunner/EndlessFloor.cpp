// Fill out your copyright notice in the Description page of Project Settings.


#include "EndlessFloor.h"
#include "Kismet/GameplayStatics.h"
#include "EndlessRunnerGameModeBase.h"
#include "RunCharacter.h"

// Sets default values
AEndlessFloor::AEndlessFloor()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = SceneComponent;

	FloorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor"));
	FloorMesh->SetupAttachment(SceneComponent);

	AttachPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("Attach Point"));
	AttachPoint->SetupAttachment(SceneComponent);

	CenterLane = CreateDefaultSubobject<UArrowComponent>(TEXT("Center Lane"));
	CenterLane->SetupAttachment(SceneComponent);

	RightLane = CreateDefaultSubobject<UArrowComponent>(TEXT("Right Lane"));
	RightLane->SetupAttachment(SceneComponent);

	LeftLane = CreateDefaultSubobject<UArrowComponent>(TEXT("Left Lane"));
	LeftLane->SetupAttachment(SceneComponent);

	FloorTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Floor Trigger Box"));
	FloorTrigger->SetupAttachment(SceneComponent);
	FloorTrigger->SetBoxExtent(FVector(32.f, 500.f, 200.f));
	FloorTrigger->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));


}

// Called when the game starts or when spawned
void AEndlessFloor::BeginPlay()
{
	Super::BeginPlay();
	GameMode = Cast<AEndlessRunnerGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	
	check(GameMode);

	FloorTrigger->OnComponentBeginOverlap.AddDynamic(this, &AEndlessFloor::OnTriggerBoxOverlap);
}

void AEndlessFloor::OnTriggerBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ARunCharacter* Character = Cast<ARunCharacter>(OtherActor);

	if (Character)
	{
		GameMode->AddFloors(true);

		GetWorldTimerManager().SetTimer(DestoryHandle, this, &AEndlessFloor::DestoryOldFloor, 2.f, false);
	}
}

void AEndlessFloor::DestoryOldFloor()
{
	if (DestoryHandle.IsValid())
	{
		GetWorldTimerManager().ClearTimer(DestoryHandle);
	}

	this->Destroy();
}

void AEndlessFloor::ChooseLaneToSpawnObstacle(UArrowComponent* Lane)
{

}


void AEndlessFloor::SpawnObstacle()
{
	ChooseLaneToSpawnObstacle(LeftLane);
	ChooseLaneToSpawnObstacle(CenterLane);
	ChooseLaneToSpawnObstacle(RightLane);
}

