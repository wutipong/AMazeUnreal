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

	
}

void ACell::Apply(const MazeGen::Cell& cell)
{
	if (cell.ConnectedCell(MazeGen::Direction::North) != MazeGen::InvalidCell) 
	{
		WallNorth->DestroyComponent();
	}

	if (cell.ConnectedCell(MazeGen::Direction::South) != MazeGen::InvalidCell)
	{
		WallSouth->DestroyComponent();
	}

	if (cell.ConnectedCell(MazeGen::Direction::East) != MazeGen::InvalidCell)
	{
		WallEast->DestroyComponent();
	}

	if (cell.ConnectedCell(MazeGen::Direction::West) != MazeGen::InvalidCell)
	{
		WallWest->DestroyComponent();
	}
}