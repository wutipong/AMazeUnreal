// Fill out your copyright notice in the Description page of Project Settings.


#include "Maze.h"
#include "MazeGen/maze_gen.hpp"

// Sets default values
AMaze::AMaze()
{
}

// Called when the game starts or when spawned
void AMaze::BeginPlay()
{
	Super::BeginPlay();

	cells.SetNumUninitialized(Count());

	auto cellWidth = Cell.GetDefaultObject()->Width;
	auto cellDepth = Cell.GetDefaultObject()->Depth;

	auto maze = MazeGen::Generate(Columns, Rows);

	for (int r = 0; r < Rows; r++)
	{
		for (int c = 0; c < Columns; c++)
		{
			int index = (r * Columns) + c;
			float x = c * cellWidth;
			float y = r * cellDepth;

			// Unreal coordinate system is opposite to MazeGen coordinate system.
			FVector location{ -x, -y, 0 };
			FRotator rotator{ 0,0,0 };

			FActorSpawnParameters params{};
			params.Owner = this;

			cells[index] = GetWorld()->SpawnActor<ACell>(Cell, location, rotator, params); 
			cells[index]->Apply(maze[index]);
		}
	}
}

