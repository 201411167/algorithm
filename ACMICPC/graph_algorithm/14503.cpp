#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct NODE {
	int x, y;
	int d;
};
int n, m;
int sx, sy, sd;
int map[51][51];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

bool inside(int x, int y) { if (x < 0 || y < 0 || x >= n || y >= m)return false; return true; }

int answer = 0;
void dfs(int x, int y, int d) {
	if (map[x][y] == 0) {
		map[x][y] = 2;
		answer++;
	}
	int nx, ny, nd;
	nd = d;
	for (int i = 0; i < 4; i++) {
		nd = (nd + 3) % 4;
		nx = x + dir[nd][0];
		ny = y + dir[nd][1];
		if (!inside(nx, ny))continue;
		if (map[nx][ny] == 0) {
			dfs(nx, ny, nd);
			return;
		}
	}
	nx = x - dir[d][0];
	ny = y - dir[d][1];
	if (map[nx][ny] == 1)return;
	else dfs(nx, ny, d);
}

int main() {
	freopen("Text.txt", "r", stdin);
	cin >> n >> m;
	cin >> sx >> sy >> sd;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	dfs(sx,sy,sd);
	cout << answer;
}