// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AnimationInstance.generated.h"

/**
 * 
 */
UCLASS()
class ENDLESSRUNNER_API UAnimationInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	//initialize
	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;





	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Movement")
		float Speed;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Movement")
		bool bIsJump;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Movement")
		class APawn* Pawn;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Movement")
		class UPawnMovementComponent* MovementComponent;	
};
