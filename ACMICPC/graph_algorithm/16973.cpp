#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct RECT {
	int x1, y1;
	int x2, y2;
};

int n, m;
int map[1001][1001];
int dijk[1001][1001];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int h, w, x, y, gx, gy;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	cin >> h >> w >> x >> y >> gx >> gy;
}

bool inside(int x1, int y1, int x2, int y2) {
	if (x1 < 0 || y1 < 0 || x2 >= n || y2 >= m)return false;
	return true;
}

bool able_to_pass(int x1, int y1, int x2, int y2, int d) {
	if (d == 0) {
		if (!inside(x1 - 1, y1, x2 - 1, y2))return false;
		for (int i = y1; i <= y2; i++) {
			if (map[x1 - 1][i] == 1)return false;
		}
	}
	if (d == 1) {
		if (!inside(x1, y1 - 1, x2, y2 - 1))return false;
		for (int i = x1; i <= x2; i++) {
			if (map[i][y1 - 1] == 1)return false;
		}
	}
	if (d == 2) {
		if (!inside(x1 + 1, y1, x2 + 1, y2))return false;
		for (int i = y1; i <= y2; i++) {
			if (map[x2 + 1][i] == 1)return false;
		}
	}
	if (d == 3) {
		if (!inside(x1, y1 + 1, x2, y2 + 1))return false;
		for (int i = x1; i <= x2; i++) {
			if (map[i][y2 + 1] == 1)return false;
		}
	}
	return true;
}

void bfs() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dijk[i][j] = 1e9;
		}
	}
	dijk[x - 1][y - 1] = 0;
	queue<RECT>q;
	q.push({ x - 1,y - 1,x + h - 2,y + w - 2 });
	while (!q.empty()) {
		int cx1 = q.front().x1;
		int cy1 = q.front().y1;
		int cx2 = q.front().x2;
		int cy2 = q.front().y2;
		q.pop();
		for (int d = 0; d < 4; d++) {
			if (!able_to_pass(cx1, cy1, cx2, cy2, d))continue;
			int nx1 = cx1 + dir[d][0];
			int ny1 = cy1 + dir[d][1];
			int nx2 = cx2 + dir[d][0];
			int ny2 = cy2 + dir[d][1];
			if (dijk[nx1][ny1] > dijk[cx1][cy1] + 1) {
				dijk[nx1][ny1] = dijk[cx1][cy1] + 1;
				q.push({ nx1,ny1,nx2,ny2 });
			}
		}
	}
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	freopen("Text.txt", "r", stdin);
	input();
	bfs();
	int answer = dijk[gx - 1][gy - 1];
	if (answer == 1e9) {
		cout << -1;
	}
	else {
		cout << answer;
	}
	return 0;
}