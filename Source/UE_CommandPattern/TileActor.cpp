
#include "TileActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ATileActor::ATileActor()
{
	FloorMesh = CreateDefaultSubobject<UStaticMeshComponent>("Floor");
}

void ATileActor::SetTileMaterial(bool bBright)
{
	if(!ensure(BrightMat) || !ensure(DarkMat)) return;
	
	if (bBright)
		FloorMesh->SetMaterial(0, BrightMat);
	else
		FloorMesh->SetMaterial(0, DarkMat);
}



