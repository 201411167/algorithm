#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

// 오작교에는 주기가 있다.
// 두 번 연속으로 오작교를 건너지는 않는다. (오작교 -> 오작교 : 불가능)
// 오작교 예정 구역에는 추가적으로 설치할 수 없다.
// 절벽이 교차하는 구간에는 오작교를 설치할 수 없다.
// 견우와 직녀가 만날 수 없는 경우는 없다.

struct NODE {
	int x, y;
	bool from_bridge;
};
int n, m;
int map[11][11];
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

bool buildable(int x, int y) {
	if (map[x][y] != 0)return false;
	int cnt = 0;
	for (int d = 0; d < 4; d++) {
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];
		if (!inside(nx, ny))continue;
		if (map[nx][ny] == 0) {
			cnt++;
		}
	}
	if (cnt >= 2)return false;
	return true;
}

int answer = 1e9;
void bfs(int x, int y) {
	int visit[11][11];
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			visit[i][j] = 1e9;
		}
	}
	visit[x][y] = 0;
	queue<NODE>q;
	NODE start; start.x = x; start.y = y; start.from_bridge = false;
	q.push(start);
	while (!q.empty()) {
		NODE cur = q.front();
		if (cur.x == n - 1 && cur.y == n - 1) {
			answer = min(answer, visit[cur.x][cur.y]);
		}
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = cur.x + dir[d][0];
			int ny = cur.y + dir[d][1];
			if (!inside(nx, ny))continue;
			if (map[nx][ny] == 0)continue;
			if (map[nx][ny] == 1) {
				if (visit[nx][ny] > visit[cur.x][cur.y] + 1) {
					visit[nx][ny] = visit[cur.x][cur.y] + 1;
					q.push({ nx,ny,false });
				}
			}
			if (2 <= map[nx][ny] && map[nx][ny] <=100) {
				if (cur.from_bridge == false) {
					int tmp = visit[cur.x][cur.y] + 1;
					while (1) {
						if (tmp % map[nx][ny] == 0) {
							break;
						}
						tmp++;
					}
					if (visit[nx][ny] > tmp) {
						visit[nx][ny] = tmp;
						q.push({ nx,ny,true });
					}
				}
			}
		}
	}
}

void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void solve() {
	bfs(0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (buildable(i, j)) {
				int origin = map[i][j];
				map[i][j] = m;
				bfs(0, 0);
				map[i][j] = origin;
			}
		}
	}
	cout << answer;
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	solve();
	return 0;
}