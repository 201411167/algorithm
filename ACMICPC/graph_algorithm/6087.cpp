#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
char map[101][101];
bool visit[101][101][4];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int sx, sy;

typedef struct NODE {
	int x, y;
	int d;
	int cnt;
}LIGHT;

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)return false;
	return true;
}

void input() {
	int C = 0;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'C') {
				map[i][j] = 'A' + C++;
				if (map[i][j] == 'A') {
					sx = i; sy = j;
				}
			}
		}
	}
}

int bfs() {
	int ret = 1e9;
	queue<LIGHT> q;
	LIGHT start;
	start.x = sx; start.y = sy; start.cnt = 0;
	for (int i = 0; i < 4; i++) {
		int x = sx + dir[i][0];
		int y = sy + dir[i][1];
		if (!inside(x, y))continue;
		if (map[x][y] != '*') {
			start.d = i;
			visit[start.x][start.y][start.d] = true;
			q.push(start);
		}
	}
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cd = q.front().d;
		int cc = q.front().cnt;
		q.pop();
		if (map[cx][cy] == 'B') {
			ret = min(ret, cc);
		}
		int nx = cx;
		int ny = cy;
		while (1) {
			nx += dir[cd][0];
			ny += dir[cd][1];
			if (!inside(nx, ny)) {
				nx -= dir[cd][0];
				ny -= dir[cd][1];
				break;
			}
			if (map[nx][ny] == '*') {
				nx -= dir[cd][0];
				ny -= dir[cd][1];
				break;
			}
			for (int i = 0; i < 3; i++) {
				if (i == 0) {
					int nd = cd;
					int nc = cc;
					if (!visit[nx][ny][nd]) {
						visit[nx][ny][nd] = true;
						LIGHT nxt;
						nxt.x = nx; nxt.y = ny; nxt.d = nd; nxt.cnt = nc;
						q.push(nxt);
					}
				}
				if (i == 1) {
					int nd = (cd + 1) % 4;
					int nc = cc + 1;
					if (!visit[nx][ny][nd]) {
						visit[nx][ny][nd] = true;
						LIGHT nxt;
						nxt.x = nx; nxt.y = ny; nxt.d = nd; nxt.cnt = nc;
						q.push(nxt);
					}
				}
				if (i == 2) {
					int nd = (cd + 3) % 4;
					int nc = cc + 1;
					if (!visit[nx][ny][nd]) {
						visit[nx][ny][nd] = true;
						LIGHT nxt;
						nxt.x = nx; nxt.y = ny; nxt.d = nd; nxt.cnt = nc;
						q.push(nxt);
					}
				}
			}
		}
	}
	return ret;
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	freopen("Text.txt", "r", stdin);
	input();
	cout << bfs();
}