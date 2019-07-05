#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
char map[105][105];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int visit[105][105];
int visitA[105][105];
int visitB[105][105];

typedef struct node {
	int x, y;
	int dist;
}NODE;
NODE A, B;

bool operator < (NODE a, NODE b) {
	return a.dist > b.dist;
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n + 2 || y >= m + 2)return false;
	return true;
}

void show() {
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < m + 2; j++) {
			cout << map[i][j] << "";
		}
		cout << "\n";
	}
	cout << "\n";
}

void bfs() {
	priority_queue<NODE> q;
	NODE start; start.x = 0; start.y = 0; start.dist = 0;
	visit[0][0] = 0;
	q.push(start);
	while (!q.empty()) {
		int cx = q.top().x;
		int cy = q.top().y;
		int cd = q.top().dist;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (!inside(nx, ny))continue;
			if (map[nx][ny] == '*')continue;
			if (map[nx][ny] == '.' || map[nx][ny] == 'A' || map[nx][ny] == 'B') {
				if (visit[nx][ny] > visit[cx][cy]) {
					visit[nx][ny] = visit[cx][cy];
					NODE nxt;
					nxt.x = nx; nxt.y = ny; nxt.dist = cd + 1;
					q.push(nxt);
				}
			}
			if (map[nx][ny] == '#') {
				if (visit[nx][ny] > visit[cx][cy] + 1) {
					visit[nx][ny] = visit[cx][cy] + 1;
					NODE nxt;
					nxt.x = nx; nxt.y = ny; nxt.dist = cd + 1;
					q.push(nxt);
				}
			}
		}
	}
}

void bfsA() {
	priority_queue<NODE>q;
	A.dist = 0;
	visitA[A.x][A.y] = 0;
	q.push(A);
	while (!q.empty()) {
		int cx = q.top().x;
		int cy = q.top().y;
		int cd = q.top().dist;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (!inside(nx, ny))continue;
			if (map[nx][ny] == '*')continue;
			if (map[nx][ny] == '.' || map[nx][ny] == 'A' || map[nx][ny] == 'B') {
				if (visitA[nx][ny] > visitA[cx][cy]) {
					visitA[nx][ny] = visitA[cx][cy];
					NODE nxt;
					nxt.x = nx; nxt.y = ny; nxt.dist = cd + 1;
					q.push(nxt);
				}
			}
			if (map[nx][ny] == '#') {
				if (visitA[nx][ny] > visitA[cx][cy] + 1) {
					visitA[nx][ny] = visitA[cx][cy] + 1;
					NODE nxt;
					nxt.x = nx; nxt.y = ny; nxt.dist = cd + 1;
					q.push(nxt);
				}
			}
		}
	}
}

void bfsB() {
	priority_queue<NODE>q;
	B.dist = 0;
	visitB[B.x][B.y] = 0;
	q.push(B);
	while (!q.empty()) {
		int cx = q.top().x;
		int cy = q.top().y;
		int cd = q.top().dist;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (!inside(nx, ny))continue;
			if (map[nx][ny] == '*')continue;
			if (map[nx][ny] == '.' || map[nx][ny] == 'A' || map[nx][ny] == 'B') {
				if (visitB[nx][ny] > visitB[cx][cy]) {
					visitB[nx][ny] = visitB[cx][cy];
					NODE nxt;
					nxt.x = nx; nxt.y = ny; nxt.dist = cd + 1;
					q.push(nxt);
				}
			}
			if (map[nx][ny] == '#') {
				if (visitB[nx][ny] > visitB[cx][cy] + 1) {
					visitB[nx][ny] = visitB[cx][cy] + 1;
					NODE nxt;
					nxt.x = nx; nxt.y = ny; nxt.dist = cd + 1;
					q.push(nxt);
				}
			}
		}
	}
}

void showAnswer() {
	int answer = 1e9;
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < m + 2; j++) {
			int t = visit[i][j];
			int ta = visitA[i][j];
			int tb = visitB[i][j];
			if (t == 1e9 || ta == 1e9 || tb == 1e9)continue;
			if (map[i][j] == '#') {
				answer = min(answer, t + ta + tb - 2);
			}
			else {
				answer = min(answer, t + ta + tb);
			}
		}
	}
	cout << answer << "\n";
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	freopen("Text.txt", "r", stdin);
	
	int testCase; cin >> testCase;
	while (testCase--) {
		cin >> n >> m;
		int prisoner = 0;
		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < m + 2; j++) {
				map[i][j] = '.';
				visit[i][j] = 1e9;
				visitA[i][j] = 1e9;
				visitB[i][j] = 1e9;
			}
		}
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				cin >> map[i][j];
				if (map[i][j] == '$') {
					map[i][j] = 'A' + prisoner++;
				}
				if (map[i][j] == 'A') {
					A.x = i;
					A.y = j;
				}
				if (map[i][j] == 'B') {
					B.x = i;
					B.y = j;
				}
			}
		}
		bfs();
		bfsA();
		bfsB();
		showAnswer();
	}
}