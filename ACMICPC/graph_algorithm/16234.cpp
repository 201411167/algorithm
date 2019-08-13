#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int n;
int l, r;
int map[51][51];
bool visit[51][51];
int group[51][51];
int sum[2600];
int people[2600];

void input() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

void init_visit() {
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			visit[i][j] = false;
		}
	}
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n)return false;
	return true;
}

void get_union(int x, int y, int num) {
	int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
	queue<pii>q;
	q.push({ x,y });
	visit[x][y] = true;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		group[cx][cy] = num;
		for (int d = 0; d < 4; d++) {
			int nx = cx + dir[d][0];
			int ny = cy + dir[d][1];
			if (!inside(nx, ny))continue;
			int diff = abs(map[nx][ny] - map[cx][cy]);
			if (l <= diff && diff <= r) {
				if (!visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
}

void grouping() {
	int team = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				visit[i][j] = true;
				team++;
				get_union(i, j,team);
			}
		}
	}
	init_visit();
}

void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << group[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

bool is_end() {
	int expected_team = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (group[i][j] != ++expected_team) {
				return false;
			}
		}
	}
	return true;
}

void divide() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum[group[i][j]] = 0;
			people[group[i][j]] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum[group[i][j]] += map[i][j];
			people[group[i][j]]++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = sum[group[i][j]] / people[group[i][j]];
		}
	}
}

int solution() {
	int cnt = 0;
	while (1) {
		if (is_end()) { break; }
		else {
			cnt++;
			grouping();
			divide();
		}
	}
	return cnt;
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	cout << solution() - 1;
	return 0;
}