#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct NODE {
	int x, y;
	int dirty;
};
int m, n;
char map[21][21];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int sx, sy;
int visit[1 << 11][21][21];
int all = 0;
int answer;

bool inside(int x, int y) { if (x < 0 || y < 0 || x >= n || y >= m)return false; return true; }

void init_visit() {
	for (int i = 0; i < (1 << 11); i++) {
		for (int j = 0; j < 21; j++) {
			for (int k = 0; k < 21; k++) {
				visit[i][j][k] = 1e9;
			}
		}
	}
	all = 0;
	answer = 1e9;
}


void bfs() {
	queue<NODE>q;
	q.push({ sx,sy,0 });
	visit[0][sx][sy] = 0;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cd = q.front().dirty;
		q.pop();
		if (cd == all) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					answer = min(answer, visit[all][i][j]);
				}
			}
		}
		for (int d = 0; d < 4; d++) {
			int nx = cx + dir[d][0];
			int ny = cy + dir[d][1];
			if (!inside(nx, ny))continue;
			if (map[nx][ny] == 'x')continue;
			if (map[nx][ny] == 'o' || map[nx][ny] == '.') {
				if (visit[cd][nx][ny] > visit[cd][cx][cy] + 1) {
					visit[cd][nx][ny] = visit[cd][cx][cy] + 1;
					q.push({ nx,ny,cd });
				}
			}
			if ('A' <= map[nx][ny] && map[nx][ny] <= 'Z') {
				int new_dirty = (1 << int(map[nx][ny] - 'A'));
				if (cd & new_dirty) {
					if (visit[cd][nx][ny] > visit[cd][cx][cy] + 1) {
						visit[cd][nx][ny] = visit[cd][cx][cy] + 1;
						q.push({ nx,ny,cd });
					}
				}
				else {
					int next_dirty = cd | new_dirty;
					visit[next_dirty][nx][ny] = visit[cd][cx][cy] + 1;
					visit[cd][nx][ny] = visit[cd][cx][cy] + 1;
					q.push({ nx,ny,next_dirty });
				}
			}
		}
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	while (1) {
		cin >> m >> n;
		if (m == 0 && n == 0)break;
		init_visit();
		int dirty = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'o') {
					sx = i; sy = j;
				}
				if (map[i][j] == '*') {
					map[i][j] = 'A' + dirty++;
					all |= (1 << int(map[i][j] - 'A'));
				}
			}
		}
		bfs();
		if (answer == 1e9) {
			cout << -1 << "\n";
		}
		else {
			cout << answer << "\n";
		}
	}
}