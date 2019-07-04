#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 105

int n, m;
char map[MAX][MAX];
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };
int visit[MAX][MAX];
int key[26];

struct node {
	int x, y;
};
node start;

void makeEmpty() {
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < m + 2; j++) {
			map[i][j] = '.';
		}
	}
}

void init() {
	start.x = 0;
	start.y = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			visit[i][j] = 0;
		}
	}
	for (int i = 0; i < 26; i++) {
		key[i] = 0;
	}
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n + 2 || y >= m + 2)return false;
	return true;
}

int bfs() {
	int ret = 0;
	queue<node>q;
	q.push(start);
	visit[start.x][start.y] = 1;
	while (!q.empty()) {
		node cur = q.front();
		node nxt;
		int cx = cur.x;
		int cy = cur.y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (!inside(nx, ny))continue;
			if (map[nx][ny] == '*')continue;
			if (map[nx][ny] == '.') {
				if (visit[nx][ny] == 0) {
					visit[nx][ny] = 1;
					nxt.x = nx; nxt.y = ny;
					q.push(nxt);
				}
			}
			if ('a' <= map[nx][ny] && map[nx][ny] <= 'z') {
				if (visit[nx][ny] == 0) {
					if (key[int(map[nx][ny] - 'a')] == 0) {
						key[int(map[nx][ny] - 'a')] = 1;
						map[nx][ny] = '.';
						for (int i = 0; i < n + 2; i++) {
							for (int j = 0; j < m + 2; j++) {
								visit[i][j] = 0;
								if (map[i][j] == map[nx][ny] - 'a' + 'A') {
									map[i][j] = '.';
								}
							}
						}
					}
					visit[nx][ny] = 1;
					nxt.x = nx; nxt.y = ny;
					q.push(nxt);
				}
			}
			if ('A' <= map[nx][ny] && map[nx][ny] <= 'Z') {
				if (visit[nx][ny] == 0) {
					if (key[int(map[nx][ny] - 'A')] == 1) {
						map[nx][ny] = '.';
						visit[nx][ny] = 1;
						nxt.x = nx; nxt.y = ny;
						q.push(nxt);
					}
				}
			}
			if (map[nx][ny] == '$') {
				if (visit[nx][ny] == 0) {
					visit[nx][ny] = 1;
					map[nx][ny] = '.';
					ret++;
					nxt.x = nx; nxt.y = ny;
					q.push(nxt);
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

	int testCase; cin >> testCase;
	while (testCase--) {
		cin >> n >> m;
		makeEmpty();
		init();
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				cin >> map[i][j];
			}
		}
		string key_input; cin >> key_input;
		if (key_input.compare("0") != 0) {
			for (int i = 0; i < key_input.size(); i++) {
				key[int(key_input[i] - 'a')] = 1;
			}
		}
		cout << bfs() << "\n";
	}
}
