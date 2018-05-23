// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

//AI finding the player controller
ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn)
	{
		return nullptr;
	}

	return Cast<ATank>(PlayerPawn);
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Controlled Tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Controlled Tank : %s"), *ControlledTank->GetName())
	}

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Player Tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank : %s"), *PlayerTank->GetName())
	}
	UE_LOG(LogTemp, Warning, TEXT("AI On Begin Play"));

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		GetControlledTank()->AimAt(FVector(GetPlayerTank()->GetActorLocation()));
		//TODO move,aim,fire towards the player
		return;
	}
}
