// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EndlessRunnerGameModeBase.h"
#include "RunCharacter.generated.h"

UCLASS()
class ENDLESSRUNNER_API ARunCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARunCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void MoveLeft();

	UFUNCTION()
		void MoveRight();

	UFUNCTION()
		void MoveDown();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Lane Switch")
		void ChangeLane();

	UFUNCTION(BlueprintCallable, Category = "Lane Switch")
		void UpdateLane(float laneID);

	UFUNCTION(BlueprintCallable, Category = "Lane Switch")
		void UpdateLaneFinished();

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite)
		int CurrentLane = 1;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite)
		int NextLane = 0;


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* Camera;

	UPROPERTY(VisibleInstanceOnly)
		class AEndlessRunnerGameModeBase* GameMode;



		
};
