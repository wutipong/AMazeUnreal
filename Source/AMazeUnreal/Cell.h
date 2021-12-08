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
	int Width;
	
	UPROPERTY(EditDefaultsOnly)
	int Depth;

	static constexpr int InvalidCell = -1;

	void ConnectTo(ACell* pToCell, EDirection direction);

	int& ConnectedCell(EDirection direction);

private:
	int connectedCells[static_cast<int>(EDirection::Count)] = { InvalidCell, InvalidCell, InvalidCell, InvalidCell };

};
