// Fill out your copyright notice in the Description page of Project Settings.


#include "Direction.h"

EDirection Opposite(const EDirection& dir)
{
	switch (dir) {
	case EDirection::North:
		return EDirection::South;

	case EDirection::South:
		return EDirection::North;

	case EDirection::East:
		return EDirection::West;

	case EDirection::West:
		return EDirection::East;

	default:
		return EDirection::Invalid;
	}
}
