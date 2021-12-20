// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Command.generated.h"

// forward declaration
class AMovingActor;


// all the movement modes
UENUM(BlueprintType)
enum class EMovementStatus : uint8 {
	MoveFWD       UMETA(DisplayName = "Forward"),
	MoveBWD       UMETA(DisplayName = "Backward"),
	MoveR         UMETA(DisplayName = "Right"),
	MoveL         UMETA(DisplayName = "Left"),
	Undo		  UMETA(DisplayName = "Undo"),
	Redo		  UMETA(DisplayName = "Redo")
};

 


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCommand : public UInterface
{
	GENERATED_BODY()
};


class UE_COMMANDPATTERN_API ICommand
{
	/*NOTE: no need for virtual destructor since it has an inherited virtual destructor.*/

	GENERATED_BODY()
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.

protected:
	// two arrays of movement stats (the second is helper)
	TArray<EMovementStatus> MovementCommands;
	TArray<EMovementStatus> PoppedActionsCommands;
		
public:
	// pure virtual functions.
	virtual void Execute(EMovementStatus MovementStatus) = 0;
	virtual void Undo() = 0;
	virtual void Redo() = 0;
};
