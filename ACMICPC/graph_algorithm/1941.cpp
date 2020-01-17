#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <time.h>
#include <queue>
using namespace std;

#define pii pair<int,int>
char map[5][5];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };

void input() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= 5 || y >= 5)return false;
	return true;
}

bool comb_chk[25];
int answer = 0;
bool adj() {
	bool rtn = false;
	queue<pii>q;
	int x, y;
	for (int i = 0; i < 25; i++) {
		if (comb_chk[i]) {
			x = i / 5;
			y = i % 5;
		}
	}

	bool visit[5][5];
	memset(visit, false, sizeof(visit));
	visit[x][y] = true;
	int cnt = 1;
	q.push({ x,y });
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = cx + dir[d][0];
			int ny = cy + dir[d][1];
			if (!inside(nx, ny))continue;
			if (comb_chk[nx * 5 + ny] && !visit[nx][ny]) {
				cnt++;
				visit[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	if (cnt >= 7)rtn = true;
	return rtn;
}

bool more_than_four() {
	int cnt = 0;
	for (int i = 0; i < 25; i++) {
		if (comb_chk[i]) {
			int x = i / 5;
			int y = i % 5;
			if (map[x][y] == 'S') {
				cnt++;
			}
		}
	}
	if (cnt >= 4) return true;
	else return false;
}

void comb(int idx, int cnt) {
	if (cnt == 7) {
		// 7¸íÀ» »Ì´Â´Ù
		if (more_than_four() && adj()) {
			answer++;
		}
		return;
	}
	else {
		for (int i = idx; i < 25; i++) {
			if (!comb_chk[i]) {
				comb_chk[i] = true;
				comb(i, cnt + 1);
				comb_chk[i] = false;
			}
		}
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	comb(0, 0);
	cout << answer;
	return 0;
}
