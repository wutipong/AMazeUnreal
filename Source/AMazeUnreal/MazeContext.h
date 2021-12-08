#pragma once

#include "Direction.h"

#include <memory>
#include <set>
#include <vector>

struct CellData {
	int id;
	int connectedCells[static_cast<int>(EDirection::Count)];
};

class MazeContext {
public:
	typedef std::set<int> Set;
	typedef std::shared_ptr<Set> SetPtr;

	struct JoinResult {
		int from;
		int to;
		EDirection direction;
	};

	const int Rows;
	const int Columns;

	static constexpr int InvalidCell = -1;

	MazeContext(int columns, int rows);
	bool TryJoinSet(int from, int to);
	JoinResult RandomJoin();
	int GetAdjacentCell(int cell, EDirection direction) const;

	int Count()const { return Rows * Columns; }

private:
	std::vector<SetPtr> disjointSets;
	int setCount;
};