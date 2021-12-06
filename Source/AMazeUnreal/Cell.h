// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Direction.h"

#include "Cell.generated.h"

UCLASS()
class AMAZEUNREAL_API ACell : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACell();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY()
	int Id = 0;
	
	UPROPERTY()
	TSubclassOf<AActor> WallNorth;

	UPROPERTY()
	TSubclassOf<AActor> WallSouth;
	
	UPROPERTY()
	TSubclassOf<AActor> WallEast;
	
	UPROPERTY()
	TSubclassOf<AActor> WallWest;

	UPROPERTY()
	int Width;
	
	UPROPERTY()
	int Depth;

	static constexpr int InvalidCell = -1;

	void ConnectTo(ACell* pToCell, EDirection direction);

	int& ConnectedCell(EDirection direction);

private:
	int connectedCells[static_cast<int>(EDirection::Count)] = { InvalidCell, InvalidCell, InvalidCell, InvalidCell };

};
