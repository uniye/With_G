#include <stdio.h>

const int N = 8;
int grid[8][8] = {
		{1,1,1,0,0,0,0,1},
		{0,1,0,0,1,1,0,1},
		{0,0,0,0,0,1,0,1},
		{0,1,0,0,1,1,0,0},
		{0,1,1,0,0,0,1,1},
		{0,1,0,0,0,1,0,1},
		{0,0,1,1,0,0,1,1},
		{0,1,1,1,0,1,0,0}
};

const int BACKGROUND_COLOR = 0;
const int IMAGE_COLOR = 1;
const int ALREADY_COUNTED = 2;

int countCells(int x, int y);

main() {
	int cells = countCells(0,0);
	printf("%d",cells);
}

int countCells(int x, int y) {
	int result;
	if (x < 0 || x >= N || y < 0 || y >= N)
		return 0;
	else if (grid[x][y] != IMAGE_COLOR)
		return 0;
	else {
		grid[x][y] = ALREADY_COUNTED;
		return 1 + countCells(x - 1, y + 1) + countCells(x, y + 1) 
			+ countCells(x + 1, y + 1) + countCells(x - 1, y)
			+ countCells(x + 1, y) + countCells(x - 1, y - 1)
			+ countCells(x, y - 1) + countCells(x + 1, y - 1);
	}
}