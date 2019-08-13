#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int n, m;
int sx, sy;
int gx, gy;
int dist[201][201];

void input() {
	cin >> n;
	cin >> sx >> sy >> gx >> gy;
}

bool inside(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n)return false;
	return true;
}

void bfs() {
	int dir[6][2] = { {-2,-1},{-2,1},{0,-2},{0,2},{2,-1},{2,1} };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = 1e9;
		}
	}
	dist[sx][sy] = 0;
	queue<pii>q;
	q.push({ sx,sy });
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int d = 0; d < 6; d++) {
			int nx = cx + dir[d][0];
			int ny = cy + dir[d][1];
			if (!inside(nx, ny))continue;
			if (dist[nx][ny] > dist[cx][cy] + 1) {
				dist[nx][ny] = dist[cx][cy] + 1;
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	bfs();
	int ans = dist[gx][gy];
	if (ans == 1e9) {
		cout << -1;
	}
	else {
		cout << ans;
	}
	return 0;
}