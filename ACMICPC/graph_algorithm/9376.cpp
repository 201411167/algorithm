#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 105
#define pii pair<int,int>
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };

int n, m;
char map[MAX][MAX];
int visit[MAX][MAX];
int visit_a[MAX][MAX];
int visit_b[MAX][MAX];
int ax, ay, bx, by;

struct info {
	int x, y;
	int distance;
};

bool operator < (info a, info b) {
	return a.distance > b.distance;
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n + 2 | y >= m + 2) return false;
	return true;
}

void init() {
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < m + 2; j++) {
			visit[i][j] = 1e9;
			visit_a[i][j] = 1e9;
			visit_b[i][j] = 1e9;
		}
	}
}

void makeEmpty() {
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < m + 2; j++) {
			map[i][j] = '.';
		}
	}
}

void showAnswer() {
	int answer = 1e9;
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < m + 2; j++) {
			if (visit[i][j] == 1e9 || visit_a[i][j] == 1e9 || visit_b[i][j] == 1e9)continue;
			if (map[i][j] == '#') {
				answer = min(answer, visit[i][j] + visit_a[i][j] + visit_b[i][j] - 2);
			}
			else {
				answer = min(answer, visit[i][j] + visit_a[i][j] + visit_b[i][j]);
			}
		}
	}
	cout << answer << "\n";
}

void bfs() {
	priority_queue<info>q;
	info start;
	start.x = 0; start.y = 0; start.distance = 0;
	visit[0][0] = 0;
	q.push(start);
	while (!q.empty()) {
		info cur = q.top();
		info nxt;
		int cx = q.top().x;
		int cy = q.top().y;
		int cd = q.top().distance;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (!inside(nx, ny))continue;
			if (map[nx][ny] == '*')continue;
			if (map[nx][ny] == 'A' || map[nx][ny] == 'B' || map[nx][ny] == '.') {
				if (visit[nx][ny] > visit[cx][cy]) {
					visit[nx][ny] = visit[cx][cy];
					nxt.x = nx; nxt.y = ny; nxt.distance = cd + 1;
					q.push(nxt);
				}
			}
			if (map[nx][ny] == '#') {
				if (visit[nx][ny] > visit[cx][cy] + 1) {
					visit[nx][ny] = visit[cx][cy] + 1;
					nxt.x = nx; nxt.y = ny; nxt.distance = cd + 1;
					q.push(nxt);
				}
			}
		}
	}
}

void bfsA(int x, int y) {
	priority_queue<info>q;
	info start;
	start.x = x; start.y = y; start.distance = 0;
	visit_a[x][y] = 0;
	q.push(start);
	while (!q.empty()) {
		info cur = q.top();
		info nxt;
		int cx = q.top().x;
		int cy = q.top().y;
		int cd = q.top().distance;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (!inside(nx, ny))continue;
			if (map[nx][ny] == '*')continue;
			if (map[nx][ny] == 'A' || map[nx][ny] == 'B' || map[nx][ny] == '.') {
				if (visit_a[nx][ny] > visit_a[cx][cy]) {
					visit_a[nx][ny] = visit_a[cx][cy];
					nxt.x = nx; nxt.y = ny; nxt.distance = cd + 1;
					q.push(nxt);
				}
			}
			if (map[nx][ny] == '#') {
				if (visit_a[nx][ny] > visit_a[cx][cy] + 1) {
					visit_a[nx][ny] = visit_a[cx][cy] + 1;
					nxt.x = nx; nxt.y = ny; nxt.distance = cd + 1;
					q.push(nxt);
				}
			}
		}
	}
}

void bfsB(int x, int y) {
	priority_queue<info>q;
	info start;
	start.x = x; start.y = y; start.distance = 0;
	visit_b[x][y] = 0;
	q.push(start);
	while (!q.empty()) {
		info cur = q.top();
		info nxt;
		int cx = q.top().x;
		int cy = q.top().y;
		int cd = q.top().distance;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (!inside(nx, ny))continue;
			if (map[nx][ny] == '*')continue;
			if (map[nx][ny] == 'A' || map[nx][ny] == 'B' || map[nx][ny] == '.') {
				if (visit_b[nx][ny] > visit_b[cx][cy]) {
					visit_b[nx][ny] = visit_b[cx][cy];
					nxt.x = nx; nxt.y = ny; nxt.distance = cd + 1;
					q.push(nxt);
				}
			}
			if (map[nx][ny] == '#') {
				if (visit_b[nx][ny] > visit_b[cx][cy] + 1) {
					visit_b[nx][ny] = visit_b[cx][cy] + 1;
					nxt.x = nx; nxt.y = ny; nxt.distance = cd + 1;
					q.push(nxt);
				}
			}
		}
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	int testCase; cin >> testCase;
	while (testCase--) {
		cin >> n >> m;
		makeEmpty();
		int prisoner = 0;
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				cin >> map[i][j];
				if (map[i][j] == '$') {
					map[i][j] = 'A' + prisoner;
					prisoner++;
				}
				if (map[i][j] == 'A') {
					ax = i;
					ay = j;
				}
				if (map[i][j] == 'B') {
					bx = i;
					by = j;
				}
			}
		}
		init();
		bfs();
		bfsA(ax, ay);
		bfsB(bx, by);
		showAnswer();
	}
	return 0;
}