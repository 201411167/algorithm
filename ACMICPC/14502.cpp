#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int,int>

int n, m;
int origin_map[10][10];
int map[10][10];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int visit_virus[10][10];

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)return false;
	return true;
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit_virus[i][j] = 0;
			map[i][j] = origin_map[i][j];
		}
	}
}

void virus_spread() {
	queue<pii>q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2 && visit_virus[i][j] == 0) {
				q.push({ i,j });
				visit_virus[i][j] = 1;
			}
		}
	}
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		map[cx][cy] = 2;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (!inside(nx, ny))continue;
			if (map[nx][ny] == 1)continue;
			if (map[nx][ny] == 2)continue;
			if (map[nx][ny] == 0 && visit_virus[nx][ny] == 0) {
				visit_virus[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
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

int main() {
	freopen("Text.txt", "r", stdin);
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> origin_map[i][j];
			map[i][j] = origin_map[i][j];
		}
	}
	int answer = 0;
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < m; b++) {
			for (int c = 0; c < n; c++) {
				for (int d = 0; d < m; d++) {
					for (int e = 0; e < n; e++) {
						for (int f = 0; f < m; f++) {
							if (a == c && b == d)continue;
							if (a == e && b == f)continue;
							if (c == e && d == f)continue;
							if (map[a][b] == 0 && map[c][d] == 0 && map[e][f] == 0) {
								map[a][b] = 1;
								map[c][d] = 1;
								map[e][f] = 1;
								virus_spread();
								int tmp = 0;
								for (int i = 0; i < n; i++) {
									for (int j = 0; j < m; j++) {
										if (map[i][j] == 0) {
											tmp++;
										}
									}
								}
								answer = max(answer, tmp);
								init();
							}
						}
					}
				}
			}
		}
	}
	cout << answer;
	return 0;
}