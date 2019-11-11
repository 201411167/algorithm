#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int sx, sy, k;
int map[21][21];
int dir[5][2] = { {0,0},{0,1},{0,-1},{-1,0},{1,0} };

struct DICE {
	int x, y;
	int back;
	int left;
	int up;
	int right;
	int front;
	int down;
};
DICE moveDice(DICE dice, int direction) {
	DICE nxtDice;
	if (direction == 1) { //east
		nxtDice.x = dice.x;
		nxtDice.y = dice.y + 1;
		nxtDice.back = dice.back;
		nxtDice.left = dice.down;
		nxtDice.up = dice.left;
		nxtDice.right = dice.up;
		nxtDice.front = dice.front;
		nxtDice.down = dice.right;
	}
	if (direction == 2) { //west
		nxtDice.x = dice.x;
		nxtDice.y = dice.y - 1;
		nxtDice.back = dice.back;
		nxtDice.left = dice.up;
		nxtDice.up = dice.right;
		nxtDice.right = dice.down;
		nxtDice.front = dice.front;
		nxtDice.down = dice.left;
	}
	if (direction == 3) { //north
		nxtDice.x = dice.x - 1;
		nxtDice.y = dice.y;
		nxtDice.back = dice.up;
		nxtDice.left = dice.left;
		nxtDice.up = dice.front;
		nxtDice.right = dice.right;
		nxtDice.front = dice.down;
		nxtDice.down = dice.back;
	}
	if (direction == 4) { //south
		nxtDice.x = dice.x + 1;
		nxtDice.y = dice.y;
		nxtDice.back = dice.down;
		nxtDice.left = dice.left;
		nxtDice.up = dice.back;
		nxtDice.right = dice.right;
		nxtDice.front = dice.up;
		nxtDice.down = dice.front;
	}
	return nxtDice;
}

void print(DICE dice) {
	cout << "  " << dice.back << "\n";
	cout << dice.left << " " << dice.up << " " << dice.right << "\n";
	cout << "  " << dice.front << "\n";
	cout << "  " << dice.down << "\n";
	cout << "\n";
}

int main() {
	freopen("Text.txt", "r", stdin);
	cin >> n >> m >> sx >> sy >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	DICE dice;
	dice.x = sx;
	dice.y = sy;
	dice.back = 0;
	dice.left = 0;
	dice.up = 0;
	dice.right = 0;
	dice.front = 0;
	dice.down = 0;
	int nx = sx;
	int ny = sy;
	for (int i = 0; i < k; i++) {
		int move; cin >> move;
		nx += dir[move][0];
		ny += dir[move][1];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) { 
			nx -= dir[move][0];
			ny -= dir[move][1];
			continue; 
		}
		dice = moveDice(dice, move);

		if (map[nx][ny] == 0) {
			map[nx][ny] = dice.down;
		}
		else if (map[nx][ny] != 0) {
			dice.down = map[nx][ny];
			map[nx][ny] = 0;
		}
		cout << dice.up << "\n";
	}
	return 0;
}