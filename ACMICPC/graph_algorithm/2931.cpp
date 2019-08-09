#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int n, m;
char map[26][26];
bool visit[26][26];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
char pipe[] = { '|','-','1','2','3','4','+' };
int sx, sy, gx, gy;
vector<pii>pipes;
pii point;
char answer;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'M') {
				sx = i; sy = j;
			}
			if (map[i][j] == 'Z') {
				gx = i; gy = j;
			}
			if (map[i][j] != '.' && map[i][j] != 'M' && map[i][j] != 'Z') {
				pipes.push_back({ i,j });
			}
		}
	}
}

bool inside(int x, int y) { if (x < 0 || y < 0 || x >= n || y >= m)return false; return true; }

void init_visit() { for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) { visit[i][j] = false; } } }

bool possible(int a, int b, int c, int d) {
	char before = map[a][b];
	char after = map[c][d];
	if (c == a - 1 && d == b) { // up
		if (before == '|' || before == '+' || before == '2' || before == '3') {
			if (after == '|' || after == '+' || after == '1' || after == '4' || after == 'Z' || after == '.') {
				return true;
			}
		}
	}
	if (c == a && d == b - 1) { // left
		if (before == '-' || before == '+' || before == '3' || before == '4') {
			if (after == '-' || after == '+' || after == '1' || after == '2' || after == 'Z' || after == '.') {
				return true;
			}
		}
	}
	if (c == a + 1 && d == b) { // down
		if (before == '|' || before == '+' || before == '1' || before == '4') {
			if (after == '|' || after == '+' || after == '2' || after == '3' || after == 'Z' || after == '.') {
				return true;
			}
		}
	}
	if (c == a && d == b + 1) { // right
		if (before == '-' || before == '+' || before == '1' || before == '2') {
			if (after == '-' || after == '+' || after == '3' || after == '4' || after == 'Z' || after == '.') {
				return true;
			}
		}
	}
	return false;
}

pii bfs() { // find empty place
	queue<pii>q;
	q.push({ sx,sy });
	visit[sx][sy] = true;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		if (map[cx][cy] == '.') {
			return { cx,cy };
		}

		if (map[cx][cy] == 'M') {
			for (int d = 0; d < 4; d++) {
				int nx = cx + dir[d][0];
				int ny = cy + dir[d][1];
				if (!inside(nx, ny))continue;
				if (map[nx][ny] == 'Z')continue;
				if (map[nx][ny] != '.') {
					if (!visit[nx][ny]) {
						visit[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		else {
			for (int d = 0; d < 4; d++) {
				int nx = cx + dir[d][0];
				int ny = cy + dir[d][1];
				if (!inside(nx, ny))continue;
				if (possible(cx, cy, nx, ny)) {
					if (!visit[nx][ny]) {
						visit[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
	}
	return { -1,-1 };
}

bool correct() {
	bool paradox = false; // anything doesn't make sense about placing pipes? ex) '-' above '+'
	init_visit();
	queue<pii>q;
	q.push({ sx,sy });
	visit[sx][sy] = true;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		if (map[cx][cy] == 'M') {
			for (int d = 0; d < 4; d++) {
				int nx = cx + dir[d][0];
				int ny = cy + dir[d][1];
				if (!inside(nx, ny))continue;
				if (map[nx][ny] == 'Z')continue;
				if (map[nx][ny] != '.' && !visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
		else {
			for (int d = 0; d < 4; d++) {
				int nx = cx + dir[d][0];
				int ny = cy + dir[d][1];
				if (!inside(nx, ny)) {
					if (map[cx][cy] == '+') {
						paradox = true;
					}
					continue;
				}
				char before = map[cx][cy];
				char after = map[nx][ny];
				if (d == 0) { // up
					if (before == '|' || before == '+' || before == '2' || before == '3') {
						if (after == '-' || after == '2' || after == '3' || after == '.') {
							paradox = true;
						}
					}
				}
				if (d == 1) { // left
					if (before == '-' || before == '+' || before == '3' || before == '4') {
						if (after == '|' || after == '3' || after == '4' || after == '.') {
							paradox = true;
						}
					}
				}
				if (d == 2) { // down
					if (before == '|' || before == '+' || before == '1' || before == '4') {
						if (after == '-' || after == '1' || after == '4' || after == '.') {
							paradox = true;
						}
					}
				}
				if (d == 3) { // right
					if (before == '-' || before == '+' || before == '1' || before == '2') {
						if (after == '|' || after == '1' || after == '2' || after == '.') {
							paradox = true;
						}
					}
				}
				if (possible(cx, cy, nx, ny)) {
					if (!visit[nx][ny]) {
						visit[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
	}

	bool reach_at_Z = false; // is it able to reach at 'Z'?
	init_visit();
	visit[sx][sy] = true;
	q.push({ sx,sy });
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		if (map[cx][cy] == 'M') {
			for (int d = 0; d < 4; d++) {
				int nx = cx + dir[d][0];
				int ny = cy + dir[d][1];
				if (!inside(nx, ny))continue;
				if (map[nx][ny] == 'Z')continue;
				if (map[nx][ny] != '.' && !visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
		else {
			for (int d = 0; d < 4; d++) {
				int nx = cx + dir[d][0];
				int ny = cy + dir[d][1];
				if (!inside(nx, ny))continue;
				if (possible(cx, cy, nx, ny)) {
					if (!visit[nx][ny]) {
						visit[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
	}
	if (visit[gx][gy]) {
		reach_at_Z = true;
	}

	bool visit_all = true; // is it able to visit all pipes?
	for (int i = 0; i < pipes.size(); i++) {
		int x = pipes[i].first;
		int y = pipes[i].second;
		if (!visit[x][y]) {
			visit_all = false;
		}
	}

	init_visit();
	if (visit_all && !paradox && reach_at_Z) {
		return true;
	}
	else {
		return false;
	}
}

void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

void solution() {
	int x = point.first;
	int y = point.second;
	for (int i = 0; i < 7; i++) {
		map[x][y] = pipe[i];
		if (correct()) {
			cout << x + 1 << " " << y + 1 << " " << pipe[i] << "\n";
		}
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	point = bfs();
	int x = point.first;
	int y = point.second;
	for (int i = 0; i < 7; i++) {
		map[x][y] = pipe[i];
		if (correct()) {
			cout << x + 1 << " " << y + 1 << " " << pipe[i] << "\n";
			return 0;
		}
	}
}
