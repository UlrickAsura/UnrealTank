// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()
public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector WorldSpaceAim) const;

	UFUNCTION(BlueprintCallable,Category = Setup)
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet) const;
protected:
	UTankAimingComponent* TankAimingComponent = nullptr;
private:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;	

	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 100000.0f;
};
