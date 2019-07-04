#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 101
#define pii pair<int,int>
int n;
int map[MAX][MAX];
int visit[MAX][MAX];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

struct pos {
	int x, y;
	int dist;
};

bool operator <(pos a, pos b) {
	return a.dist > b.dist;
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n)return false;
	return true;
}

void clear_visit() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = 0;
		}
	}
}

void labeling() {
	int label = 0;
	queue <pii> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 0 && visit[i][j] == 0) {
				label++;
				q.push({ i,j });
				while (!q.empty()) {
					int cx = q.front().first;
					int cy = q.front().second;
					q.pop();
					map[cx][cy] = label;
					for (int i = 0; i < 4; i++) {
						int nx = cx + dx[i];
						int ny = cy + dy[i];
						if (!inside(nx, ny))continue;
						if (map[nx][ny] != 0 &&	visit[nx][ny] == 0) {
							visit[nx][ny] = 1;
							q.push({ nx,ny });
						}
					}
				}
			}
		}
	}
	clear_visit();
}

int find_short(int x, int y) {
	if (map[x][y] == 0) return -1;
	bool on_beach = false;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!inside(nx, ny))continue;
			if (map[nx][ny] == 0) {
				on_beach = true;
			}
		}
	}
	if (!on_beach) return -1;

	pos start;
	start.x = x;
	start.y = y;
	start.dist = 0;
	int from = map[start.x][start.y];

	priority_queue<pos>q;
	q.push(start);
	visit[start.x][start.y] = 1;
	while (!q.empty()) {
		pos cur = q.top();
		pos nxt;
		q.pop();
		if (map[cur.x][cur.y] != 0 && map[cur.x][cur.y] != from) {
			clear_visit();
			return cur.dist - 1;
		}
		for (int i = 0; i < 4; i++) {
			nxt.x = cur.x + dx[i];
			nxt.y = cur.y + dy[i];
			if (!inside(nxt.x, nxt.y))continue;
			if (map[nxt.x][nxt.y] == 0 && visit[nxt.x][nxt.y] == 0) {
				visit[nxt.x][nxt.y] = 1;
				nxt.dist = cur.dist + 1;
				q.push(nxt);
			}
			if (map[nxt.x][nxt.y] != 0 && map[nxt.x][nxt.y] != from && visit[nxt.x][nxt.y] == 0) {
				visit[nxt.x][nxt.y] = 1;
				nxt.dist = cur.dist + 1;
				q.push(nxt);
			}
		}
	}
	return -1;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	input();
	labeling();

	int answer = 1e9;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int result = find_short(i, j);
			if (result != -1) {
				answer = min(answer, result);
			}
		}
	}
	cout << answer;
	return 0;
}