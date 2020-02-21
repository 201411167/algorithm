#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int testCase;
int n;

// 1 : white 
// 2 : yellow
// 3 : red
// 4 : orange
// 5 : green
// 6 : blue

int UP[3][3];
int DOWN[3][3];
int FRONT[3][3];
int BACK[3][3];
int LEFT[3][3];
int RIGHT[3][3];

void init() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			UP[i][j] = 1;
			DOWN[i][j] = 2;
			FRONT[i][j] = 3;
			BACK[i][j] = 4;
			LEFT[i][j] = 5;
			RIGHT[i][j] = 6;
		}
	}
}

void print_UP() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (UP[i][j] == 1) { cout << 'w'; }
			if (UP[i][j] == 2) { cout << 'y'; }
			if (UP[i][j] == 3) { cout << 'r'; }
			if (UP[i][j] == 4) { cout << 'o'; }
			if (UP[i][j] == 5) { cout << 'g'; }
			if (UP[i][j] == 6) { cout << 'b'; }
		}
		cout << "\n";
	}
}

queue<string>command_q;
void solve() {
	while (!command_q.empty()) {
		string cur = command_q.front();
		command_q.pop();
		char face = cur[0];
		char rotate = cur[1];
		if (face == 'U') {
			if (rotate == '+') {
				int TMP[3][3];
				TMP[0][0] = UP[2][0];
				TMP[0][1] = UP[1][0];
				TMP[0][2] = UP[0][0];
				TMP[1][0] = UP[2][1];
				TMP[1][1] = UP[1][1];
				TMP[1][2] = UP[0][1];
				TMP[2][0] = UP[2][2];
				TMP[2][1] = UP[1][2];
				TMP[2][2] = UP[0][2];
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						UP[i][j] = TMP[i][j];
					}
				}
				int a = BACK[2][0];
				int b = BACK[2][1];
				int c = BACK[2][2];
				BACK[2][0] = LEFT[2][2];
				BACK[2][1] = LEFT[1][2];
				BACK[2][2] = LEFT[0][2];
				LEFT[2][2] = FRONT[0][2];
				LEFT[1][2] = FRONT[0][1];
				LEFT[0][2] = FRONT[0][0];
				FRONT[0][2] = RIGHT[0][0];
				FRONT[0][1] = RIGHT[1][0];
				FRONT[0][0] = RIGHT[2][0];
				RIGHT[0][0] = a;
				RIGHT[1][0] = b;
				RIGHT[2][0] = c;
			}
			if (rotate == '-') {
				int TMP[3][3];
				TMP[0][0] = UP[0][2];
				TMP[0][1] = UP[1][2];
				TMP[0][2] = UP[2][2];
				TMP[1][0] = UP[0][1];
				TMP[1][1] = UP[1][1];
				TMP[1][2] = UP[2][1];
				TMP[2][0] = UP[0][0];
				TMP[2][1] = UP[1][0];
				TMP[2][2] = UP[2][0];
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						UP[i][j] = TMP[i][j];
					}
				}
				int a = BACK[2][0];
				int b = BACK[2][1];
				int c = BACK[2][2];
				BACK[2][0] = RIGHT[0][0];
				BACK[2][1] = RIGHT[1][0];
				BACK[2][2] = RIGHT[2][0];
				RIGHT[0][0] = FRONT[0][2];
				RIGHT[1][0] = FRONT[0][1];
				RIGHT[2][0] = FRONT[0][0];
				FRONT[0][2] = LEFT[2][2];
				FRONT[0][1] = LEFT[1][2];
				FRONT[0][0] = LEFT[0][2];
				LEFT[2][2] = a;
				LEFT[1][2] = b;
				LEFT[0][2] = c;
			}
		}
		if (face == 'D') {
			if (rotate == '+') {
				int TMP[3][3];
				TMP[0][0] = DOWN[2][0];
				TMP[0][1] = DOWN[1][0];
				TMP[0][2] = DOWN[0][0];
				TMP[1][0] = DOWN[2][1];
				TMP[1][1] = DOWN[1][1];
				TMP[1][2] = DOWN[0][1];
				TMP[2][0] = DOWN[2][2];
				TMP[2][1] = DOWN[1][2];
				TMP[2][2] = DOWN[0][2];
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						DOWN[i][j] = TMP[i][j];
					}
				}
				int a = FRONT[2][0];
				int b = FRONT[2][1];
				int c = FRONT[2][2];
				FRONT[2][0] = LEFT[0][0];
				FRONT[2][1] = LEFT[1][0];
				FRONT[2][2] = LEFT[2][0];
				LEFT[0][0] = BACK[0][2];
				LEFT[1][0] = BACK[0][1];
				LEFT[2][0] = BACK[0][0];
				BACK[0][2] = RIGHT[2][2];
				BACK[0][1] = RIGHT[1][2];
				BACK[0][0] = RIGHT[0][2];
				RIGHT[2][2] = a;
				RIGHT[1][2] = b;
				RIGHT[0][2] = c;

			}
			if (rotate == '-') {
				int TMP[3][3];
				TMP[0][0] = DOWN[0][2];
				TMP[0][1] = DOWN[1][2];
				TMP[0][2] = DOWN[2][2];
				TMP[1][0] = DOWN[0][1];
				TMP[1][1] = DOWN[1][1];
				TMP[1][2] = DOWN[2][1];
				TMP[2][0] = DOWN[0][0];
				TMP[2][1] = DOWN[1][0];
				TMP[2][2] = DOWN[2][0];
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						DOWN[i][j] = TMP[i][j];
					}
				}
				int a = FRONT[2][0];
				int b = FRONT[2][1];
				int c = FRONT[2][2];
				FRONT[2][0] = RIGHT[2][2];
				FRONT[2][1] = RIGHT[1][2];
				FRONT[2][2] = RIGHT[0][2];
				RIGHT[2][2] = BACK[0][2];
				RIGHT[1][2] = BACK[0][1];
				RIGHT[0][2] = BACK[0][0];
				BACK[0][2] = LEFT[0][0];
				BACK[0][1] = LEFT[1][0];
				BACK[0][0] = LEFT[2][0];
				LEFT[0][0] = a;
				LEFT[1][0] = b;
				LEFT[2][0] = c;
			}
		}
		if (face == 'F') {
			if (rotate == '+') {
				int TMP[3][3];
				TMP[0][0] = FRONT[2][0];
				TMP[0][1] = FRONT[1][0];
				TMP[0][2] = FRONT[0][0];
				TMP[1][0] = FRONT[2][1];
				TMP[1][1] = FRONT[1][1];
				TMP[1][2] = FRONT[0][1];
				TMP[2][0] = FRONT[2][2];
				TMP[2][1] = FRONT[1][2];
				TMP[2][2] = FRONT[0][2];
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						FRONT[i][j] = TMP[i][j];
					}
				}
				int a = UP[2][0];
				int b = UP[2][1];
				int c = UP[2][2];
				UP[2][0] = LEFT[2][0];
				UP[2][1] = LEFT[2][1];
				UP[2][2] = LEFT[2][2];
				LEFT[2][0] = DOWN[0][2];
				LEFT[2][1] = DOWN[0][1];
				LEFT[2][2] = DOWN[0][0];
				DOWN[0][2] = RIGHT[2][0];
				DOWN[0][1] = RIGHT[2][1];
				DOWN[0][0] = RIGHT[2][2];
				RIGHT[2][0] = a;
				RIGHT[2][1] = b;
				RIGHT[2][2] = c;
			}
			if (rotate == '-') {
				int TMP[3][3];
				TMP[0][0] = FRONT[0][2];
				TMP[0][1] = FRONT[1][2];
				TMP[0][2] = FRONT[2][2];
				TMP[1][0] = FRONT[0][1];
				TMP[1][1] = FRONT[1][1];
				TMP[1][2] = FRONT[2][1];
				TMP[2][0] = FRONT[0][0];
				TMP[2][1] = FRONT[1][0];
				TMP[2][2] = FRONT[2][0];
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						FRONT[i][j] = TMP[i][j];
					}
				}
				int a = UP[2][0];
				int b = UP[2][1];
				int c = UP[2][2];
				UP[2][0] = RIGHT[2][0];
				UP[2][1] = RIGHT[2][1];
				UP[2][2] = RIGHT[2][2];
				RIGHT[2][0] = DOWN[0][2];
				RIGHT[2][1] = DOWN[0][1];
				RIGHT[2][2] = DOWN[0][0];
				DOWN[0][2] = LEFT[2][0];
				DOWN[0][1] = LEFT[2][1];
				DOWN[0][0] = LEFT[2][2];
				LEFT[2][0] = a;
				LEFT[2][1] = b;
				LEFT[2][2] = c;
			}
		}
		if (face == 'B') {
			if (rotate == '+') {
				int TMP[3][3];
				TMP[0][0] = BACK[2][0];
				TMP[0][1] = BACK[1][0];
				TMP[0][2] = BACK[0][0];
				TMP[1][0] = BACK[2][1];
				TMP[1][1] = BACK[1][1];
				TMP[1][2] = BACK[0][1];
				TMP[2][0] = BACK[2][2];
				TMP[2][1] = BACK[1][2];
				TMP[2][2] = BACK[0][2];
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						BACK[i][j] = TMP[i][j];
					}
				}
				int a = DOWN[2][0];
				int b = DOWN[2][1];
				int c = DOWN[2][2];
				DOWN[2][0] = LEFT[0][2];
				DOWN[2][1] = LEFT[0][1];
				DOWN[2][2] = LEFT[0][0];
				LEFT[0][2] = UP[0][2];
				LEFT[0][1] = UP[0][1];
				LEFT[0][0] = UP[0][0];
				UP[0][2] = RIGHT[0][2];
				UP[0][1] = RIGHT[0][1];
				UP[0][0] = RIGHT[0][0];
				RIGHT[0][2] = a;
				RIGHT[0][1] = b;
				RIGHT[0][0] = c;
			}
			if (rotate == '-') {
				int TMP[3][3];
				TMP[0][0] = BACK[0][2];
				TMP[0][1] = BACK[1][2];
				TMP[0][2] = BACK[2][2];
				TMP[1][0] = BACK[0][1];
				TMP[1][1] = BACK[1][1];
				TMP[1][2] = BACK[2][1];
				TMP[2][0] = BACK[0][0];
				TMP[2][1] = BACK[1][0];
				TMP[2][2] = BACK[2][0];
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						BACK[i][j] = TMP[i][j];
					}
				}
				int a = DOWN[2][0];
				int b = DOWN[2][1];
				int c = DOWN[2][2];
				DOWN[2][0] = RIGHT[0][2];
				DOWN[2][1] = RIGHT[0][1];
				DOWN[2][2] = RIGHT[0][0];
				RIGHT[0][2] = UP[0][2];
				RIGHT[0][1] = UP[0][1];
				RIGHT[0][0] = UP[0][0];
				UP[0][2] = LEFT[0][2];
				UP[0][1] = LEFT[0][1];
				UP[0][0] = LEFT[0][0];
				LEFT[0][2] = a;
				LEFT[0][1] = b;
				LEFT[0][0] = c;
			}
		}
		if (face == 'L') {
			if (rotate == '+') {
				int TMP[3][3];
				TMP[0][0] = LEFT[2][0];
				TMP[0][1] = LEFT[1][0];
				TMP[0][2] = LEFT[0][0];
				TMP[1][0] = LEFT[2][1];
				TMP[1][1] = LEFT[1][1];
				TMP[1][2] = LEFT[0][1];
				TMP[2][0] = LEFT[2][2];
				TMP[2][1] = LEFT[1][2];
				TMP[2][2] = LEFT[0][2];
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						LEFT[i][j] = TMP[i][j];
					}
				}
				int a = BACK[0][0];
				int b = BACK[1][0];
				int c = BACK[2][0];
				BACK[0][0] = DOWN[0][0];
				BACK[1][0] = DOWN[1][0];
				BACK[2][0] = DOWN[2][0];
				DOWN[0][0] = FRONT[0][0];
				DOWN[1][0] = FRONT[1][0];
				DOWN[2][0] = FRONT[2][0];
				FRONT[0][0] = UP[0][0];
				FRONT[1][0] = UP[1][0];
				FRONT[2][0] = UP[2][0];
				UP[0][0] = a;
				UP[1][0] = b;
				UP[2][0] = c;
			}
			if (rotate == '-') {
				int TMP[3][3];
				TMP[0][0] = LEFT[0][2];
				TMP[0][1] = LEFT[1][2];
				TMP[0][2] = LEFT[2][2];
				TMP[1][0] = LEFT[0][1];
				TMP[1][1] = LEFT[1][1];
				TMP[1][2] = LEFT[2][1];
				TMP[2][0] = LEFT[0][0];
				TMP[2][1] = LEFT[1][0];
				TMP[2][2] = LEFT[2][0];
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						LEFT[i][j] = TMP[i][j];
					}
				}
				int a = BACK[0][0];
				int b = BACK[1][0];
				int c = BACK[2][0];
				BACK[0][0] = UP[0][0];
				BACK[1][0] = UP[1][0];
				BACK[2][0] = UP[2][0];
				UP[0][0] = FRONT[0][0];
				UP[1][0] = FRONT[1][0];
				UP[2][0] = FRONT[2][0];
				FRONT[0][0] = DOWN[0][0];
				FRONT[1][0] = DOWN[1][0];
				FRONT[2][0] = DOWN[2][0];
				DOWN[0][0] = a;
				DOWN[1][0] = b;
				DOWN[2][0] = c;
			}
		}
		if (face == 'R') {
			if (rotate == '+') {
				int TMP[3][3];
				TMP[0][0] = RIGHT[2][0];
				TMP[0][1] = RIGHT[1][0];
				TMP[0][2] = RIGHT[0][0];
				TMP[1][0] = RIGHT[2][1];
				TMP[1][1] = RIGHT[1][1];
				TMP[1][2] = RIGHT[0][1];
				TMP[2][0] = RIGHT[2][2];
				TMP[2][1] = RIGHT[1][2];
				TMP[2][2] = RIGHT[0][2];
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						RIGHT[i][j] = TMP[i][j];
					}
				}
				int a = BACK[2][2];
				int b = BACK[1][2];
				int c = BACK[0][2];
				BACK[2][2] = UP[2][2];
				BACK[1][2] = UP[1][2];
				BACK[0][2] = UP[0][2];
				UP[2][2] = FRONT[2][2];
				UP[1][2] = FRONT[1][2];
				UP[0][2] = FRONT[0][2];
				FRONT[2][2] = DOWN[2][2];
				FRONT[1][2] = DOWN[1][2];
				FRONT[0][2] = DOWN[0][2];
				DOWN[2][2] = a;
				DOWN[1][2] = b;
				DOWN[0][2] = c;
			}
			if (rotate == '-') {
				int TMP[3][3];
				TMP[0][0] = RIGHT[0][2];
				TMP[0][1] = RIGHT[1][2];
				TMP[0][2] = RIGHT[2][2];
				TMP[1][0] = RIGHT[0][1];
				TMP[1][1] = RIGHT[1][1];
				TMP[1][2] = RIGHT[2][1];
				TMP[2][0] = RIGHT[0][0];
				TMP[2][1] = RIGHT[1][0];
				TMP[2][2] = RIGHT[2][0];
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						RIGHT[i][j] = TMP[i][j];
					}
				}
				int a = BACK[2][2];
				int b = BACK[1][2];
				int c = BACK[0][2];
				BACK[2][2] = DOWN[2][2];
				BACK[1][2] = DOWN[1][2];
				BACK[0][2] = DOWN[0][2];
				DOWN[2][2] = FRONT[2][2];
				DOWN[1][2] = FRONT[1][2];
				DOWN[0][2] = FRONT[0][2];
				FRONT[2][2] = UP[2][2];
				FRONT[1][2] = UP[1][2];
				FRONT[0][2] = UP[0][2];
				UP[2][2] = a;
				UP[1][2] = b;
				UP[0][2] = c;
			}
		}
	}
}

void input() {
	cin >> testCase;
	while (testCase--) {
		init();
		cin >> n;
		for (int i = 0; i < n; i++) {
			string command; cin >> command;
			command_q.push(command);
		}
		solve();
		print_UP();
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	return 0;
}