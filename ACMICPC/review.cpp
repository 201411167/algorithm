#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int n, m;
char map[1501][1501];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
bool visit[1501][1501];

struct NODE {
	int x, y;
	int day;
};
bool operator < (NODE a, NODE b) {
	return a.day > b.day;
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) { return false; }
	return true;
}

int sx, sy;
queue<pii>w1;
queue<pii>w2;
int bfs() {
	NODE start;
	start.x = sx; start.y = sy; start.day = 0;
	priority_queue<NODE>q1;
	priority_queue<NODE>q2;
	q1.push(start);
	while (!q1.empty() || !q2.empty() || !w1.empty() || !w2.empty()) {
		while (!q1.empty()) {
			int cx = q1.top().x;
			int cy = q1.top().y;
			int cd = q1.top().day;
			q1.pop();
			if (cx != sx && cy != sy && map[cx][cy] == 'L') {
				return cd;
			}
			for (int d = 0; d < 4; d++) {
				int nx = cx + dir[d][0];
				int ny = cy + dir[d][1];
				if (!inside(nx, ny))continue;
				if (map[nx][ny] == '.' || map[nx][ny] == 'L') {
					if (!visit[nx][ny]) {
						visit[nx][ny] = true;
						NODE nxt;
						nxt.x = nx; nxt.y = ny; nxt.day = cd;
						q1.push(nxt);
					}
				}
				if (map[nx][ny] == 'X') {
					if (!visit[nx][ny]) {
						visit[nx][ny] = true;
						NODE nxt;
						nxt.x = nx; nxt.y = ny; nxt.day = cd + 1;
						q2.push(nxt);
					}
				}
			}
		}
		while (!w1.empty()) {
			int cx = w1.front().first;
			int cy = w1.front().second;
			w1.pop();
			for (int d = 0; d < 4; d++) {
				int nx = cx + dir[d][0];
				int ny = cy + dir[d][1];
				if (!inside(nx, ny))continue;
				if (map[nx][ny] == 'X') {
					map[nx][ny] = '.';
					w2.push({ nx,ny });
				}
			}
		}
		while (!q2.empty()) {
			int cx = q2.top().x;
			int cy = q2.top().y;
			int cd = q2.top().day;
			q2.pop();
			if (cx != sx && cy != sy && map[cx][cy] == 'L') {
				return cd;
			}
			for (int d = 0; d < 4; d++) {
				int nx = cx + dir[d][0];
				int ny = cy + dir[d][1];
				if (!inside(nx, ny))continue;
				if (map[nx][ny] == '.' || map[nx][ny] == 'L') {
					if (!visit[nx][ny]) {
						visit[nx][ny] = true;
						NODE nxt;
						nxt.x = nx; nxt.y = ny; nxt.day = cd;
						q2.push(nxt);
					}
				}
				if (map[nx][ny] == 'X') {
					if (!visit[nx][ny]) {
						visit[nx][ny] = true;
						NODE nxt;
						nxt.x = nx; nxt.y = ny; nxt.day = cd + 1;
						q1.push(nxt);
					}
				}
			}
		}
		while (!w2.empty()) {
			int cx = w2.front().first;
			int cy = w2.front().second;
			w2.pop();
			for (int d = 0; d < 4; d++) {
				int nx = cx + dir[d][0];
				int ny = cy + dir[d][1];
				if (!inside(nx, ny))continue;
				if (map[nx][ny] == 'X') {
					map[nx][ny] = '.';
					w1.push({ nx,ny });
				}
			}
		}
	}
	return -1;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'L') {
				sx = i;
				sy = j;
			}
			if (map[i][j] == '.' || map[i][j] == 'L') {
				w1.push({ i,j });
			}
		}
	}
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	freopen("Text.txt", "r", stdin);

	input();
	cout << bfs();

	return 0;
}
