#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
public:
	Grid();
	void Initialize();
	void Draw();
	bool IsCellOutside(int row, int cloumn);
	bool IsCellEmpty(int row, int column);
	int ClearFullRows();
	void Print();
	int grid[20][10];


private:
	int numRows;
	int numCols;
	int cellSize;
	bool IsRowFull(int row);
	void ClearRow(int row);
	void MoveRowDown(int row, int numRows);
	std::vector<Color> colors;
};

