#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int map[101][101];
int dist[101][101][5];
int dx[] = { 0, 0, 0, 1, -1};
int dy[] = { 0, 1, -1, 0, 0};

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)return false;
	return true;
}

struct INFO {
	int x, y;
	int dir;
};
INFO start, goal;

void bfs() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			for (int k = 0; k < 5; k++) {
				dist[i][j][k] = 1e9;
			}
		}
	}
	dist[start.x][start.y][start.dir] = 0;
	queue<INFO>q;
	q.push(start);
	while (!q.empty()) {
		INFO cur = q.front();
		q.pop();
		for (int i = 1; i <= 3; i++) { // distance
			int nx = cur.x + (dx[cur.dir] * i);
			int ny = cur.y + (dy[cur.dir] * i);
			if (!inside(nx, ny))continue;
			int nd = cur.dir;
			if (map[nx][ny] == 1) break;
			if (dist[nx][ny][nd] > dist[cur.x][cur.y][cur.dir] + 1) {
				dist[nx][ny][nd] = dist[cur.x][cur.y][cur.dir] + 1;
				INFO nxt;
				nxt.x = nx; nxt.y = ny; nxt.dir = nd;
				q.push(nxt);
			}
		}
		for (int i = 0; i < 2; i++) {
			if (i == 0) { // left : 1 -> 3 -> 2-> 4 -> 1
				int nx = cur.x;
				int ny = cur.y;
				int nd;
				if (cur.dir == 1) { nd = 3; }
				if (cur.dir == 2) { nd = 4; }
				if (cur.dir == 3) { nd = 2; }
				if (cur.dir == 4) { nd = 1; }
				if (dist[nx][ny][nd] > dist[cur.x][cur.y][cur.dir] + 1) {
					dist[nx][ny][nd] = dist[cur.x][cur.y][cur.dir] + 1;
					INFO nxt;
					nxt.x = nx; nxt.y = ny; nxt.dir = nd;
					q.push(nxt);
				}
			}
			if (i == 1) { // right : 1 -> 4 -> 2 -> 3 -> 1
				int nx = cur.x;
				int ny = cur.y;
				int nd;
				if (cur.dir == 1) { nd = 4; }
				if (cur.dir == 2) { nd = 3; }
				if (cur.dir == 3) { nd = 1; }
				if (cur.dir == 4) { nd = 2; }
				if (dist[nx][ny][nd] > dist[cur.x][cur.y][cur.dir] + 1) {
					dist[nx][ny][nd] = dist[cur.x][cur.y][cur.dir] + 1;
					INFO nxt;
					nxt.x = nx; nxt.y = ny; nxt.dir = nd;
					q.push(nxt);
				}
			}
		}
	}
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int sx, sy, sd;
	int gx, gy, gd;
	cin >> sx >> sy >> sd;
	cin >> gx >> gy >> gd;
	start.x = sx - 1; start.y = sy - 1; start.dir = sd;
	goal.x = gx - 1; goal.y = gy - 1; goal.dir = gd;
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	freopen("Text.txt", "r", stdin);

	input();
	bfs();
	cout << dist[goal.x][goal.y][goal.dir];
	return 0;
}