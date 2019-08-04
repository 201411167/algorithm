#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct NODE {
	int x, y, d;
};
int n, m;
int sx, sy, sd;
int map[51][51];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
bool visit[51][51];

bool inside(int x, int y) { if (x < 0 || y < 0 || x >= n || y >= m)return false; return true; }

int answer = 0;
void bfs() {
	queue<NODE>q;
	q.push({ sx,sy,sd });
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cd = q.front().d;
		q.pop();

		if (!visit[cx][cy]) {
			visit[cx][cy] = true;
			answer++;
		}

		int nd = cd;
		bool find = false;
		for (int d = 0; d < 4; d++) {
			nd = (nd + 3) % 4;
			int nx = cx + dir[nd][0];
			int ny = cy + dir[nd][1];
			if (!inside(nx, ny))continue;
			if (map[nx][ny] == 1)continue;
			if (map[nx][ny] == 0) {
				if (!visit[nx][ny]) {
					q.push({ nx,ny,nd });
					find = true;
					break;
				}
			}
		}
		if (!find) {
			int nx = cx - dir[nd][0];
			int ny = cy - dir[nd][1];
			if (inside(nx, ny) && map[nx][ny] == 0) {
				q.push({ nx,ny,cd });
			}
		}
	}
}

int all = 0;
void input() {
	cin >> n >> m;
	cin >> sx >> sy >> sd;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				all++;
			}
		}
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	bfs();
	cout << answer;
}