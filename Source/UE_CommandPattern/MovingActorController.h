// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Command.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MovingActorController.generated.h"

/**
 * 
 */


UCLASS()
class UE_COMMANDPATTERN_API AMovingActorController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	
	ICommand* Command;

	
public:
	virtual void SetupInputComponent() override;
	
protected:
	virtual void BeginPlay() override;

private:

	void ExecuteActions(EMovementStatus MovementStatus);
};
