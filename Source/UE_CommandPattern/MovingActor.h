// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Command.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor.generated.h"

class UStaticMeshComponent;


USTRUCT()
struct FMatrixPosition
{
	GENERATED_BODY()

	uint16 X {0};
	uint16 Y {0};
};


UCLASS()
class UE_COMMANDPATTERN_API AMovingActor : public AActor, public ICommand
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	UStaticMeshComponent* ActorMesh{nullptr};

	
	FMatrixPosition CurrentPosition{0, 0};
	
public:	
	// Sets default values for this actor's properties
	AMovingActor();

	virtual void Tick(float DeltaSeconds) override;

	virtual void Execute( EMovementStatus MovementStatus) override;
	virtual void Undo() override;
	virtual void Redo() override;

	void MoveForward();
	void MoveBack();
	void MoveRight();
	void MoveLeft();

};
