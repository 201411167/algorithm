#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

#define pii pair<int,int>
int n, m;
char map[103][103];
int keys[26];
bool visit[103][103];

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n + 2 || y >= m + 2) { return false; }
	return true;
}

void init_visit() {
	for(int i=0;i<103;i++){
		for (int j = 0; j < 103; j++) {
			visit[i][j] = false;
		}
	}
}

void init_keys() {
	for (int i = 0; i < 26; i++) {
		keys[i] = 0;
	}
}

int bfs() {
	int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
	int ret = 0;
	queue<pii>q;
	q.push({ 0,0 });
	visit[0][0] = true;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = cx + dir[d][0];
			int ny = cy + dir[d][1];
			if (!inside(nx, ny))continue;
			if (map[nx][ny] == '*')continue;
			if (map[nx][ny] == '.') {
				if (!visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
			if ('a' <= map[nx][ny] && map[nx][ny] <= 'z') {
				if (!visit[nx][ny]) {
					if (keys[map[nx][ny] - 'a'] == 0) {
						keys[map[nx][ny] - 'a'] = 1;
						map[nx][ny] = '.';
						init_visit();
					}
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
			if ('A' <= map[nx][ny] && map[nx][ny] <= 'Z') {
				if (!visit[nx][ny]) {
					if (keys[map[nx][ny] - 'A'] == 1) {
						map[nx][ny] = '.';
						visit[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
			if (map[nx][ny] == '$') {
				if (!visit[nx][ny]) {
					visit[nx][ny] = true;
					map[nx][ny] = '.';
					ret++;
					q.push({ nx,ny });
				}
			}
		}
	}
	return ret;
}

void show() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	freopen("Text.txt", "r", stdin);
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	int testCase; cin >> testCase;
	while (testCase--) {
		cin >> n >> m;
		init_visit();
		init_keys();
		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < m + 2; j++) {
				map[i][j] = '.';
			}
		}
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				cin >> map[i][j];
			}
		}
		string key; cin >> key;
		if(key.compare("0") != 0) {
			for (int i = 0; i < key.length(); i++) {
				keys[key[i] - 'a'] = 1;
			}
		}
		cout << bfs() << "\n";
	}
}