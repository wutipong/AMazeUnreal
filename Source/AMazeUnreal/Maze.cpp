// Fill out your copyright notice in the Description page of Project Settings.


#include "Maze.h"

// Sets default values
AMaze::AMaze()
{
}

// Called when the game starts or when spawned
void AMaze::BeginPlay()
{
	Super::BeginPlay();

	cells.SetNumUninitialized(Count());

	int cellWidth = Cell.GetDefaultObject()->Width;
	int cellHeight = Cell.GetDefaultObject()->Depth;

	FVector origin;
	FVector extent;
	Cell.GetDefaultObject()->GetActorBounds(false, origin, extent);

	for (int r = 0; r < Rows; r++) 
	{
		for (int c = 0; c < Columns; c++) 
		{
			int index = (r * Columns) + c;
			float x = c * cellWidth;
			float y = r * cellHeight;

			FTransform transform;
			transform.SetLocation({ x, y, 0 });

			auto cell = GetWorld()->SpawnActor(Cell.Get(), &transform);
			cells[index] = dynamic_cast<ACell*>(cell);
		}
	}
}

