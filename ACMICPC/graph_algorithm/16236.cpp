#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[21][21];
bool visit[21][21];
int dir[4][2] = { {-1,0},{0,-1},{0,1},{1,0} };
int sx, sy;

#define piii pair<int, pair<int,int>>
typedef struct { int x, y, dist; }FISH;
bool operator <(FISH a, FISH b) {
	if (a.dist == b.dist) {
		if (a.x == b.x) {
			return a.y < b.y;
		}
		return a.x < b.x;
	}
	return a.dist < b.dist;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				map[i][j] = 0;
				sx = i; sy = j;
			}
		}
	}
}

void init_visit() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = false;
		}
	}
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n)return false;
	return true;
}

piii bfs(int size, int x, int y) {
	vector<FISH>v;
	queue<FISH>q;
	q.push({ x,y,0 });
	visit[x][y] = true;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cd = q.front().dist;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = cx + dir[d][0];
			int ny = cy + dir[d][1];
			if (!inside(nx, ny))continue;
			if (map[nx][ny] > size)continue;
			if (map[nx][ny] == 0 || map[nx][ny] == size) {
				if (!visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ nx,ny,cd + 1 });
				}
			}
			if (map[nx][ny] < size && map[nx][ny] != 0) {
				if (!visit[nx][ny]) {
					visit[nx][ny] = true;
					v.push_back({ nx,ny,cd + 1 });
				}
			}
		}
	}
	init_visit();
	if (v.empty()) {
		return { -1,{-1,-1} };
	}
	else {
		sort(v.begin(), v.end());
		return{ v[0].dist, {v[0].x, v[0].y} };
	}
}

void solution() {
	int x = sx;
	int y = sy;
	int eat = 0;
	int size = 2;
	int dist = 0;
	piii result;
	while (1) {
		result = bfs(size, x, y);
		if (result.first == -1)break;
		int nx = result.second.first;
		int ny = result.second.second;
		dist += result.first;
		if (eat + 1 == size) {
			eat = 0;
			size++;
			map[nx][ny] = 0;
			x = nx;
			y = ny;
		}
		else {
			eat++;
			map[nx][ny] = 0;
			x = nx;
			y = ny;
		}
	}
	cout << dist;
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	solution();
	return 0;
}