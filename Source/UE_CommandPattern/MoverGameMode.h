// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MoverGameMode.generated.h"

class ATileActor;
class AMovingActor;
class ICommand;


UCLASS()
class UE_COMMANDPATTERN_API AMoverGameMode : public AGameModeBase
{
	GENERATED_BODY()


private:

	UPROPERTY(EditDefaultsOnly, Category = "Tile", meta = (PrivateAccess = "True"))
		TSubclassOf<ATileActor> TileActorInstance{ nullptr };

	UPROPERTY(EditDefaultsOnly, Category = "Tile", meta = (PrivateAccess = "True"))
		TSubclassOf<AMovingActor>MovingActorInstance{ nullptr };

	UPROPERTY(VisibleAnywhere, Category = "Tile", meta = (PrivateAccess = "True"))
		TArray<ATileActor*> TileArray;

	int TileNumberX;
	int TileNumberY;

	UPROPERTY()
	AMovingActor* MoverActor {nullptr};


	
public:
	// CTor
	AMoverGameMode(const FObjectInitializer& ObjectInitializer);

	FORCEINLINE AMovingActor* GetMoverActor() { return MoverActor; }
	
protected:
	void BeginPlay() override;


	
};
