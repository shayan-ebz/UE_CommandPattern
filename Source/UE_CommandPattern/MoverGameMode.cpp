// Fill out your copyright notice in the Description page of Project Settings.
#include "MoverGameMode.h"
#include "TileActor.h"
#include "MovingActor.h"


AMoverGameMode::AMoverGameMode(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer), TileNumberX(8), TileNumberY(8) 
{
	// it's more optimized to reserve memory for the array(dynamic allocations have resizing overheads, this way there is no need to redundant copies)
	TileArray.Reserve(64);
}

void AMoverGameMode::BeginPlay()
{
	Super::BeginPlay();

	//spawn moving actor
	auto MovingActor = GetWorld()->SpawnActor<AMovingActor>(MovingActorInstance, FVector{ 0,0,360 }, FRotator{ 0, 0, 0 });
	if(!ensure(MovingActor)) return;
	MoverActor = MovingActor;

	// generate the tiles of chessboard.
	for (int i{ 0 }; i < 64; ++i)
	{
		auto RowNumber{ i / TileNumberY };
		auto ColumnNumber{ i % TileNumberX };
		
		FVector SpawnLocation{ RowNumber * 1000.f, ColumnNumber * 1000.f, 0.f };
		auto TileToSpawn{ GetWorld()->SpawnActor<ATileActor>(TileActorInstance, SpawnLocation, FRotator(0, 0, 0)) };
		if (!ensure(TileToSpawn)) return;

		TileArray.Add(TileToSpawn);

		if ((i + RowNumber) % 2 == 0 )
			TileToSpawn->SetTileMaterial(true);
		else
			TileToSpawn->SetTileMaterial(false);
	}
}
