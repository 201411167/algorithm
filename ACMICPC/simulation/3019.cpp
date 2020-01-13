#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int tetris_type[7] = { 1,2,3,4,5,6,7 };
int c, p;
int map[110][110];
queue<pair<int, int>>starting_level;

void show() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void input() {
	cin >> c >> p;
	for (int j = 0; j < c; j++) {
		int r; cin >> r;
		starting_level.push({ r,j });
		for (int i = 0; i < r; i++) {
			map[i][j] = 1;
		}
	}
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= 110 || y >= c) { return false; }
	else { return true; }
}

int explore(int x, int y, int block_type) {
	if (block_type == 1) {
		int ret = 0;
		for (int i = 0; i < 2; i++) {
			if (i == 0) { // び
				if (!inside(x, y) || !inside(x + 1, y) || !inside(x + 2, y) || !inside(x + 3, y))continue;
				if (map[x][y] == 1 || map[x + 1][y] == 1 || map[x + 2][y] == 1 || map[x + 3][y] == 1)continue;
				map[x][y] = 1; map[x + 1][y] = 1; map[x + 2][y] = 1; map[x + 3][y] = 1;
				bool possible = true;
				for (int j = x; j >= 0; j--) {
					if (map[j][y] == 0) {
						possible = false;
					}
				}
				if (possible)ret++;
				map[x][y] = 0; map[x + 1][y] = 0; map[x + 2][y] = 0; map[x + 3][y] = 0;
			}
			if (i == 1) { // ぱ
				if (!inside(x, y) || !inside(x, y + 1) || !inside(x, y + 2) || !inside(x, y + 3))continue;
				if (map[x][y] == 1 || map[x][y + 1] == 1 || map[x][y + 2] == 1 || map[x][y + 3] == 1)continue;
				map[x][y] = 1; map[x][y + 1] = 1; map[x][y + 2] = 1; map[x][y + 3] = 1;
				bool possible = true;
				for (int j = x; j >= 0; j--) {
					if (map[j][y] == 0 || map[j][y + 1] == 0 || map[j][y + 2] == 0 || map[j][y + 3] == 0) {
						possible = false;
					}
				}
				if (possible)ret++;
				map[x][y] = 0; map[x][y + 1] = 0; map[x][y + 2] = 0; map[x][y + 3] = 0;
			}
		}
		return ret;
	}
	if (block_type == 2) {
		int ret = 0;
		for (int i = 0; i < 1; i++) {
			if (i == 0) { // け
				if (!inside(x, y) || !inside(x + 1, y) || !inside(x, y + 1) || !inside(x + 1, y + 1))continue;
				if (map[x][y] == 1 || map[x + 1][y] == 1 || map[x][y + 1] == 1 || map[x + 1][y + 1] == 1)continue;
				map[x][y] = 1; map[x + 1][y] = 1; map[x][y + 1] = 1; map[x + 1][y + 1] = 1;
				bool possible = true;
				for (int j = x; j >= 0; j--) {
					if (map[j][y] == 0 || map[j][y + 1] == 0) {
						possible = false;
					}
				}
				if (possible)ret++;
				map[x][y] = 0; map[x + 1][y] = 0; map[x][y + 1] = 0; map[x + 1][y + 1] = 0;
			}
		}
		return ret;
	}
	if (block_type == 4) {
		int ret = 0;
		for (int i = 0; i < 2; i++) {
			//  けけ
			//けけ
			if (i == 0) {
				if (!inside(x, y) || !inside(x, y + 1) || !inside(x + 1, y - 1) || !inside(x + 1, y))continue;
				if (map[x][y] == 1 || map[x][y + 1] == 1 || map[x + 1][y - 1] == 1 || map[x + 1][y] == 1)continue;
				map[x][y] = 1; map[x][y + 1] = 1; map[x + 1][y - 1] = 1; map[x + 1][y] = 1;
				bool possible = true;
				for (int j = x; j >= 0; j--) {
					if (map[j][y] == 0 || map[j][y + 1] == 0 || map[j][y - 1] == 0) {
						possible = false;
					}
				}
				if (possible)ret++;
				map[x][y] = 0; map[x][y + 1] = 0; map[x + 1][y - 1] = 0; map[x + 1][y] = 0;
			}
			//け
			//けけ
			//  け
			if (i == 1) {
				if (!inside(x, y) || !inside(x + 1, y) || !inside(x + 1, y + 1) || !inside(x + 2, y + 1))continue;
				if (map[x][y] == 1 || map[x + 1][y] == 1 || map[x + 1][y + 1] == 1 || map[x + 2][y + 1] == 1)continue;
				map[x][y] = 1; map[x + 1][y] = 1; map[x + 1][y + 1] = 1; map[x + 2][y + 1] = 1;
				bool possible = true;
				for (int j = x; j >= 0; j--) {
					if (map[j][y] == 0 || map[j][y + 1] == 0) {
						possible = false;
					}
				}
				if (possible)ret++;
				map[x][y] = 0; map[x + 1][y] = 0; map[x + 1][y + 1] = 0; map[x + 2][y + 1] = 0;
			}
		}
		return ret;
	}
	if (block_type == 3) {
		int ret = 0;
		for (int i = 0; i < 2; i++) {
			// けけ
			//   けけ
			if (i == 0) {
				if (!inside(x, y) || !inside(x, y + 1) || !inside(x + 1, y + 1) || !inside(x + 1, y + 2))continue;
				if (map[x][y] == 1 || map[x][y + 1] == 1 || map[x + 1][y + 1] == 1 || map[x + 1][y + 2] == 1)continue;
				map[x][y] = 1; map[x][y + 1] = 1; map[x + 1][y + 1] = 1; map[x + 1][y + 2] = 1;
				bool possible = true;
				for (int j = x; j >= 0; j--) {
					if (map[j][y] == 0 || map[j][y + 1] == 0 || map[j][y + 2] == 0) {
						possible = false;
					}
				}
				if (possible)ret++;
				map[x][y] = 0; map[x][y + 1] = 0; map[x + 1][y + 1] = 0; map[x + 1][y + 2] = 0;
			}
			//  け
			//けけ
			//け
			if (i == 1) {
				if (!inside(x, y) || !inside(x + 1, y - 1) || !inside(x + 1, y) || !inside(x + 2, y - 1))continue;
				if (map[x][y] == 1 || map[x + 1][y - 1] == 1 || map[x + 1][y] == 1 || map[x + 2][y - 1] == 1)continue;
				map[x][y] = 1; map[x + 1][y - 1] = 1; map[x + 1][y] = 1; map[x + 2][y - 1] = 1;
				bool possible = true;
				for (int j = x; j >= 0; j--) {
					if (map[j][y - 1] == 0 || map[j][y] == 0) {
						possible = false;
					}
				}
				if (possible)ret++;
				map[x][y] = 0; map[x + 1][y - 1] = 0; map[x + 1][y] = 0; map[x + 2][y - 1] = 0;
			}
		}
		return ret;
	}
	if (block_type == 5) {
		int ret = 0;
		for (int i = 0; i < 4; i++) {
			if (i == 0) { // た
				if (!inside(x, y) || !inside(x + 1, y) || !inside(x + 2, y) || !inside(x + 1, y + 1)) continue;
				if (map[x][y] == 1 || map[x + 1][y] == 1 || map[x + 2][y] == 1 || map[x + 1][y + 1] == 1) continue;
				map[x][y] = 1; map[x + 1][y] = 1; map[x + 2][y] = 1; map[x + 1][y + 1] = 1;
				bool possible = true;
				for (int j = x; j >= 0; j--) {
					if (map[j][y] == 0 || map[j][y + 1] == 0) {
						possible = false;
					}
				}
				if (possible)ret++;
				map[x][y] = 0; map[x + 1][y] = 0; map[x + 2][y] = 0; map[x + 1][y + 1] = 0;
			}
			if (i == 1) { // で
				if (!inside(x, y) || !inside(x + 1, y - 1) || !inside(x + 1, y) || !inside(x + 1, y + 1))continue;
				if (map[x][y] == 1 || map[x + 1][y - 1] == 1 || map[x + 1][y] == 1 || map[x + 1][y + 1] == 1)continue;
				map[x][y] = 1; map[x + 1][y - 1] = 1; map[x + 1][y] = 1; map[x + 1][y + 1] = 1;
				bool possible = true;
				for (int j = x; j >= 0; j--) {
					if (map[j][y] == 0 || map[j][y - 1] == 0 || map[j][y + 1] == 0) {
						possible = false;
					}
				}
				if (possible)ret++;
				map[x][y] = 0; map[x + 1][y - 1] = 0; map[x + 1][y] = 0; map[x + 1][y + 1] = 0;
			}
			if (i == 2) { // っ
				if (!inside(x, y) || !inside(x + 1, y - 1) || !inside(x + 1, y) || !inside(x + 2, y))continue;
				if (map[x][y] == 1 || map[x + 1][y - 1] == 1 || map[x + 1][y] == 1 || map[x + 2][y] == 1)continue;
				map[x][y] = 1; map[x + 1][y - 1] = 1; map[x + 1][y] = 1; map[x + 2][y] = 1;
				bool possible = true;
				for (int j = x; j >= 0; j--) {
					if (map[j][y] == 0 || map[j][y - 1] == 0) {
						possible = false;
					}
				}
				if (possible)ret++;
				map[x][y] = 0; map[x + 1][y - 1] = 0; map[x + 1][y] = 0; map[x + 2][y] = 0;
			}
			if (i == 3) { // ぬ
				if (!inside(x, y) || !inside(x, y - 1) || !inside(x, y + 1) || !inside(x + 1, y))continue;
				if (map[x][y] == 1 || map[x][y - 1] == 1 || map[x][y + 1] == 1 || map[x + 1][y] == 1)continue;
				map[x][y] = 1; map[x][y - 1] = 1; map[x][y + 1] = 1; map[x + 1][y] = 1;
				bool possible = true;
				for (int j = x; j >= 0; j--) {
					if (map[j][y] == 0 || map[j][y - 1] == 0 || map[j][y + 1] == 0) {
						possible = false;
					}
				}
				if (possible)ret++;
				map[x][y] = 0; map[x][y - 1] = 0; map[x][y + 1] = 0; map[x + 1][y] = 0;
			}
		}
		return ret;
	}
	if (block_type == 6) {
		int ret = 0;
		for (int i = 0; i < 4; i++) {
			//けけけ
			//    け
			if (i == 0) {
				if (!inside(x, y) || !inside(x, y + 1) || !inside(x, y + 2) || !inside(x + 1, y + 2))continue;
				if (map[x][y] == 1 || map[x][y + 1] == 1 || map[x][y + 2] == 1 || map[x + 1][y + 2] == 1)continue;
				map[x][y] = 1; map[x][y + 1] = 1; map[x][y + 2] = 1; map[x + 1][y + 2] = 1;
				bool possible = true;
				for (int j = x; j >= 0; j--) {
					if (map[j][y] == 0 || map[j][y + 1] == 0 || map[j][y + 2] == 0) {
						possible = false;
					}
				}
				if (possible)ret++;
				map[x][y] = 0; map[x][y + 1] = 0; map[x][y + 2] = 0; map[x + 1][y + 2] = 0;
			}
			//けけ
			//け
			//け
			if (i == 1) {
				if (!inside(x, y) || !inside(x, y + 1) || !inside(x + 1, y) || !inside(x + 2, y))continue;
				if (map[x][y] == 1 || map[x][y + 1] == 1 || map[x + 1][y] == 1 || map[x + 2][y] == 1)continue;
				map[x][y] = 1; map[x][y + 1] = 1; map[x + 1][y] = 1; map[x + 2][y] = 1;
				bool possible = true;
				for (int j = x; j >= 0; j--) {
					if (map[j][y] == 0 || map[j][y + 1] == 0) {
						possible = false;
					}
				}
				if (possible)ret++;
				map[x][y] = 0; map[x][y + 1] = 0; map[x + 1][y] = 0; map[x + 2][y] = 0;
			}
			//け
			//けけけ
			if (i == 2) {
				if (!inside(x, y) || !inside(x + 1, y) || !inside(x + 1, y + 1) || !inside(x + 1, y + 2))continue;
				if (map[x][y] == 1 || map[x + 1][y] == 1 || map[x + 1][y + 1] == 1 || map[x + 1][y + 2] == 1)continue;
				map[x][y] = 1; map[x + 1][y] = 1; map[x + 1][y + 1] = 1; map[x + 1][y + 2] = 1;
				bool possible = true;
				for (int j = x; j >= 0; j--) {
					if (map[j][y] == 0 || map[j][y + 1] == 0 || map[j][y + 2] == 0) {
						possible = false;
					}
				}
				if (possible)ret++;
				map[x][y] = 0; map[x + 1][y] = 0; map[x + 1][y + 1] = 0; map[x + 1][y + 2] = 0;
			}
			//  け
			//  け
			//けけ
			if (i == 3) {
				if (!inside(x, y) || !inside(x + 1, y) || !inside(x + 2, y - 1) || !inside(x + 2, y))continue;
				if (map[x][y] == 1 || map[x + 1][y] == 1 || map[x + 2][y - 1] == 1 || map[x + 2][y] == 1)continue;
				map[x][y] = 1; map[x + 1][y] = 1; map[x + 2][y - 1] = 1; map[x + 2][y] = 1;
				bool possible = true;
				for (int j = x; j >= 0; j--) {
					if (map[j][y - 1] == 0 || map[j][y] == 0 || map[j + 1][y - 1] == 00) {
						possible = false;
					}
				}
				if (possible)ret++;
				map[x][y] = 0; map[x + 1][y] = 0; map[x + 2][y - 1] = 0; map[x + 2][y] = 0;
			}
		}
		return ret;
	}
	if (block_type == 7) {
		int ret = 0;
		for (int i = 0; i < 4; i++) {
			//けけけ
			//け
			if (i == 0) {
				if (!inside(x, y) || !inside(x, y + 1) || !inside(x, y + 2) || !inside(x + 1, y))continue;
				if (map[x][y] == 1 || map[x][y + 1] == 1 || map[x][y + 2] == 1 || map[x + 1][y] == 1)continue;
				map[x][y] = 1; map[x][y + 1] = 1; map[x][y + 2] = 1; map[x + 1][y] = 1;
				bool possible = true;
				for (int j = x; j >= 0; j--) {
					if (map[j][y] == 0 || map[j][y + 1] == 0 || map[j][y + 2] == 0) {
						possible = false;
					}
				}
				if (possible)ret++;
				map[x][y] = 0; map[x][y + 1] = 0; map[x][y + 2] = 0; map[x + 1][y] = 0;
			}
			//け
			//け
			//けけ
			if (i == 1) {
				if (!inside(x, y) || !inside(x + 1, y) || !inside(x + 2, y) || !inside(x + 2, y + 1))continue;
				if (map[x][y] == 1 || map[x + 1][y] == 1 || map[x + 2][y] == 1 || map[x + 2][y + 1] == 1)continue;
				map[x][y] = 1; map[x + 1][y] = 1; map[x + 2][y] = 1; map[x + 2][y + 1] = 1;
				bool possible = true;
				for (int j = x; j >= 0; j--) {
					if (map[j][y] == 0 || map[j][y + 1] == 0 || map[j + 1][y + 1] == 0) {
						possible = false;
					}
				}
				if (possible)ret++;
				map[x][y] = 0; map[x + 1][y] = 0; map[x + 2][y] = 0; map[x + 2][y + 1] = 0;
			}
			//    け
			//けけけ
			if (i == 2) {
				if (!inside(x, y) || !inside(x + 1, y - 2) || !inside(x + 1, y - 1) || !inside(x + 1, y))continue;
				if (map[x][y] == 1 || map[x + 1][y - 2] == 1 || map[x + 1][y - 1] == 1 || map[x + 1][y] == 1)continue;
				map[x][y] = 1; map[x + 1][y - 2] = 1; map[x + 1][y - 1] = 1; map[x + 1][y] = 1;
				bool possible = true;
				for (int j = x; j >= 0; j--) {
					if (map[j][y - 2] == 0 || map[j][y - 1] == 0 || map[j][y] == 0) {
						possible = false;
					}
				}
				if (possible)ret++;
				map[x][y] = 0; map[x + 1][y - 2] = 0; map[x + 1][y - 1] = 0; map[x + 1][y] = 0;
			}
			//けけ
			//  け
			//  け
			if (i == 3) {
				if (!inside(x, y) || !inside(x, y + 1) || !inside(x + 1, y + 1) || !inside(x + 2, y + 1))continue;
				if (map[x][y] == 1 || map[x][y + 1] == 1 || map[x + 1][y + 1] == 1 || map[x + 2][y + 1] == 1)continue;
				map[x][y] = 1; map[x][y + 1] = 1; map[x + 1][y + 1] = 1; map[x + 2][y + 1] = 1;
				bool possible = true;
				for (int j = x; j >= 0; j--) {
					if (map[j][y] == 0 || map[j][y + 1] == 0) {
						possible = false;
					}
				}
				if (possible)ret++;
				map[x][y] = 0; map[x][y + 1] = 0; map[x + 1][y + 1] = 0; map[x + 2][y + 1] = 0;
			}
		}
		return ret;
	}
}

void solve() {
	int answer = 0;
	while (!starting_level.empty()) {
		int x = starting_level.front().first;
		int y = starting_level.front().second;
		starting_level.pop();
		answer += explore(x, y, p);
	}
	cout << answer;
}

int main() {
	freopen("text.txt", "r", stdin);
	input();
	solve();
	return 0;
}