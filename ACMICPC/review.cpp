#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
char map[21][21];
int sx, sy;
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int visit[1 << 11][21][21];
int total;

struct NODE {
	int x, y;
	int dirty;
};

void input() {
	cin >> m >> n;
	if (m == 0 && n == 0) {
		return;
	}
	total = 0;
	int numbering = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'o') { sx = i; sy = j; }
			if (map[i][j] == '*') {
				map[i][j] = 'A' + numbering++;
				total |= (1 << map[i][j] - 'A');
			}
		}
	}
}

void init() {
	for (int i = 0; i < (1 << 11); i++) {
		for (int j = 0; j < 21; j++) {
			for (int k = 0; k < 21; k++) {
				visit[i][j][k] = 1e9;
			}
		}
	}
	visit[0][sx][sy] = 0;
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)return false;
	return true;
}

int bfs() {
	int ret = 1e9;
	queue<NODE>q;
	q.push({ sx,sy,0 });
	init();
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cd = q.front().dirty;
		q.pop();
		if (cd == total) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					ret = min(ret, visit[total][i][j]);
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
				int nd = cd | new_dirty;
				if (visit[nd][nx][ny] > visit[cd][cx][cy] + 1) {
					visit[nd][nx][ny] = visit[cd][cx][cy] + 1;
					visit[cd][nx][ny] = visit[cd][cx][cy] + 1;
					q.push({ nx,ny,nd });
				}
			}
		}
	}
	if (ret == 1e9)ret = -1;
	return ret;
}

void solve() {
	while (1) {
		input();
		if (n == 0 && m == 0)break;
		cout << bfs() << "\n";
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	solve();
}