#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int map[501][501];
bool visit[501][501];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = false;
		}
	}
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)return false;
	return true;
}

int answer = 0;
void dfs(int x, int y, int depth, int total) {
	if (depth == 4) {
		answer = max(answer, total);
		return;
	}
	for (int d = 0; d < 4; d++) {
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];
		if (!inside(nx, ny))continue;
		if (!visit[nx][ny]) {
			visit[x][y] = true;
			dfs(nx, ny, depth + 1, total + map[nx][ny]);
			visit[x][y] = false;
		}
	}
}

void explore(int x, int y) {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < m) {
		a = map[x][y] + map[x - 1][y] + map[x][y - 1] + map[x][y + 1];
	}
	if (y - 1 >= 0 && y + 1 < m && x + 1 < n) {
		b = map[x][y] + map[x][y - 1] + map[x][y + 1] + map[x + 1][y];
	}
	if (x - 1 >= 0 && y - 1 >= 0 && x + 1 < n) {
		c = map[x][y] + map[x - 1][y] + map[x][y - 1] + map[x + 1][y];
	}
	if (x - 1 >= 0 && y + 1 < m && x + 1 < n) {
		d = map[x][y] + map[x - 1][y] + map[x][y + 1] + map[x + 1][y];
	}
	answer = max(answer, max(a, max(b, max(c, d))));
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs(i, j, 1, map[i][j]);
			explore(i, j);
		}
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	solve();
	cout << answer;
	return 0;
}