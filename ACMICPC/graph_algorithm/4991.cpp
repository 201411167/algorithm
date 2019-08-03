#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct NODE {
	int x, y;
	int dirty;
	int dist;
};

int n, m;
char map[21][21];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
bool visit[1 << 11][21][21];
int start_x, start_y;
int all;

bool inside(int x, int y) { if (x < 0 || y < 0 || x >= n || y >= m)return false; return true; }

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

int bfs(int x, int y) {
	memset(visit, false, sizeof(visit));
	NODE start;
	start.x = x; start.y = y; start.dirty = 0; start.dist = 0;
	visit[start.dirty][start.x][start.y] = true;
	queue<NODE>q;
	q.push(start);
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cur_dirty = q.front().dirty;
		int dist = q.front().dist;
		q.pop();
		if (cur_dirty == all) {
			return dist;
		}
		for (int d = 0; d < 4; d++) {
			int nx = cx + dir[d][0];
			int ny = cy + dir[d][1];
			if (!inside(nx, ny))continue;
			if (map[nx][ny] == 'x')continue;
			if (map[nx][ny] == '.' || map[nx][ny] == 'o') {
				if (!visit[cur_dirty][nx][ny]) {
					visit[cur_dirty][nx][ny] = true;
					q.push({ nx,ny,cur_dirty,dist + 1 });
				}
			}
			if ('A' <= map[nx][ny] && map[nx][ny] <= 'Z') {
				int new_dirty = cur_dirty | (1 << int(map[nx][ny] - 'A'));
				if (!visit[new_dirty][nx][ny]) {
					visit[new_dirty][nx][ny] = true;
					visit[cur_dirty][nx][ny] = true;
					q.push({ nx,ny,new_dirty,dist + 1 });
				}
			}
		}
	}
	return -1;
}

int main() {
	freopen("Text.txt", "r", stdin);
	while (1) {
		cin >> m >> n;
		if (m == 0 && n == 0)break;
		int dirty = 0;
		all = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
				if (map[i][j] == '*') {
					map[i][j] = 'A' + dirty++;
					all |= (1 << int(map[i][j] - 'A'));
				}
				if (map[i][j] == 'o') {
					start_x = i;
					start_y = j;
				}
			}
		}
		cout << bfs(start_x, start_y) << "\n";
	}
}