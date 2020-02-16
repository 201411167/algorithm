#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
int a[11][11];
int b[11][11];
vector<int>map[11][11];
int dir[8][2] = { {-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };

void input() {
	cin >> n >> m >> k; // map, trees, years
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z;
		x--;
		y--;
		map[x][y].push_back(z);
	}
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n)return false;
	return true;
}

void spring_and_summer() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j].size() == 0)continue;
			int die_tree = 0;
			vector<int>tmp;
			sort(map[i][j].begin(), map[i][j].end());
			for (int k = 0; k < map[i][j].size(); k++) {
				int age = map[i][j][k];
				if (a[i][j] >= age) {
					a[i][j] -= age;
					tmp.push_back(age + 1);
				}
				else {
					die_tree += age / 2;
				}
			}
			map[i][j].clear();
			for (int k = 0; k < tmp.size(); k++) {
				map[i][j].push_back(tmp[k]);
			}
			a[i][j] += die_tree;
		}
	}
}

void fall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j].size() == 0)continue;
			for (int k = 0; k < map[i][j].size(); k++) {
				int age = map[i][j][k];
				if (age % 5 == 0) {
					for (int d = 0; d < 8; d++) {
						int nx = i + dir[d][0];
						int ny = j + dir[d][1];
						if (!inside(nx, ny))continue;
						map[nx][ny].push_back(1);
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] += b[i][j];
		}
	}
}

void solve() {
	for (int i = 0; i < k; i++) {
		spring_and_summer();
		fall();
		winter();
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer += map[i][j].size();
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