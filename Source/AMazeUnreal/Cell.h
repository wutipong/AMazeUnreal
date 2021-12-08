// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MazeGen/maze_gen.hpp"

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
	int Id = 0;
	
	UPROPERTY(BlueprintReadWrite, Instanced)
	UStaticMeshComponent* WallNorth;

	UPROPERTY(BlueprintReadWrite, Instanced)
	UStaticMeshComponent* WallSouth;
	
	UPROPERTY(BlueprintReadWrite, Instanced)
	UStaticMeshComponent* WallEast;
	
	UPROPERTY(BlueprintReadWrite, Instanced)
	UStaticMeshComponent* WallWest;

	UPROPERTY(EditDefaultsOnly)
	float Width;
	
	UPROPERTY(EditDefaultsOnly)
	float Depth;

	void Apply(const MazeGen::Cell& cell);
};
