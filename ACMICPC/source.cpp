#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
#define piii pair<int, pair<int,int>>
int n;
int map[101][101];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n)return false;
	return true;
}

void labeling() {
	bool visit[101][101] = { false, };
	int numbering = 0;
	queue<pii> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && visit[i][j] == false) {
				numbering++;
				visit[i][j] = true;
				q.push({ i,j });
				while (!q.empty()) {
					int cx = q.front().first;
					int cy = q.front().second;
					q.pop();
					map[cx][cy] = numbering;
					for (int i = 0; i < 4; i++) {
						int nx = cx + dx[i];
						int ny = cy + dy[i];
						if (!inside(nx, ny))continue;
						if (visit[nx][ny] == false && map[nx][ny] == 1) {
							visit[nx][ny] = true;
							q.push({ nx,ny });
						}
					}
				}
			}
		}
	}
}

bool near_beach(int x, int y) {
	bool ret = false;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!inside(nx, ny))continue;
		if (map[nx][ny] == 0) {
			ret = true;
		}
	}
	return ret;
}

int shortest_path(int x, int y) {
	int ret = 1e9;
	priority_queue<piii> q;
	bool visit[101][101] = { false, };
	int from = map[x][y];
	q.push({ 0,{x,y} });
	while (!q.empty()) {
		int cx = q.top().second.first;
		int cy = q.top().second.second;
		int cd = -q.top().first;
		q.pop();
		if (map[cx][cy] != 0 && map[cx][cy] != from) {
			ret = min(ret, cd - 1);
			return ret;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (!inside(nx, ny))continue;
			if (map[nx][ny] == from)continue;
			if (map[nx][ny] == 0 && visit[nx][ny] == 0) {
				visit[nx][ny] = 1;
				q.push({ -cd - 1, {nx,ny} });
			}
			if (map[nx][ny] != 0 && visit[nx][ny] == 0) {
				visit[nx][ny] = 1;
				q.push({ -cd - 1, {nx,ny} });
			}
		}
	}
}

int make_bridge() {
	int ret = 1e9;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 0 && near_beach(i,j)) {
				ret = min(ret, shortest_path(i, j));
			}
		}
	}
	return ret;
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	freopen("Text.txt", "r", stdin);

	input();
	labeling();
	cout << make_bridge();
}