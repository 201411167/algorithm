#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<char>>map;
bool visit[8][8];
int dir[9][2] = { {0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,0} };

void input() {
	for (int i = 0; i < 8; i++) {
		vector<char>tmp;
		for (int j = 0; j < 8; j++) {
			char item; cin >> item;
			tmp.push_back(item);
		}
		map.push_back(tmp);
	}
}

void show() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= 8 || y >= 8)return false;
	return true;
}

vector<vector<char>> down(vector<vector<char>>map) {
	for (int i = 7; i > 0; i--) {
		map[i] = map[i - 1];
	}
	map[0].clear();
	for (int i = 0; i < 8; i++) {
		map[0].push_back('.');
	}
	return map;
}

int result = 0;
bool finish = false;
void dfs(int x, int y, vector<vector<char>>map) {
	if (x == 0) {
		result = 1;
		finish = true;
		return;
	}
	if (map[x][y] == '#') { 
		return; 
	}
	if (finish) {
		return;
	}

	for (int d = 0; d < 9; d++) {
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];
		if (!inside(nx, ny))continue;
		if (map[nx][ny] == '#')continue;
		dfs(nx, ny, down(map));
	}
}

void solve() {
	input();
	visit[7][0] = true;
	dfs(7, 0, map);;
	cout << result;
}

int main() {
	freopen("Text.txt", "r", stdin);
	solve();
	return 0;
}