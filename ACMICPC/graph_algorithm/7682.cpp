#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

#define piii pair<int,pair<int,int>>
char map[3][3];
int dist[8][3][3];
int checkmate[3][3];
int checknum;
int dir[8][2] = { {-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };
int xs, os;

bool input() {
	xs = 0;
	os = 0;
	string tmp; cin >> tmp;
	if (tmp.compare("end") == 0)return false;
	else {
		int i = 0;
		int j = 0;
		for (int k = 0; k < tmp.length(); k++) {
			map[i][j++] = tmp[k];
			if (tmp[k] == 'X')xs++;
			if (tmp[k] == 'O')os++;
			if (j == 3) {
				j = 0;
				i++;
			}
		}
	}
	return true;
}

void show() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

void show_check() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << checkmate[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

void init_dist() {
	for (int k = 0; k < 8; k++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				dist[k][i][j] = 1e9;
			}
		}
	}
}

void init_checkmate() {
	checknum = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			checkmate[i][j] = 0;
		}
	}
}

bool full() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (map[i][j] == '.')return false;
		}
	}
	return true;
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= 3 || y >= 3)return false;
	return true;
}

void bfs(int x, int y) {
	if (map[x][y] == '.')return;
	if (checkmate[x][y] > 0)return;
	queue<piii>q;
	init_dist();
	for (int d = 0; d < 8; d++) {
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];
		if (!inside(nx, ny))continue;
		if (map[nx][ny] == map[x][y]) {
			q.push({ d,{x,y} });
			dist[d][x][y] = 0;
		}
	}
	while (!q.empty()) {
		int cx = q.front().second.first;
		int cy = q.front().second.second;
		int cd = q.front().first;
		q.pop();
		if (dist[cd][cx][cy] == 2) {
			if (checkmate[x][y] == 0 && checkmate[(x + cx) / 2][(y + cy) / 2] == 0 && checkmate[cx][cy] == 0) {
				checknum++;
				checkmate[x][y] = checknum;
				checkmate[(x + cx) / 2][(y + cy) / 2] = checknum;
				checkmate[cx][cy] = checknum;
			}
			else {
				int tmp = max(checkmate[x][y], max(checkmate[(x + cx) / 2][(y + cy) / 2], checkmate[cx][cy]));
				checkmate[x][y] = tmp;
				checkmate[(x + cx) / 2][(y + cy) / 2] = tmp;
				checkmate[cx][cy] = tmp;
			}
			return;
		}
		int nx = cx + dir[cd][0];
		int ny = cy + dir[cd][1];
		if (inside(nx, ny)) {
			if (map[nx][ny] == map[x][y]) {
				if (dist[cd][nx][ny] > dist[cd][cx][cy] + 1) {
					dist[cd][nx][ny] = dist[cd][cx][cy] + 1;
					q.push({ cd,{nx,ny} });
				}
			}
		}
	}
	return;
}

void solve() {
	init_checkmate();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			bfs(i, j);
		}
	}
}

void solution() {
	if (xs == os || xs == os + 1) {
		solve();
		if (xs == os) {
			char player='F';
			int win = 0;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (win < checkmate[i][j]) {
						win = checkmate[i][j];
						player = map[i][j];
					}
				}
			}
			if (player == 'O' && win == 1) {
				cout << "valid\n";
				return;
			}
			else {
				cout << "invalid\n";
				return;
			}
		}
		if (xs == os + 1) {
			char player = 'F';
			int win = 0;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (win < checkmate[i][j]) {
						win = checkmate[i][j];
						player = map[i][j];
					}
				}
			}
			if (player == 'X' && win == 1) {
				cout << "valid\n";
				return;
			}
			if (full() && player == 'F' && win == 0) {
				cout << "valid\n";
				return;
			}
			else {
				cout << "invalid\n";
				return;
			}
		}
	}
	else {
		cout << "invalid\n";
		return;
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	while (input()) {
		solution();
	}
}