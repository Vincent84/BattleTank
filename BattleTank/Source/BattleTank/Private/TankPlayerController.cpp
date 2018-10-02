// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetContolledTank();
	if(!ControlledTank)
	{ 
		UE_LOG(LogTemp, Warning, TEXT("Player controller doesn't possess a tank"));
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Player controller possesses the %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));
}

ATank * ATankPlayerController::GetContolledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if(!GetContolledTank()) { return; }

}
