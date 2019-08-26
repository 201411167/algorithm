#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int n, m;
int map[190][190];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
queue<pii>q;
int dijk[190][190];

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j] == 1) {
				q.push({ i,j });
				dijk[i][j] = 0;
			}
			if (map[i][j] == 0) {
				dijk[i][j] = 1e9;
			}
		}
	}
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)return false;
	return true;
}

void bfs() {
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = cx + dir[d][0];
			int ny = cy + dir[d][1];
			if (!inside(nx, ny))continue;
			if (map[nx][ny] == 0) {
				if (dijk[nx][ny] > dijk[cx][cy] + 1) {
					dijk[nx][ny] = dijk[cx][cy] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
}

void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dijk[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	bfs();
	show();
	return 0;
}