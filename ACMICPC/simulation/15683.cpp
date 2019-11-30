#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int map[10][10];
int wall = 0;

int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };

int total = 0;
struct CCTV {
	int x, y;
	int type;
} cctvs[10];

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (1 <= map[i][j] && map[i][j] <= 5) {
				cctvs[++total] = { i,j,map[i][j] };
			}
			if (map[i][j] == 6) {
				wall++;
			}
		}
	}
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)return false;
	return true;
}

int sightScope[10];
bool visit[10][10];
int maxAnswer = 0;
void dfs(int index, int way, int total) {
	if (index == total) {
		memset(visit, false, sizeof(visit));
		for (int i = 1; i < 10; i++) {
			if (sightScope[i] != -1) {
				
				int type = cctvs[i].type;
				int x = cctvs[i].x;
				int y = cctvs[i].y;
				int d = sightScope[i];

				if (type == 1) {
					int nx = x;
					int ny = y;
					while (1) {
						if (map[nx][ny] == 6 || !inside(nx, ny)) {
							break;
						}
						visit[nx][ny] = true;
						nx += dir[d][0];
						ny += dir[d][1];
					}
				}
				if (type == 2) {
					int nx = x;
					int ny = y;
					while (1) {
						if (map[nx][ny] == 6 || !inside(nx, ny)) {
							break;
						}
						visit[nx][ny] = true;
						nx += dir[d][0];
						ny += dir[d][1];
					}
					nx = x;
					ny = y;
					while (1) {
						if (map[nx][ny] == 6 || !inside(nx, ny)) {
							break;
						}
						visit[nx][ny] = true;
						nx += dir[(d + 2) % 4][0];
						ny += dir[(d + 2) % 4][1];
					}
				}
				if (type == 3) {
					int nx = x;
					int ny = y;
					while (1) {
						if (map[nx][ny] == 6 || !inside(nx, ny)) {
							break;
						}
						visit[nx][ny] = true;
						nx += dir[d][0];
						ny += dir[d][1];
					}
					nx = x;
					ny = y;
					while (1) {
						if (map[nx][ny] == 6 || !inside(nx, ny)) {
							break;
						}
						visit[nx][ny] = true;
						nx += dir[(d + 1) % 4][0];
						ny += dir[(d + 1) % 4][1];
					}
				}
				if (type == 4) {
					int nx = x;
					int ny = y;
					while (1) {
						if (map[nx][ny] == 6 || !inside(nx, ny)) {
							break;
						}
						visit[nx][ny] = true;
						nx += dir[d][0];
						ny += dir[d][1];
					}
					nx = x;
					ny = y;
					while (1) {
						if (map[nx][ny] == 6 || !inside(nx, ny)) {
							break;
						}
						visit[nx][ny] = true;
						nx += dir[(d + 1) % 4][0];
						ny += dir[(d + 1) % 4][1];
					}
					nx = x;
					ny = y;
					while (1) {
						if (map[nx][ny] == 6 || !inside(nx, ny)) {
							break;
						}
						visit[nx][ny] = true;
						nx += dir[(d + 2) % 4][0];
						ny += dir[(d + 2) % 4][1];
					}
				}
				if (type == 5) {
					int nx = x;
					int ny = y;
					while (1) {
						if (map[nx][ny] == 6 || !inside(nx, ny)) {
							break;
						}
						visit[nx][ny] = true;
						nx += dir[0][0];
						ny += dir[0][1];
					}
					nx = x;
					ny = y;
					while (1) {
						if (map[nx][ny] == 6 || !inside(nx, ny)) {
							break;
						}
						visit[nx][ny] = true;
						nx += dir[1][0];
						ny += dir[1][1];
					}
					nx = x;
					ny = y;
					while (1) {
						if (map[nx][ny] == 6 || !inside(nx, ny)) {
							break;
						}
						visit[nx][ny] = true;
						nx += dir[2][0];
						ny += dir[2][1];
					}
					nx = x;
					ny = y;
					while (1) {
						if (map[nx][ny] == 6 || !inside(nx, ny)) {
							break;
						}
						visit[nx][ny] = true;
						nx += dir[3][0];
						ny += dir[3][1];
					}
				}
			}
		}
		int answer = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visit[i][j]) {
					answer++;
				}
			}
		}
		maxAnswer = max(answer, maxAnswer);
	}
	else {
		int type = cctvs[index].type;
		int x = cctvs[index].x;
		int y = cctvs[index].y;

		for (int d = 0; d < 4; d++) {
			sightScope[index + 1] = d;
			dfs(index + 1, d, total);
			sightScope[index + 1] = -1;
		}
	}
}

void solve() {
	memset(sightScope, -1, sizeof(sightScope));
	dfs(0, 0, total);
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	solve();
	cout << n * m - maxAnswer - wall;
	return 0;
}