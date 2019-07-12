#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int n, m;
int map[51][51];
int dir[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) { return false; }
	else { return true; }
}

int number_of_room() {
	int ret = 0;
	bool visit[51][51] = { false, };
	queue<pii>q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == false) {
				ret++;
				visit[i][j] = true;
				q.push({ i,j });
				while (!q.empty()) {
					int cx = q.front().first;
					int cy = q.front().second;
					q.pop();
					int wall = map[cx][cy];
					for (int d = 0; d < 4; d++) {
						int nx = cx + dir[d][0];
						int ny = cy + dir[d][1];
						if (!inside(nx, ny))continue;
						if (wall & (1 << d))continue;
						if (!visit[nx][ny]) {
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

int max_size() {
	int ret = 0;
	queue<pii>q;
	bool visit[51][51] = { false, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j]) {
				visit[i][j] = true;
				q.push({ i,j });
				int size = 0;
				while (!q.empty()) {
					int cx = q.front().first;
					int cy = q.front().second;
					q.pop();
					size++;
					int wall = map[cx][cy];
					for (int d = 0; d < 4; d++) {
						int nx = cx + dir[d][0];
						int ny = cy + dir[d][1];
						if (!inside(nx, ny))continue;
						if (wall & (1 << d))continue;
						if (!visit[nx][ny]) {
							visit[nx][ny] = true;
							q.push({ nx,ny });
						}
					}
				}
				ret = max(ret, size);
			}
		}
	}
	return ret;
}

int max_size_with_destroy() {
	int ret = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int origin_wall = map[i][j];
			for (int k = 0; k < 4; k++) {
				if (origin_wall & (1 << k)) {
					map[i][j] &= ~(1 << k);
					int size = max_size();
					ret = max(ret, size);
					map[i][j] = origin_wall;
				}
			}
		}
	}

	return ret;
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	freopen("Text.txt", "r", stdin);

	cin >> m >> n;
	for (int i = 0; i < n; i++) { {for (int j = 0; j < m; j++) { cin >> map[i][j]; }} }

	cout << number_of_room() << "\n";
	cout << max_size() << "\n";
	cout << max_size_with_destroy() << "\n";

	return 0;
}