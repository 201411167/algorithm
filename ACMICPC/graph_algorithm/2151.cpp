#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define pii pair<int,int>

int n;
char map[51][51];
int sx, sy;
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
bool visit[51][51][4];

typedef struct NODE {
	int x, y;
	int direction;
	int mirror;
}LIGHT;

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n)return false;
	return true;
}

void input() {
	cin >> n;
	int door = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') {
				map[i][j] = 'A' + door++;
				if (map[i][j] == 'A') {
					sx = i; sy = j;
				}
			}
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

int bfs() {
	int answer = 1e9;
	LIGHT start; 
	start.x = sx; start.y = sy; start.mirror = 0;
	for (int i = 0; i < 4; i++) {
		int nx = start.x + dir[i][0];
		int ny = start.y + dir[i][1];
		if (!inside(nx, ny)) { continue; }
		if (map[nx][ny] == '*') { continue; }
		start.direction = i;
	}
	visit[start.x][start.y][start.direction] = true;

	queue<LIGHT>q;
	q.push(start);
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cd = q.front().direction;
		int cm = q.front().mirror;
		q.pop();
		if (map[cx][cy] == 'B') {
			answer = min(answer, cm);
		}

		int nx = cx;
		int ny = cy;
		while (1) {
			nx = nx + dir[cd][0];
			ny = ny + dir[cd][1];
			if (!inside(nx, ny)) { break; }
			if (map[nx][ny] == '*') {
				nx = nx - dir[cd][0];
				ny = ny - dir[cd][1];
				break;
			}
			if (map[nx][ny] == '.' || map[nx][ny] == 'B') {
				LIGHT nxt;
				nxt.x = nx; nxt.y = ny; nxt.direction = cd; nxt.mirror = cm;
				if (visit[nxt.x][nxt.y][nxt.direction] == false) {
					visit[nxt.x][nxt.y][nxt.direction] = true;
					q.push(nxt);
				}
			}
			if (map[nx][ny] == '!') {
				LIGHT nxt;
				nxt.x = nx; nxt.y = ny; nxt.direction = cd; nxt.mirror = cm;
				if (visit[nxt.x][nxt.y][nxt.direction] == false) {
					visit[nxt.x][nxt.y][nxt.direction] = true;
					q.push(nxt);
				}
				nxt.x = nx; nxt.y = ny; nxt.direction = cd + 1; nxt.mirror = cm + 1;
				if (nxt.direction > 3) nxt.direction = 0;
				if (visit[nxt.x][nxt.y][nxt.direction] == false) {
					visit[nxt.x][nxt.y][nxt.direction] = true;
					q.push(nxt);
				}
				nxt.x = nx; nxt.y = ny; nxt.direction = cd - 1; nxt.mirror = cm + 1;
				if (nxt.direction < 0) nxt.direction = 3;
				if (visit[nxt.x][nxt.y][nxt.direction] == false) {
					visit[nxt.x][nxt.y][nxt.direction] = true;
					q.push(nxt);
				}
			}
		}
	}
	return answer;
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	freopen("Text.txt", "r", stdin);

	input();
	cout << bfs();
	
	return 0;
}