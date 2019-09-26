#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct HOLE {
	int x1, y1;
	int x2, y2;
}holes[5];

int n;
int map[101][101];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };

void init() {
	for (int i = 0; i < 5; i++) {
		holes[i].x1 = -1;
		holes[i].y1 = -1;
		holes[i].x2 = -1;
		holes[i].y2 = -1;
	}
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (6 <= map[i][j] && map[i][j] <= 10) {
				if (holes[map[i][j] - 6].x1 == -1 && holes[map[i][j] - 6].y1 == -1) {
					holes[map[i][j] - 6].x1 = i;
					holes[map[i][j] - 6].y1 = j;
				}
				else {
					holes[map[i][j] - 6].x2 = i;
					holes[map[i][j] - 6].y2 = j;
				}
			}
		}
	}
}

int explore(int x, int y, int d) {
	int nx = x;
	int ny = y;
	int nd = d;
	int ret = 0;
	while (1) {
		nx += dir[nd][0];
		ny += dir[nd][1];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
			nx -= dir[nd][0];
			ny -= dir[nd][1];
			if (nx == 0 && nd == 0) {
				nd = 2;
			}
			if (ny == 0 && nd == 1) {
				nd = 3;
			}
			if (nx == n - 1 && nd == 2) {
				nd = 0;
			}
			if (ny == n - 1 && nd == 3) {
				nd = 1;
			}
			ret++;
		}
		if (map[nx][ny] == -1) {
			break;
		}
		if (nx == x && ny == y) {
			break;
		}
		if (1 <= map[nx][ny] && map[nx][ny] <= 5) {
			ret++;
			if (nd == 0) {
				if (map[nx][ny] == 1 || map[nx][ny] == 4 || map[nx][ny] == 5) {
					nd = 2;
				}
				if (map[nx][ny] == 2) {
					nd = 3;
				}
				if (map[nx][ny] == 3) {
					nd = 1;
				}
			}
			else if (nd == 1) {
				if (map[nx][ny] == 3 || map[nx][ny] == 4 || map[nx][ny] == 5) {
					nd = 3;
				}
				if (map[nx][ny] == 1) {
					nd = 0;
				}
				if (map[nx][ny] == 2) {
					nd = 2;
				}
			}
			else if (nd == 2) {
				if (map[nx][ny] == 2 || map[nx][ny] == 3 || map[nx][ny] == 5) {
					nd = 0;
				}
				if (map[nx][ny] == 1) {
					nd = 3;
				}
				if (map[nx][ny] == 4) {
					nd = 1;
				}
			}
			else  {
				if (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 5) {
					nd = 1;
				}
				if (map[nx][ny] == 3) {
					nd = 2;
				}
				if (map[nx][ny] == 4) {
					nd = 0;
				}
			}
		}
		if (6 <= map[nx][ny] && map[nx][ny] <= 10) {
			int num = map[nx][ny] - 6;
			int x1 = holes[num].x1;
			int y1 = holes[num].y1;
			int x2 = holes[num].x2;
			int y2 = holes[num].y2;
			if (nx == x1 && ny == y1) {
				nx = x2; ny = y2;
			}
			else {
				nx = x1; ny = y1;
			}
		}
	}
	return ret;
}

int main() {
	freopen("Text.txt", "r", stdin);
	int testCase; cin >> testCase;
	for (int idx = 1; idx <= testCase; idx++) {
		init();
		input();
		int answer = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 0) {
					for (int d = 0; d < 4; d++) {
						int tmp = explore(i, j, d);
						answer = max(answer, tmp);
					}
				}
			}
		}
		cout << "#" << idx << " ";
		cout << answer << "\n";
	}
}