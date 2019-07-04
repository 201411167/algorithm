#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int n, m;
int map[51][51];
int visit[51][51];
// 0-west, 1-north, 2-east, 3-south
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return false;
	return true;
}

void clear_visit() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = 0;
		}
	}
}

void input() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

int bfs(int x, int y) {
	int ret = 0;
	queue<pii> q;
	q.push({ x,y });
	visit[x][y] = 1;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		ret++;
		int wall = map[cx][cy];
		for (int i = 0; i < 4; i++) {
			if (wall & (1 << i))continue; // there is a wall on direction[i]
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (!inside(nx, ny))continue;
			if (visit[nx][ny] == 0) {
				visit[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}x
	return ret;
}

pii room_count() {
	pii ret;
	ret = { 0,0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == 0) {
				ret.first++;
				int size = bfs(i, j);
				if (size > ret.second)
					ret.second = size;
			}
		}
	}
	clear_visit();
	return ret;
}

int biggest_size_without_one_wall() {
	int ret = 0;
	// about the whole walls in this map
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int origin_wall = map[i][j];
			// should remove the wall to the one side
			for (int k = 0; k < 4; k++) {
				// when there is a wall on k side -> remove the wall on k side -> find answer -> recover the origin wall value
				if (map[i][j] & (1 << k)) {
					map[i][j] = (map[i][j] & ~(1 << k));
					int size = room_count().second;
					if (ret < size) {
						ret = size;
					}
					map[i][j] = origin_wall;
				}
			}
		}
	}
	return ret;
}

int main() {
	freopen("Text.txt", "r", stdin);
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	input();
	pii result = room_count();
	cout << result.first << "\n" << result.second << "\n";
	cout << biggest_size_without_one_wall();
	

	return 0;
}