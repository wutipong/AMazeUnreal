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
		WallNorth->DestroyComponent();
	}

	if (ConnectedCell(EDirection::South) != InvalidCell) 
	{
		WallSouth->DestroyComponent();
	}

	if (ConnectedCell(EDirection::East) != InvalidCell) 
	{
		WallEast->DestroyComponent();
	}

	if (ConnectedCell(EDirection::West) != InvalidCell) 
	{
		WallWest->DestroyComponent();
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
