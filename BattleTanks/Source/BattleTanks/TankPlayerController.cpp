// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"




ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


// This is the override function for BeginPlay
void ATankPlayerController::BeginPlay()
{
	// Call the BeginPlay method from the Parent
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("TankPlayerController -> BeginPlay method running!"))

	// get possessed pawn and log if there is one or not
	ATank* ControlledTankPawn = GetControlledTank();
	if (ControlledTankPawn) {
		UE_LOG(LogTemp, Warning, TEXT("SUCCESS: TankPlayerController -> Possesed Pawn(Tank) is -> %s!"), *(ControlledTankPawn->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("WARNING -> No possesed tank pawn! check made by TankPlayerController::BeginPlay method."));
	}

}
