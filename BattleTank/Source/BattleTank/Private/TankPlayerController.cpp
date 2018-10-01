// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{

	Super::BeginPlay();

	ATank * ControlledTank = GetContolledTank();

	if(!ControlledTank)
	{ 
		UE_LOG(LogTemp, Warning, TEXT("You don't possess a tank"));
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("You possess the %s"), *(ControlledTank->GetName()));
	}
}

ATank * ATankPlayerController::GetContolledTank() const
{
	return Cast<ATank>(GetPawn());
}
