// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"



ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


ATank* ATankAIController::GetPlayerTank() const
{
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (!PlayerTank) {
		return nullptr;
	}

	return PlayerTank;
}

void ATankAIController::BeginPlay()
{
	// Call the BeginPlay method from the Parent
	Super::BeginPlay();

	ATank* AIControlledTankPawn = GetControlledTank();
	ATank* PlayerTankPawn = GetPlayerTank();

	/// Log info for AIControlledTankPawn
	if (AIControlledTankPawn) {
		UE_LOG(LogTemp, Warning, TEXT("SUCCESS: TankAIController -> Possesed Pawn(Tank) is -> %s!"), *(AIControlledTankPawn->GetName()));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("ERROR: TankAIController-> Issue from BeginPlay, attempting possession failed!"));
	}


	/// Log info for PlayerTankPawn
	if (PlayerTankPawn) {
		UE_LOG(LogTemp, Warning,
			TEXT("AI SUCCESS(PLAYER FOUND): TankAIController -> Pawn: %s found Player Controller: %s"),
			*(GetControlledTank()->GetName()), *(PlayerTankPawn->GetName()))
	} else {
		UE_LOG(LogTemp, Warning,
			TEXT("AI ERROR(CAN'T FIND PLAYER) : TankAIController -> Pawn: %s can't find Player Controller"),
			*(GetControlledTank()->GetName()))
	}
}
