#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int k, n, m;
int map[201][201];
int visit[31][201][201];
int dx[] = { 0,-1,0,1,-1,-1,-2,-2,1,1,2,2 };
int dy[] = { -1,0,1,0,-2,2,-1,1,-2,2,-1,1 };

struct info {
	int x, y;
	int jump;
	int cnt;
};
info start;
queue<info>q;
int answer = 1e9;
bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)return false;
	return true;
}
void bfs() {
	while (!q.empty()) {
		info cur = q.front();
		info nxt;
		q.pop();
		if (cur.x == n - 1 && cur.y == m - 1) {
			answer = min(answer, cur.cnt);
		}
		if (cur.jump == 0) {
			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if (!inside(nx, ny))continue;
				if (map[nx][ny] == 1)continue;
				nxt.x = nx;
				nxt.y = ny;
				nxt.jump = cur.jump;
				nxt.cnt = cur.cnt + 1;
				if (visit[nxt.jump][nxt.x][nxt.y] == 0) {
					visit[nxt.jump][nxt.x][nxt.y] = 1;
					q.push(nxt);
				}
			}
		}
		else {
			for (int i = 0; i < 12; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if (!inside(nx, ny))continue;
				if (map[nx][ny] == 1)continue;
				if (0 <= i && i < 4) {
					nxt.x = nx;
					nxt.y = ny;
					nxt.jump = cur.jump;
					nxt.cnt = cur.cnt + 1;
					if (visit[nxt.jump][nxt.x][nxt.y] == 0) {
						visit[nxt.jump][nxt.x][nxt.y] = 1;
						q.push(nxt);
					}
				}
				if (4 <= i & i < 12) {
					nxt.x = nx;
					nxt.y = ny;
					nxt.jump = cur.jump - 1;
					nxt.cnt = cur.cnt + 1;
					if (visit[nxt.jump][nxt.x][nxt.y] == 0) {
						visit[nxt.jump][nxt.x][nxt.y] = 1;
						q.push(nxt);
					}
				}
			}
		}
	}
}

int main() {
	//freopen("Text.txt", "r", stdin);
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	cin >> k >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	start.x = 0;
	start.y = 0;
	start.jump = k;
	start.cnt = 0;
	q.push(start);
	bfs();
	if (answer != 1e9) {
		cout << answer;
	}
	else {
		cout << -1;
	}
}