#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

#define pii pair<int,int>
int n;
int map[101][101];
bool visit[101][101];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int min_value;
int max_value;

void input() {
	min_value = 1e9;
	max_value = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			min_value = min(min_value, map[i][j]);
			max_value = max(max_value, map[i][j]);
		}
	}
}

bool inside(int x, int y) { if (x < 0 || y < 0 || x >= n || y >= n)return false; return true; }

bool bfs(int diff) {
	queue<pii>q;
	for (int k = min_value; k <= max_value; k++) {
		memset(visit, true, sizeof(visit));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (k <= map[i][j] && map[i][j] <= k + diff) { visit[i][j] = false; }
			}
		}
		if (visit[0][0])continue;
		visit[0][0] = true;
		q.push({ 0,0 });
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == n - 1 && y == n - 1)return true;
			for (int d = 0; d < 4; d++) {
				int nx = x + dir[d][0];
				int ny = y + dir[d][1];
				if (!inside(nx, ny))continue;
				if (!visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
	return false;
}

int solve() {
	int s = 0;
	int e = max_value - min_value;
	int m;
	while (s <= e) {
		m = (s + e) / 2;
		if (bfs(m))e = m - 1;
		else s = m + 1;
	}
	return e + 1;
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	cout << solve();
	return 0;
}