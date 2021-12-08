// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cell.h"

#include "Maze.generated.h"

UCLASS()
class AMAZEUNREAL_API AMaze : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMaze();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	TArray<ACell*> cells;

public:	
	UPROPERTY(EditAnywhere)
	int32 Columns = 5;

	UPROPERTY(EditAnywhere)
	int32 Rows = 6;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ACell> Cell;

	int Count() const { return Columns * Rows; }
};
