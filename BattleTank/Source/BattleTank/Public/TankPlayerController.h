// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

//Forward Declarations
class ATank;
/**
*
*/
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float) override;
private:

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.33333f;
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 10000000.0f;

	// Find the crosshair position
	// "De-project" the screen position of the crosshair to a world direction
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
	ATank* GetControlledTank() const;
	bool GetSightRayHitLocation(FVector&) const;

	bool GetLookVectorHit(FHitResult&) const;
	// Start the tank moving the barrel so that a shot would hit where 
	// the crosshair intersects the world
	void   AimTowardsCrosshair();

};