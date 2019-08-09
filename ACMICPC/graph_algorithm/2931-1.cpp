#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
typedef struct {
	int x, y;
	int d;
}GAS;
int n, m;
char map[26][26];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
bool visit[26][26];
char pipe[] = { '|','-','1','2','3','4','+' };
vector<pii> pipes;
int sx, sy, gx, gy;
pii point;

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

void init() { for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) { visit[i][j] = false; } } }

bool inside(int x, int y) { if (x < 0 || y < 0 || x >= n || y >= m)return false; return true; }

int get_direction(int cd, char nxt) {
	int nd = -1;
	if (nxt == '|') {
		if (cd == 0 || cd == 2) {
			nd = cd;
		}
	}
	if (nxt == '-') {
		if (cd == 1 || cd == 3) {
			nd = cd;
		}
	}
	if (nxt == '+') {
		nd = cd;
	}
	if (nxt == '1') {
		if (cd == 0) nd = 3; // up -> right
		if (cd == 1) nd = 2; // left -> down
	}
	if (nxt == '2') {
		if (cd == 2) nd = 3; // down -> right
		if (cd == 1) nd = 0; // left -> up
	}
	if (nxt == '3') {
		if (cd == 3) nd = 0; // right -> up
		if (cd == 2) nd = 1; // down -> left
	}
	if (nxt == '4') {
		if (cd == 0) nd = 1; // up -> left
		if (cd == 3) nd = 2; // right -> down
	}
	return nd;
}

pii bfs() {
	int start_path_cnt = 0;
	int sd;
	for (int d = 0; d < 4; d++) {
		int nx = sx + dir[d][0];
		int ny = sy + dir[d][1];
		if (!inside(nx, ny))continue;
		if (map[nx][ny] == 'Z')continue;
		if (map[nx][ny] != '.') {
			if (get_direction(d, map[nx][ny]) != -1) {
				start_path_cnt++;
				sd = d;
			}
		}
	}
	if (start_path_cnt == 1) {
		queue<GAS>q;
		q.push({ sx,sy,sd });
		while (!q.empty()) {
			int cx = q.front().x;
			int cy = q.front().y;
			int cd = q.front().d;
			q.pop();
			visit[cx][cy] = true;

			int nx = cx + dir[cd][0];
			int ny = cy + dir[cd][1];
			if (inside(nx, ny)) {
				int nd = get_direction(cd, map[nx][ny]);
				if (nd != -1) {
					q.push({ nx,ny,nd });
				}
				if (nd == -1) {
					if (map[nx][ny] == '.') {
						return { nx,ny };
					}
					if (map[nx][ny] == 'Z') {
						return { -1,-1 };
					}
					return { -2,-2 };
				}
			}
		}
	}
	else {
		return { -2,-2 };
	}
}

bool visit_all() {
	for (int i = 0; i < pipes.size(); i++) {
		if (!visit[pipes[i].first][pipes[i].second]) {
			return false;
		}
	}
	return true;
}

int main() {
	freopen("Text.txt", "r", stdin);
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	input();
	point = bfs();
	for (int i = 0; i < 7; i++) {
		map[point.first][point.second] = pipe[i];
		init();
		pii result = bfs();
		if (result.first == -1 && result.second == -1) {
			if (visit_all()) {
				cout << point.first + 1 << " " << point.second + 1 << " " << pipe[i] << "\n";
				return 0;
			}
		}
	}
}
