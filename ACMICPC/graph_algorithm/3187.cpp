#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int n, m;
char map[251][251];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

bool inside(int x, int y) { if (x < 0 || y < 0 || x >= n || y >= m)return false; return true; }

pii fight() {
	int final_sheep = 0;
	int final_wolf = 0;
	bool visit[251][251] = { false, };
	queue<pii>q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != '#' && !visit[i][j]) {
				int sheep = 0;
				int wolf = 0;
				visit[i][j] = true;
				q.push({ i,j });
				while (!q.empty()) {
					int cx = q.front().first;
					int cy = q.front().second;
					q.pop();
					if (map[cx][cy] == 'k')sheep++;
					if (map[cx][cy] == 'v')wolf++;
					for (int d = 0; d < 4; d++) {
						int nx = cx + dir[d][0];
						int ny = cy + dir[d][1];
						if (!inside(nx, ny))continue;
						if (map[nx][ny] == '#')continue;
						if (!visit[nx][ny]) {
							visit[nx][ny] = true;
							q.push({ nx,ny });
						}
					}
				}
				if (wolf >= sheep)sheep = 0;
				if (wolf < sheep)wolf = 0;
				final_sheep += sheep;
				final_wolf += wolf;
			}
		}
	}
	return { final_sheep, final_wolf };
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	pii answer = fight();
	cout << answer.first << " " << answer.second;
	return 0;
}