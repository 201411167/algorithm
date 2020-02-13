#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct virus {
	int x, y;
};
int n, m;
int map[51][51];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n)return false;
	return true;
}

queue<virus>q;
bool combination_chk[51][51];
int visit[51][51];
int answer = 1e9;

void pick(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visit[i][j] = 1e9;
			}
		}
		for (int i = 0; i < n * n; i++) {
			int x = i / n;
			int y = i % n;
			if (combination_chk[x][y]) {
				q.push({ x,y });
				visit[x][y] = 0;
			}
		}
		int maxtime = 0;
		while (!q.empty()) {
			int cx = q.front().x;
			int cy = q.front().y;
			q.pop();
			for (int d = 0; d < 4; d++) {
				int nx = cx + dir[d][0];
				int ny = cy + dir[d][1];
				if (!inside(nx, ny))continue;
				if (map[nx][ny] == 1)continue;
				if (visit[nx][ny] > visit[cx][cy] + 1) {
					visit[nx][ny] = visit[cx][cy] + 1;
					q.push({ nx,ny });
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 2) {
					visit[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1)continue;
				maxtime = max(maxtime, visit[i][j]);
			}
		}
		int possible = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] != 1 && visit[i][j] == 1e9) {
					possible = -1;
				}
			}
		}
		if (possible == 0) {
			answer = min(answer, maxtime);
		}
	}
	else {
		for (int i = idx; i < n * n; i++) {
			int x = i / n;
			int y = i % n;
			if (combination_chk[x][y])continue;
			if (map[x][y] != 2)continue;
			combination_chk[x][y] = true;
			pick(i, cnt + 1);
			combination_chk[x][y] = false;
		}
	}
}

void solve() {
	pick(0, 0);
	if (answer == 1e9) {
		cout << -1;
	}
	else {
		cout << answer;
	}
}

int main() {
	//freopen("Text.txt", "r", stdin);
	input();
	solve();
	return 0;
}