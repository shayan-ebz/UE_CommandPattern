
#include "MovingActor.h"

// Sets default values
AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;
	
	ActorMesh = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
}

void AMovingActor::MoveForward()
{
	// end of the board situation
	if(CurrentPosition.Y == 7 )
		return;
	// moves based on the size of the tiles.
	CurrentPosition.Y += 1;
	this->SetActorLocation(FVector(GetActorLocation().X + 1000.f, GetActorLocation().Y, GetActorLocation().Z));
}

void AMovingActor::MoveBack()
{
	// end of the board situation
	if (CurrentPosition.Y == 0)
		return;
	// moves based on the size of the tiles.
	CurrentPosition.Y -= 1;
	this->SetActorLocation(FVector(GetActorLocation().X - 1000.f, GetActorLocation().Y, GetActorLocation().Z));
}

void AMovingActor::MoveRight()
{
	// end of the board situation
	if (CurrentPosition.X == 7) 
		return;
	// moves based on the size of the tiles.
	CurrentPosition.X += 1;
	this->SetActorLocation(FVector(GetActorLocation().X , GetActorLocation().Y + 1000.f, GetActorLocation().Z));
}

void AMovingActor::MoveLeft()
{
	// end of the board situation
	if (CurrentPosition.X == 0)
		return;
	// moves based on the size of the tiles 
	CurrentPosition.X -= 1;
	this->SetActorLocation(FVector(GetActorLocation().X , GetActorLocation().Y - 1000.f, GetActorLocation().Z));
}


void AMovingActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}


void AMovingActor::Execute(EMovementStatus MovementStatus)
{
	switch (MovementStatus)
	{
	case EMovementStatus::MoveFWD:
		MoveForward();
		MovementCommands.Add(MovementStatus);
		break;
	case EMovementStatus::MoveBWD:
		MoveBack();
		MovementCommands.Add(MovementStatus);
		break;
	case EMovementStatus::MoveR:
		MoveRight();
		MovementCommands.Add(MovementStatus);
		break;
	case EMovementStatus::MoveL:
		MoveLeft();
		MovementCommands.Add(MovementStatus);	
		break;
	}
}

void AMovingActor::Undo()
{
	if(MovementCommands.Num()<= 0)return;
	
	switch (MovementCommands.Last())
	{
	case EMovementStatus::MoveFWD:
		MoveBack();
		break;
	case EMovementStatus::MoveBWD:
		MoveForward();
		break;
	case EMovementStatus::MoveR:
		MoveLeft();
		break;
	case EMovementStatus::MoveL:
		MoveRight();
		break;
	}
	
	PoppedActionsCommands.Add(MovementCommands.Last());
	MovementCommands.RemoveAt(MovementCommands.Num() - 1);
}

void AMovingActor::Redo()
{
	if(PoppedActionsCommands.Num() <= 0) return;
	
	Execute(PoppedActionsCommands.Last());
	PoppedActionsCommands.RemoveAt(PoppedActionsCommands.Num() - 1);
}

