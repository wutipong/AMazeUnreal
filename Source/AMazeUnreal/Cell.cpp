// Fill out your copyright notice in the Description page of Project Settings.


#include "Cell.h"

// Sets default values
ACell::ACell()
{
}

// Called when the game starts or when spawned
void ACell::BeginPlay()
{
	Super::BeginPlay();

	if (ConnectedCell(EDirection::North) != InvalidCell) 
	{
		dynamic_cast<AActor*>(WallNorth.Get())->Destroy();
	}

	if (ConnectedCell(EDirection::South) != InvalidCell) 
	{
		dynamic_cast<AActor*>(WallSouth.Get())->Destroy();
	}

	if (ConnectedCell(EDirection::East) != InvalidCell) 
	{
		dynamic_cast<AActor*>(WallEast.Get())->Destroy();
	}

	if (ConnectedCell(EDirection::West) != InvalidCell) 
	{
		dynamic_cast<AActor*>(WallWest.Get())->Destroy();
	}
}

void ACell::ConnectTo(ACell* pToCell, EDirection direction)
{
	ConnectedCell(direction) = pToCell->Id;
	pToCell->ConnectedCell(Opposite(direction)) = Id;
}

int& ACell::ConnectedCell(EDirection direction) 
{
	int d = static_cast<int>(direction);
	return connectedCells[d];
}
