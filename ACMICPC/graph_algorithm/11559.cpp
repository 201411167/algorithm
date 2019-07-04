#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
#define piii pair<int,pii>

char map[12][6];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

bool inside(int x, int y) {
	if (x < 0 || x>12 || y < 0 || y >= 6)return false;
	return true;
}

void show() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void fall() {
	bool again = false;
	for (int i = 1; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (map[i][j] == '.') {
				if (map[i - 1][j] != '.') {
					map[i][j] = map[i - 1][j];
					map[i - 1][j] = '.';
					again = true;
				}
			}
		}
	}
	if (again) { fall(); }
}

int crush(int x, int y) {
	if (map[x][y] == '.')return -1;
	int cnt = 0;
	char item = map[x][y];
	bool visit[13][7] = { 0, };
	queue<pii>q; // for exploring
	queue<pii>trace; // storage for items same as map[x][y]
	visit[x][y] = true;
	q.push({ x,y });
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		if (map[cx][cy] == map[x][y]) {
			trace.push({ cx,cy });
			cnt++;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (!inside(nx, ny))continue;
			if (map[nx][ny] == map[cx][cy]) {
				if (visit[nx][ny] == false) {
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
	if (cnt >= 4) {
		while (!trace.empty()) {
			int cx = trace.front().first;
			int cy = trace.front().second;
			trace.pop();
			map[cx][cy] = '.';
		}
		return 1;
	}
	else {
		while (!trace.empty()) {
			trace.pop();
		}
		return -1;
	}
}

int start() {
	fall();
	int score = 0;
	while (1) {
		bool win = false;
		while (1) {
			int stop = 0;
			for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 6; j++) {
					if (map[i][j] == '.')continue;
					int result = crush(i, j);
					if (result == 1) {
						win = true;
						stop++;
					}
				}
			}
			if (stop == 0) break;
		}
		if (win) {
			score++;
			fall();
		}
		else {
			break;
		}
	}
	return score;
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	freopen("Text.txt", "r", stdin);

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> map[i][j];
		}
	}
	cout << start();
	return 0;
}