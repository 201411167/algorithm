#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int n, m;
char map[101][101];
bool visit[101][101];
int dir[8][2] = { {-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)return false;
	return true;
}

bool input() {
	cin >> n >> m;
	if (n == 0 && m == 0)return false;
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
			}
		}
		return true;
	}
}

void init_visit() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			visit[i][j] = false;
		}
	}
}

int solve() {
	int ret = 0;
	queue<pii>q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '@' && visit[i][j] == false) {
				ret++;
				visit[i][j] = true;
				q.push({ i,j });
				while (!q.empty()) {
					int cx = q.front().first;
					int cy = q.front().second;
					q.pop();
					for (int d = 0; d < 8; d++) {
						int nx = cx + dir[d][0];
						int ny = cy + dir[d][1];
						if (!inside(nx, ny))continue;
						if (map[nx][ny] == '@') {
							if (!visit[nx][ny]) {
								visit[nx][ny] = true;
								q.push({ nx,ny });
							}
						}
					}
				}
			}
		}
	}
	return ret;
}

int main() {
	freopen("Text.txt", "r", stdin);
	while (input()) {
		init_visit();
		cout << solve() << "\n";
	}
	return 0;
}