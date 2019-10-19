#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
char map[51][51];
int sx, sy;
int ex, ey;
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int dist[1 << 6][51][51];
int total = 0;

struct NODE {
	int x, y;
	int item;
	int move;
};

void input() {
	cin >> m >> n;
	int numbering = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'X') {
				map[i][j] = 'a' + numbering++;
				total |= (1 << int(map[i][j] - 'a'));
			}
			if (map[i][j] == 'S') {
				sx = i; sy = j;
			}
			if (map[i][j] == 'E') {
				ex = i; ey = j;
			}
		}
	}
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)return false;
	return true;
}

void init() {
	for (int i = 0; i < (1 << 6); i++) {
		for (int j = 0; j < 51; j++) {
			for (int k = 0; k < 51; k++) {
				dist[i][j][k] = 1e9;
			}
		}
	}
	dist[0][sx][sy] = 0;
}

void solution() {
	init();
	queue<NODE>q;
	q.push({ sx,sy,0,0 });
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int ci = q.front().item;
		int cm = q.front().move;
		q.pop();
		if (cx == ex && cy == ey) {
			if (ci == total) {
				cout << cm << "\n";
			}
		}
		for (int d = 0; d < 4; d++) {
			int nx = cx + dir[d][0];
			int ny = cy + dir[d][1];
			if (!inside(nx, ny))continue;
			if (map[nx][ny] == '#')continue;
			if (map[nx][ny] == '.' || map[nx][ny] == 'E' || map[nx][ny] == 'S') {
				if (dist[ci][nx][ny] > dist[ci][cx][cy] + 1) {
					dist[ci][nx][ny] = dist[ci][cx][cy] + 1;
					q.push({ nx,ny,ci,cm + 1 });
				}
			}
			if ('a' <= map[nx][ny] && map[nx][ny] <= 'z') {
				int new_item = (1 << int(map[nx][ny] - 'a'));
				int ni = ci | new_item;
				if (dist[ni][nx][ny] > dist[ci][cx][cy] + 1) {
					dist[ni][nx][ny] = dist[ci][cx][cy] + 1;
					dist[ci][nx][ny] = dist[ci][cx][cy] + 1;
					q.push({ nx,ny,ni,cm + 1 });
				}
			}
		}
	}
}

void solve() {
	input();
	solution();
}

int main() {
	freopen("Text.txt", "r", stdin);
	solve();
	return 0;
}