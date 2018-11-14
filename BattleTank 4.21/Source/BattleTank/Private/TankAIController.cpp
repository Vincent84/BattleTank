// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{

	Super::BeginPlay();

	ATank * PlayerTank = GetPlayerTank();

	if(!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller doesn't found player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found Player %s"), *(PlayerTank->GetName()));
	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(GetPlayerTank())
	{
		GetAITank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
	
}

ATank * ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if(!PlayerTank) { return nullptr; }
	return Cast<ATank>(PlayerTank);
}


