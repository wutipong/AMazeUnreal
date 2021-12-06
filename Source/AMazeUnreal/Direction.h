// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

enum class EDirection 
{
	North, South, East, West, Count, Invalid = -1
};

EDirection Opposite(const EDirection& dir);