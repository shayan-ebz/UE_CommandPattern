// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileActor.generated.h"

class UStaticMeshComponent;
class UMaterialInterface;

UCLASS()
class UE_COMMANDPATTERN_API ATileActor : public AActor
{
	GENERATED_BODY()



protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	UStaticMeshComponent* FloorMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Material")
	UMaterialInterface* BrightMat{nullptr};

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Material")
	UMaterialInterface* DarkMat{nullptr};
	
	
public:	
	// Sets default values for this actor's properties
	ATileActor();

	void SetTileMaterial(bool bBright);

};
