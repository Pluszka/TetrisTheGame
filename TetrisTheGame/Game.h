#pragma once
#include "Grid.h"
#include "Blocks.cpp"
class Game
{
public:
	Game();
	void Draw();
	void HandleInput();
	void MoveBlockDown();
	bool gameOver;
	int score;

private:
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	void MoveBlockLeft();
	void MoveBlockRight();
	Grid grid;
	bool IsBlockOutside();
	std::vector<Block> blocks;
	void RotateBlock();
	void LockBlock();
	bool BlockFits();
	Block currentBlock;
	Block nextBlock;
	void Reset();
	void updateScore(int linesCleared, int moveDownPoints);
};

