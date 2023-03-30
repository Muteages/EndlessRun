// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimationInstance.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UAnimationInstance::NativeInitializeAnimation()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
	}

	if (Pawn)
	{
		MovementComponent = Pawn->GetMovementComponent();
	}
}

void UAnimationInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if (Pawn && MovementComponent)
	{
		bIsJump = MovementComponent->IsFalling();
		Speed = Pawn->GetVelocity().Size();
	}
}
