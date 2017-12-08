#include<stdio.h>
#include<math.h>

#define ROW 515
#define COL 515

struct Position {
	int pos_x;
	int pos_y;
};

enum STATE {RIGHT, UP, LEFT, DOWN};

int add_adjecant(struct Position pos, int arr[515][515], char visited[515][515]) {

	int temp = 0;

	//Top-left
	if (visited[pos.pos_y-1][pos.pos_x-1]) {
		temp += arr[pos.pos_y-1][pos.pos_x-1];
	}
	//Top-middle
	if (visited[pos.pos_y-1][pos.pos_x]) {
		temp += arr[pos.pos_y-1][pos.pos_x];
	}
	//Top-right
	if (visited[pos.pos_y-1][pos.pos_x+1]) {
		temp += arr[pos.pos_y-1][pos.pos_x+1];
	}

	//Middle-left
	if (visited[pos.pos_y][pos.pos_x-1]) {
		temp += arr[pos.pos_y][pos.pos_x-1];
	}
	//Middle-Right
	if (visited[pos.pos_y][pos.pos_x+1]) {
		temp += arr[pos.pos_y][pos.pos_x+1];
	}

	//Bottom-Left
	if (visited[pos.pos_y+1][pos.pos_x-1]) {
		temp += arr[pos.pos_y+1][pos.pos_x-1];
	}
	//Bottom-middle
	if (visited[pos.pos_y+1][pos.pos_x]) {
		temp += arr[pos.pos_y+1][pos.pos_x];
	}
	//Bottom-right
	if (visited[pos.pos_y+1][pos.pos_x+1]) {
		temp += arr[pos.pos_y+1][pos.pos_x+1];
	}

	return temp;

}

int main() {
	
	int result = 0;
	char visited[ROW][COL] = {0};
	int  array[ROW][COL] = {0};

	struct Position initial_pos;
	initial_pos.pos_x = 257;
	initial_pos.pos_y = 257;

	enum STATE state;
	state = RIGHT;

	int step = 1;
	int time = 0;
	array[257][257] = 1;
	visited[257][257] = 1;

	do {
		result = 0;
		switch (state) {
			case RIGHT:

				initial_pos.pos_x++;
				time++;
				if (time == step) {
				    time = 0;
					state = UP;
				}

				break;
			case UP:

				initial_pos.pos_y--;
				time++;
				if (time == step) {
				    time = 0;
					state = LEFT;
					step++;
				}
				
				break;
			case LEFT:

				initial_pos.pos_x--;
				time++;
				if (time == step) {
				    time = 0;
					state = DOWN;
				}

				break;
			case DOWN:

				initial_pos.pos_y++;
				time++;
				if (time == step) {
					step++;
					time = 0;
					state = RIGHT;
				}

				break;
		}

		result += add_adjecant(initial_pos, array, visited);
		array[initial_pos.pos_y][initial_pos.pos_x] = result;
		visited[initial_pos.pos_y][initial_pos.pos_x] = 1;
		printf("<%d, %d>: %d\n", initial_pos.pos_y, initial_pos.pos_x, result);
	} while (result < 265149 );

	printf("Result is %d\n", result);
	printf("Position is %d\n", abs(initial_pos.pos_y - 257) + abs(initial_pos.pos_x - 257));

	return 0;

}