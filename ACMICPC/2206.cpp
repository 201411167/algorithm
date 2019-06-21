#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int n, m;
int map[1001][1001];
int visit[2][1001][1001];
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };

struct INFO {
	int x, y;
	int dist;
	int crush;
};

bool operator < (INFO a, INFO b) {
	return a.dist > b.dist;
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)return false;
	return true;
}

void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void show0() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int result = visit[0][i][j];
			if (result == 1e9) {
				cout << "! ";
			}
			else {
				cout << result << " ";
			}
		}
		cout << "\n";
	}
	cout << "\n";
}

void show1() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int result = visit[1][i][j];
			if (result == 1e9) {
				cout << "! ";
			}
			else {
				cout << result << " ";
			}
		}
		cout << "\n";
	}
	cout << "\n";
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[0][i][j] = 1e9;
			visit[1][i][j] = 1e9;
		}
	}
}

void bfs() {
	init();
	INFO start;
	visit[0][0][0] = 1;
	start.x = 0; start.y = 0; start.dist = 0; start.crush = 0;
	priority_queue<INFO>q;
	q.push(start);
	while (!q.empty()) {
		INFO cur = q.top();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (!inside(nx, ny))continue;
			if (cur.crush == 0) {
				if (map[nx][ny] == 0) {
					if (visit[0][nx][ny] > visit[0][cur.x][cur.y] + 1) {
						visit[0][nx][ny] = visit[0][cur.x][cur.y] + 1;
						INFO nxt;
						nxt.x = nx; nxt.y = ny; 
						nxt.dist = cur.dist + 1; 
						nxt.crush = cur.crush;
						q.push(nxt);
					}
					if (visit[1][nx][ny] > visit[0][cur.x][cur.y] + 1) {
						visit[1][nx][ny] = visit[0][cur.x][cur.y] + 1;
						INFO nxt;
						nxt.x = nx; nxt.y = ny;
						nxt.dist = cur.dist + 1;
						nxt.crush = cur.crush;
						q.push(nxt);
					}
				}
				if (map[nx][ny] == 1) {
					if (visit[1][nx][ny] > visit[0][cur.x][cur.y] + 1) {
						visit[1][nx][ny] = visit[0][cur.x][cur.y] + 1;
						INFO nxt;
						nxt.x = nx; nxt.y = ny;
						nxt.dist = cur.dist + 1;
						nxt.crush = cur.crush + 1;
						q.push(nxt);
					}
				}
			}
			if (cur.crush == 1) {
				if (map[nx][ny] == 0) {
					if (visit[1][nx][ny] > visit[1][cur.x][cur.y] + 1) {
						visit[1][nx][ny] = visit[1][cur.x][cur.y] + 1;
						INFO nxt;
						nxt.x = nx; nxt.y = ny;
						nxt.dist = cur.dist + 1;
						nxt.crush = cur.crush;
						q.push(nxt);
					}
				}
				if (map[nx][ny] == 1) {
					continue;
				}
			}
		}
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	bfs();
	//show();
	//show0();
	//show1();
	int answer = min(visit[0][n - 1][m - 1], visit[1][n - 1][m - 1]);
	if (answer == 1e9)
		cout << -1;
	else
		cout << answer;
	return 0;
}