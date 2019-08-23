#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int n, m;
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int map[101][101];
int ans = 0;
bool visit[101][101];

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

void init_visit() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = false;
		}
	}
}

void bfs(int x, int y) {
	init_visit();
	int limit = map[x][y];
	int low = 1e9;
	bool leak = false;
	queue<pii>q;
	q.push({ x,y });
	visit[x][y] = true;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		if (cx == 0 || cy == 0 || cx == n - 1 || cy == m - 1) {
			leak = true;
			break;
		}
		for (int d = 0; d < 4; d++) {
			int nx = cx + dir[d][0];
			int ny = cy + dir[d][1];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
			if (map[nx][ny] <= limit && !visit[nx][ny]) {
				visit[nx][ny] = true;
				q.push({ nx,ny });
			}
			if (map[nx][ny] > limit) {
				low = min(low, map[nx][ny]);
			}
		}
	}
	if (!leak) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visit[i][j]) {
					ans += low - map[i][j];
					map[i][j] = low;
				}
			}
		}
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || j == 0 || i == n - 1 || j == m - 1)continue;
			bfs(i, j);
		}
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	solve();
	cout << ans;
	return 0;
}