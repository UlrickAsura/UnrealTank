// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"
/**
 * Responsible from driving the tank tracks
 */
class UTankTrack;
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable,Category= Input)
	void IntendMoveForward(float Throw);	
	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendTurnRight(float Throw);
	UFUNCTION(BlueprintCallable,Category = Setup)
	void Initialise(UTankTrack* LeftTrack,UTankTrack* RightTRack);
private:
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
};