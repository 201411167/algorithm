#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct NODE {
	int x, y;
	int d;
	int cnt;
};

int n, m;
char map[101][101];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int sx, sy;
bool visit[101][101][4];

void input() {
	cin >> m >> n;
	int door = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'C') {
				map[i][j] = 'A' + door++;
			}
			if (map[i][j] == 'A') {
				sx = i; sy = j;
			}
		}
	}
}

void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)return false;
	return true;
}

void bfs() {
	int answer = 1e9;
	queue<NODE>q;
	for (int d = 0; d < 4; d++) {
		int nx = sx + dir[d][0];
		int ny = sy + dir[d][1];
		if (!inside(nx, ny))continue;
		if (map[nx][ny] == '*')continue;
		if (!visit[sx][sy][d]) {
			visit[sx][sy][d];
			q.push({ sx,sy,d,0 });
		}
	}
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cd = q.front().d;
		int cc = q.front().cnt;
		q.pop();
		if (map[cx][cy] == 'B') {
			answer = min(answer, cc);
		}
		int nx = cx;
		int ny = cy;
		while (1) {
			nx += dir[cd][0];
			ny += dir[cd][1];
			if (!inside(nx, ny))break;
			if (map[nx][ny] == '*') {
				nx -= dir[cd][0];
				ny -= dir[cd][1];
				break;
			}
			if (map[nx][ny] == '.' || map[nx][ny] == 'B') {
				if (!visit[nx][ny][(cd + 1) % 4]) {
					visit[nx][ny][(cd + 1) % 4] = true;
					q.push({ nx,ny,(cd + 1) % 4,cc + 1 });
				}
				if (!visit[nx][ny][(cd + 3) % 4]) {
					visit[nx][ny][(cd + 3) % 4] = true;
					q.push({ nx,ny,(cd + 3) % 4,cc + 1 });
				}
				if (!visit[nx][ny][cd]) {
					visit[nx][ny][cd] = true;
					q.push({ nx,ny,cd,cc });
				}
			}
		}
	}
	cout << answer;
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	bfs();
	return 0;
}