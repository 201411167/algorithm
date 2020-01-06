#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int map[5][5];
bool visit[1000000];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };

void input() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= 5 || y >= 5) { return false; }
	else { return true; }
}

void show(vector<int> list) {
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << " ";
	}
	cout << "\n";
}

int answer = 0;
void dfs(int x, int y, int num, int cnt) {
	if (cnt == 6) {
		if (!visit[num]) {
			visit[num] = true;
			answer++;
		}
		return;
	}
	for (int d = 0; d < 4; d++) {
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];
		if (!inside(nx, ny))continue;
		int new_num = num * 10 + map[nx][ny];
		dfs(nx, ny, new_num, cnt + 1);
	}
}

void solve() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, map[i][j], 1);
		}
	}
	cout << answer;
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	solve();
	return 0;
}