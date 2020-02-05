#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int original_map[21][21];
int map[21][21];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> original_map[i][j];
		}
	}
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n)return false;
	return true;
}

bool occupied[21][21];
void move(int d) {
	memset(occupied, false, sizeof(occupied));

	if (d == 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 0)continue;
				int cx = i;
				int cy = j;
				int nx = cx + dir[d][0];
				int ny = cy + dir[d][1];
				if (!inside(nx, ny) || occupied[nx][ny])continue;
				while (1) {
					if (!inside(nx, ny) || map[nx][ny] != 0)break;
					map[nx][ny] = map[cx][cy];
					map[cx][cy] = 0;
					nx += dir[d][0];
					ny += dir[d][1];
					cx += dir[d][0];
					cy += dir[d][1];
				}
				if (!occupied[nx][ny] && map[nx][ny] == map[cx][cy]) {
					map[nx][ny] += map[cx][cy];
					map[cx][cy] = 0;
					occupied[nx][ny] = true;
				}
			}
		}
	}
	if (d == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 0)continue;
				int cx = i;
				int cy = j;
				int nx = cx + dir[d][0];
				int ny = cy + dir[d][1];
				if (!inside(nx, ny) || occupied[nx][ny])continue;
				while (1) {
					if (!inside(nx, ny) || map[nx][ny] != 0)break;
					map[nx][ny] = map[cx][cy];
					map[cx][cy] = 0;
					nx += dir[d][0];
					ny += dir[d][1];
					cx += dir[d][0];
					cy += dir[d][1];
				}
				if (!occupied[nx][ny] && map[nx][ny] == map[cx][cy]) {
					map[nx][ny] += map[cx][cy];
					map[cx][cy] = 0;
					occupied[nx][ny] = true;
				}
			}
		}
	}
	if (d == 2) {
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 0)continue;
				int cx = i;
				int cy = j;
				int nx = cx + dir[d][0];
				int ny = cy + dir[d][1];
				if (!inside(nx, ny) || occupied[nx][ny])continue;
				while (1) {
					if (!inside(nx, ny) || map[nx][ny] != 0)break;
					map[nx][ny] = map[cx][cy];
					map[cx][cy] = 0;
					nx += dir[d][0];
					ny += dir[d][1];
					cx += dir[d][0];
					cy += dir[d][1];
				}
				if (!occupied[nx][ny] && map[nx][ny] == map[cx][cy]) {
					map[nx][ny] += map[cx][cy];
					map[cx][cy] = 0;
					occupied[nx][ny] = true;
				}
			}
		}
	}
	if (d == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (map[i][j] == 0)continue;
				int cx = i;
				int cy = j;
				int nx = cx + dir[d][0];
				int ny = cy + dir[d][1];
				if (!inside(nx, ny) || occupied[nx][ny])continue;
				while (1) {
					if (!inside(nx, ny) || map[nx][ny] != 0)break;
					map[nx][ny] = map[cx][cy];
					map[cx][cy] = 0;
					nx += dir[d][0];
					ny += dir[d][1];
					cx += dir[d][0];
					cy += dir[d][1];
				}
				if (!occupied[nx][ny] && map[nx][ny] == map[cx][cy]) {
					map[nx][ny] += map[cx][cy];
					map[cx][cy] = 0;
					occupied[nx][ny] = true;
				}
			}
		}
	}
}

void init_map() {
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			map[x][y] = original_map[x][y];
		}
	}
}

int answer = 0;
// 중복이 있는 순열
void permutation(vector<int> list, int cnt) {
	if (cnt == 5) {
		init_map();
		for (int i = 0; i < list.size(); i++) {
			move(list[i]);
		}
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				answer = max(answer, map[x][y]);
			}
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			list.push_back(i);
			permutation(list, cnt + 1);
			list.pop_back();
		}
	}
}

void solve() {
	vector<int>list;
	permutation(list, 0);
	cout << answer;
}

int main() {
	//freopen("Text.txt", "r", stdin);
	input();
	solve();

	return 0;
}