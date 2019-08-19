#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct { int rx, ry, bx, by; }BEAD; BEAD start;
int n, m;
char map[11][11];
int dijk[11][11][11][11];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int goalx, goaly;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				start.rx = i;
				start.ry = j;
			}
			if (map[i][j] == 'B') {
				start.bx = i;
				start.by = j;
			}
			if (map[i][j] == 'O') {
				goalx = i;
				goaly = j;
			}
		}
	}
}

void bfs() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < m; l++) {
					dijk[i][j][k][l] = 1e9;
				}
			}
		}
	}
	dijk[start.rx][start.ry][start.bx][start.by] = 0;
	queue<BEAD>q;
	q.push(start);
	while (!q.empty()) {
		int crx = q.front().rx;
		int cry = q.front().ry;
		int cbx = q.front().bx;
		int cby = q.front().by;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nrx = crx;
			int nry = cry;
			int nbx = cbx;
			int nby = cby;
			while (1) {
				if (map[nrx][nry] != '#' && map[nrx][nry] != 'O') {
					nrx += dir[d][0];
					nry += dir[d][1];
				}
				else {
					if (map[nrx][nry] == '#') {
						nrx -= dir[d][0];
						nry -= dir[d][1];
					}
					break;
				}
			}
			while (1) {
				if (map[nbx][nby] != '#' && map[nbx][nby] != 'O') {
					nbx += dir[d][0];
					nby += dir[d][1];
				}
				else {
					if (map[nbx][nby] == '#') {
						nbx -= dir[d][0];
						nby -= dir[d][1];
					}
					break;
				}
			}
			if (nrx == nbx && nry == nby) {
				if (map[nrx][nry] != 'O') {
					int r_dist = abs(nrx - crx) + abs(nry - cry);
					int b_dist = abs(nbx - cbx) + abs(nby - cby);
					if (r_dist > b_dist) {
						nrx -= dir[d][0];
						nry -= dir[d][1];
					}
					else {
						nbx -= dir[d][0];
						nby -= dir[d][1];
					}
				}
			}
			if (map[nbx][nby] != 'O') {
				if (dijk[nrx][nry][nbx][nby] > dijk[crx][cry][cbx][cby] + 1) {
					dijk[nrx][nry][nbx][nby] = dijk[crx][cry][cbx][cby] + 1;
					q.push({ nrx,nry,nbx,nby });
				}
			}
		}
	}
}

void solve() {
	vector<int>answer;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dijk[goalx][goaly][i][j] == 1e9)continue;
			answer.push_back({ dijk[goalx][goaly][i][j] });
		}
	}
	sort(answer.begin(), answer.end());
	if (answer.empty()) {
		cout << -1;
	}
	else {
		cout << answer[0];
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	bfs();
	solve();
	
	return 0;
}