#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int n, m;
int map[301][301];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
bool check[301][301]; // for water to melt the iceberg
bool visit[301][301]; // for exploring the iceberg

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)return false;
	return true;
}

void melt() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			check[i][j] = false;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 && check[i][j] == false) {
				check[i][j] = true;
				for (int k = 0; k < 4; k++) {
					int x = i + dx[k];
					int y = j + dy[k];
					if (!inside(x, y))continue;
					if (map[x][y] > 0) {
						map[x][y]--;
						if (map[x][y] == 0) {
							check[x][y] = true;
						}
					}
				}
			}
		}
	}
}

int get_size() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = false;
		}
	}
	queue<pii>q;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0 && visit[i][j] == false) {
				visit[i][j] = true;
				ret++;
				q.push({ i,j });
				while (!q.empty()) {
					int cx = q.front().first;
					int cy = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cx + dx[k];
						int ny = cy + dy[k];
						if (!inside(nx, ny))continue;
						if (map[nx][ny] == 0)continue;
						if (map[nx][ny] != 0 && visit[nx][ny] == false) {
							visit[nx][ny] = true;
							q.push({ nx,ny });
						}
					}
				}
			}
		}
	}
	return ret;
}

bool all_melt() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}

int melting() {
	int ret = 0;
	while (1) {
		if (all_melt()) { return 0; }
		if (get_size() > 1) { break; }
		melt();
		ret++;
	}

	return ret;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	freopen("Text.txt", "r", stdin);
	input();
	cout << melting();
	return 0;
}