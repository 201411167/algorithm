#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

unsigned r, c, t;
int map[51][51];
struct DUST {
	int x, y;
	int amount;
	int spread[4];
};
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int ux, uy, dx, dy;

void input() {
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				dx = i;
				dy = j;
			}
		}
	}
	ux = dx - 1;
	uy = dy;
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= r || y >= c)return false;
	return true;
}

queue<DUST>q;
void solve() {
	while (t--) {
		//먼지 확산
		// 1. 먼지의 위치와 양을 큐에 삽입
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j] != 0 && map[i][j] != -1) {
					q.push({ i,j,map[i][j],{0,0,0,0} });
				}
			}
		}
		int size = q.size();
		// 2. 큐에서 꺼내, 확산된 후의 상태를 큐에 삽입
		while (size--) {
			DUST cur = q.front();
			q.pop();
			DUST nxt;
			nxt.x = cur.x;
			nxt.y = cur.y;
			nxt.amount = cur.amount;
			int spread_count = 0;
			for (int d = 0; d < 4; d++) {
				int nx = cur.x + dir[d][0];
				int ny = cur.y + dir[d][1];
				if (!inside(nx, ny))continue;
				if (map[nx][ny] == -1)continue;
				nxt.spread[d] = cur.amount / 5;
				spread_count++;
			}
			if (spread_count != 0) {
				nxt.amount -= nxt.amount / 5 * spread_count;
			}
			q.push(nxt);
		}
		// 3. 맵 초기화
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j] != -1) {
					map[i][j] = 0;
				}
			}
		}
		// 4. 큐에서 꺼내, 맵에 더함
		while (!q.empty()) {
			DUST cur = q.front();
			q.pop();
			map[cur.x][cur.y] += cur.amount;
			for (int d = 0; d < 4; d++) {
				int nx = cur.x + dir[d][0];
				int ny = cur.y + dir[d][1];
				if (!inside(nx, ny))continue;
				if (map[nx][ny] == -1)continue;
				map[nx][ny] += cur.spread[d];
			}
		}
		//공기청정기
		if (uy == 0 && dy == 0) {
			for (int i = ux; i > 0; i--) {
				if (i == ux) {
					map[i - 1][0] = 0;
				}
				else {
					map[i][0] = map[i - 1][0];
				}
			}
			map[0][0] = 0;
			for (int j = 0; j < c - 1; j++) {
				map[0][j] = map[0][j + 1];
			}
			map[0][c - 1] = 0;
			for (int i = 0; i < ux; i++) {
				map[i][c - 1] = map[i + 1][c - 1];
			}
			map[ux][c - 1] = 0;
			for (int j = c - 1; j > 0; j--) {
				map[ux][j] = map[ux][j - 1];
			}
			map[ux][1] = 0;

			for (int i = dx; i < r - 1; i++) {
				if (i == dx) {
					map[i + 1][0] = 0;
				}
				else {
					map[i][0] = map[i + 1][0];
				}
			}
			map[r - 1][0] = 0;
			for (int j = 0; j < c - 1; j++) {
				map[r - 1][j] = map[r - 1][j + 1];
			}
			map[r - 1][c - 1] = 0;
			for (int i = r - 1; i > dx; i--) {
				map[i][c - 1] = map[i - 1][c - 1];
			}
			map[dx][c - 1] = 0;
			for (int j = c - 1; j > 0; j--) {
				map[dx][j] = map[dx][j - 1];
			}
			map[dx][1] = 0;
		}
	}
	int answer = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == -1)continue;
			answer += map[i][j];
		}
	}
	cout << answer;
}

int main() {
	//bool read =freopen("Text.txt", "r", stdin);
	input();
	solve();
	return 0;
}