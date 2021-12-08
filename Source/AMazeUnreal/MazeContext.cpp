#include "MazeContext.h"
#include <random>

namespace {
	std::random_device r;
	EDirection randomDirection()
	{
		std::default_random_engine e(r());

		// maximum value is exclusive.
		std::uniform_int_distribution<int> uniform_dist(0, static_cast<int>(EDirection::Count) - 1);

		return static_cast<EDirection>(uniform_dist(e));
	}

	int randomCell(int maxCell)
	{
		std::default_random_engine e(r());

		// maximum value is exclusive.
		std::uniform_int_distribution<int> uniform_dist(0, maxCell - 1);

		return uniform_dist(e);
	}
}

MazeContext::MazeContext(int columns, int rows) :Columns(columns), Rows(rows), setCount(Count())
{
	disjointSets.reserve(Count());
	for (int i = 0; i < Count(); i++)
	{
		auto ptr = std::make_shared<Set>();
		ptr->emplace(i);

		disjointSets.emplace_back(ptr);
	}
}

MazeContext::JoinResult MazeContext::RandomJoin()
{
	while (true)
	{
		auto fromCell = randomCell(Count());
		auto direction = randomDirection();
		auto toCell = GetAdjacentCell(fromCell, direction);
		if (TryJoinSet(toCell, fromCell))
		{
			return { fromCell, toCell, direction };
		}
	}
}

int MazeContext::GetAdjacentCell(int cell, EDirection direction) const
{
	int column = cell % Columns;
	int row = cell / Columns;

	switch (direction)
	{
	case EDirection::North:
		row--;
		break;

	case EDirection::South:
		row++;
		break;
	case EDirection::West:
		column--;
		break;

	case EDirection::East:
		column++;
		break;
	}

	if (row < 0 || row == Rows || column < 0 || column == Columns)
		return InvalidCell;

	return (row * Columns) + column;
}

bool MazeContext::TryJoinSet(int to, int from)
{
	if (to == InvalidCell)
		return false;

	if (from == InvalidCell)
		return false;

	auto& toSet = disjointSets[to];
	auto& fromSet = disjointSets[from];

	for (auto c : *fromSet)
	{
		if (toSet->find(c) != toSet->end())
		{
			return false;
		}
	}

	toSet->insert(fromSet->begin(), fromSet->end());

	Set destSet = *fromSet;

	for (auto c : destSet)
	{
		disjointSets[c] = toSet;
	}

	setCount--;

	return true;
}
