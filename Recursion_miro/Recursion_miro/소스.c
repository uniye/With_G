#include <stdio.h>
#include <stdbool.h>

int maze[8][8] = {
		{0,0,0,0,0,0,0,1},
		{0,1,1,0,1,1,0,1},
		{0,0,0,1,0,0,0,1},
		{0,1,0,0,1,1,0,0},
		{0,1,1,1,0,0,1,1},
		{0,1,0,0,0,1,0,1},
		{0,0,0,1,0,0,0,1},
		{0,1,1,1,0,1,0,0}
};
const int N = 8;
const int PATHWAY_COLOR=0;
const int WALL_COLOR = 1;
const int BLOCKED_COLOR = 2;
const int PATH_COLOR = 3;

bool findMazePath(int x, int y);
void printMaze();


main() {
	printMaze();
	printf("\n");
	findMazePath(0, 0);
	printMaze();
}

void printMaze() {
	for (int a = 0; a < 8; a++) {
		for (int b = 0; b < 8; b++) {
			printf("%d",maze[a][b]);
		}
		printf("\n");
	}
	
}

bool findMazePath(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= N)
		return false;
	else if (maze[x][y] != PATHWAY_COLOR)
		return false;
	else if (x == N - 1 && y == N - 1) {
		maze[x][y] = PATH_COLOR;
		return true;
	}
	else {
		maze[x][y] = PATH_COLOR;
		if (findMazePath(x - 1, y) || findMazePath(x, y + 1)
			|| findMazePath(x + 1, y) || findMazePath(x, y - 1)) {
			return true;
		}
		maze[x][y] = BLOCKED_COLOR;
		return false;
	}
}
