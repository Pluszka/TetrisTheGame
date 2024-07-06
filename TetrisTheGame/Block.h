#pragma once
#include <vector>
#include <map>
#include "Position.h"
#include <raylib.h>
#include "Color.h"

class Block
{
public:
	Block();
	void Draw(int offsetX, int offsetY);
	void Move(int rows, int coulmns);
	std::vector<Position> GetCellPosition();
	int id;
	std::map<int, std::vector<Position>> cells;
	void Rotate();
	void UndoRotation();

private:
	int cellSize;
	int rotationState;
	std::vector<Color> colors;
	int rowOffset;
	int columnOffset;
};

