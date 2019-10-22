#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
char map[51][51];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
bool visit[51][51];

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

bool inside(int x, int y) { 
	if (x < 0 || y < 0 || x >= n || y >= m) return false; 
	return true; 
}

bool result = false;
void  dfs(int sx, int sy, int x, int y, int cd, int dir_change) {
	if (x == sx && y == sy && dir_change >= 3) {
		result = true;
	}
	else {
		int nd, nx, ny, ndc;
		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				nd = cd;
				nx = x + dir[nd][0];
				ny = y + dir[nd][1];
				ndc = dir_change;
			}
			if (i == 1) {
				nd = (cd + 1) % 4;
				nx = x + dir[nd][0];
				ny = y + dir[nd][1];
				ndc = dir_change + 1;
			}
			if (i == 2) {
				nd = (cd + 3) % 4;
				nx = x + dir[nd][0];
				ny = y + dir[nd][1];
				ndc = dir_change + 1;
			}
			if (!inside(nx, ny))continue;
			if (map[nx][ny] != map[sx][sy])continue;
			if (!visit[nx][ny]) {
				visit[nx][ny] = true;
				dfs(sx, sy, nx, ny, nd, ndc);
				visit[nx][ny] = false;
			}
		}
	}
}

void solve() {
	input();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int d = 0; d < 4; d++) {
				int ni = i + dir[d][0];
				int nj = j + dir[d][1];
				if (!inside(ni, nj))continue;
				if (map[ni][nj] != map[i][j])continue;
				dfs(i, j, i, j, d, 0);
				if (result) break;
			}
			if (result)break;
		}
		if (result)break;
	}
	if (result) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}

int main() {
	freopen("text.txt", "r", stdin);
	solve();
	return 0;
}