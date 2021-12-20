
#include "MovingActorController.h"
#include "MoverGameMode.h"
#include "MovingActor.h"


void AMovingActorController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// bind inputs
	// since the action functions have one param we need to declare them as one param delegates
	DECLARE_DELEGATE_OneParam(FCustomInputDelegate, const EMovementStatus);
	InputComponent->BindAction<FCustomInputDelegate>("MoveFWD", IE_Pressed, this, &AMovingActorController::ExecuteActions, EMovementStatus::MoveFWD);
	InputComponent->BindAction<FCustomInputDelegate>("MoveBWD", IE_Pressed, this, &AMovingActorController::ExecuteActions, EMovementStatus::MoveBWD);
	InputComponent->BindAction<FCustomInputDelegate>("MoveR", IE_Pressed, this, &AMovingActorController::ExecuteActions, EMovementStatus::MoveR);
	InputComponent->BindAction<FCustomInputDelegate>("MoveL", IE_Pressed, this, &AMovingActorController::ExecuteActions, EMovementStatus::MoveL);
	InputComponent->BindAction<FCustomInputDelegate>("Undo", IE_Pressed, this, &AMovingActorController::ExecuteActions, EMovementStatus::Undo);
	InputComponent->BindAction<FCustomInputDelegate>("Redo", IE_Pressed, this, &AMovingActorController::ExecuteActions, EMovementStatus::Redo);
}

void AMovingActorController::BeginPlay()
{
	auto GM = Cast<AMoverGameMode>(GetWorld()->GetAuthGameMode());
	check(GM);

	Command = GM->GetMoverActor();
}

void AMovingActorController::ExecuteActions(EMovementStatus MovementStatus)
{
	if (MovementStatus != EMovementStatus::Undo && MovementStatus != EMovementStatus::Redo)
	{
		Command->Execute(MovementStatus);
	}
	else if (MovementStatus == EMovementStatus::Undo)
	{
		Command->Undo();
	}
	else
	{
		Command->Redo();
	}
}
	