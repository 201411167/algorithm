#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int l, r, c;
char map[31][31][31];
int start_floor, start_x, start_y;

int d[6][3] = { {-1,0,0},{1,0,0},{0,-1,0},{0,0,-1},{0,1,0},{0,0,1} };
bool visit[31][31][31];

typedef struct NODE {
	int f, x, y;
	int distance;
}NODE;
bool operator < (NODE a, NODE b) {
	return a.distance > b.distance;
}

bool inside(int f, int x, int y) {
	if (f < 0 || x < 0 || y < 0 || f >= l || x >= r || y >= c)return false;
	return true;
}

int bfs() {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				visit[i][j][k] = false;
			}
		}
	}
	NODE start;
	start.f = start_floor; start.x = start_x; start.y = start_y;
	start.distance = 0;
	visit[start.f][start.x][start.y] = true;
	queue<NODE>q;
	q.push(start);
	while (!q.empty()) {
		int cf = q.front().f;
		int cx = q.front().x;
		int cy = q.front().y;
		int cd = q.front().distance;
		q.pop();
		if (map[cf][cx][cy] == 'E') {
			while (!q.empty()) { q.pop(); }
			return cd;
		}
		for (int i = 0; i < 6; i++) {
			int nf = cf + d[i][0];
			int nx = cx + d[i][1];
			int ny = cy + d[i][2];
			if (!inside(nf, nx, ny))continue;
			if (map[nf][nx][ny] == '.' || map[nf][nx][ny] == 'E') {
				if (visit[nf][nx][ny] == false) {
					visit[nf][nx][ny] = true;
					NODE nxt;
					nxt.f = nf; nxt.x = nx; nxt.y = ny; nxt.distance = cd + 1;
					q.push(nxt);
				}
			}
		}
	}
	return -1;
}

int main() {
	freopen("Text.txt", "r", stdin);
	
	while (1) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0)break;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> map[i][j][k];
					if (map[i][j][k] == 'S') {
						start_floor = i;
						start_x = j;
						start_y = k;
					}
				}
			}
		}
		int answer = bfs();
		if (answer == -1) {
			cout << "Trapped!\n";
		}
		else {
			cout << "Escaped in " << answer << " minute(s).\n";
		}
	}
	return 0;
}