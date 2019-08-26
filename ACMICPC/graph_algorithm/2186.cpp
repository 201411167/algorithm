#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, k;
int answer;
int dp[101][101][81];
char map[101][101];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
string goal;
int goal_len;

void input() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	cin >> goal;
	goal_len = goal.length();
	memset(dp, -1, sizeof(dp));
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)return false;
	return true;
}

int dfs(int x, int y, int idx) {
	if (dp[x][y][idx] != -1)return dp[x][y][idx];
	if (idx >= goal_len)return 1;

	dp[x][y][idx] = 0;
	for (int d = 0; d < 4; d++) {
		for (int l = 1; l <= k; l++) {
			int nx = x + dir[d][0] * l;
			int ny = y + dir[d][1] * l;
			if (!inside(nx, ny))continue;
			if (map[nx][ny] != goal[idx])continue;
			dp[x][y][idx] += dfs(nx, ny, idx + 1);
		}
	}

	return dp[x][y][idx];
}

void solution() {
	char temp = goal[0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == temp) {
				answer += dfs(i, j, 1);
			}
		}
	}
	cout << answer;
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	solution();
	return 0;
}