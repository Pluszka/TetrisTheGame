#include "Block.h"
Block::Block() {
	cellSize = 30;
	rotationState = 0;
	colors = GetCellColors();
	rowOffset = 0;
	columnOffset = 0;
}

void Block::Draw(int offsetX, int offsetY)
{
	std::vector<Position> titles = GetCellPosition();
	for (Position item : titles) {
		DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
	}
}

void Block::Move(int rows, int columns) {
	rowOffset += rows;
	columnOffset += columns;
}

std::vector<Position> Block::GetCellPosition() {
	std::vector<Position> titles = cells[rotationState];
	std::vector<Position> movedTitles;
	for (Position item : titles) {
		Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
		movedTitles.push_back(newPos);
	}
	return movedTitles;
}

void Block::Rotate()
{
	rotationState++;
	if (rotationState == (int)cells.size()) {
		rotationState = 0;
	}
}

void Block::UndoRotation()
{
	rotationState--;
	if (rotationState == -1) {
		rotationState = cells.size() - 1;
	}
}
