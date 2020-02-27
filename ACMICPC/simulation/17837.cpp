#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, k;
int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
struct HORSE {
	int num;
	int x, y;
	int d;
};
bool operator <(HORSE A, HORSE B) {
	return A.num < B.num;
}
vector<HORSE>horses;

struct INFO {
	int color;
	vector<int> list;
};
INFO map[13][13];

void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j].color;
		}
	}
	for (int i = 0; i < k; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		x--;
		y--;
		d--;
		map[x][y].list.push_back(i + 1);
		horses.push_back({ i + 1,x,y,d });
	}
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n)return false;
	return true;
}

bool is_end() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j].list.size() >= 4) {
				return true;
			}
		}
	}
	return false;
}

void solve() {
	int time = 0;
	while (1) {
		if (is_end()) {
			cout << time;
			return;
		}
		if (time > 1000) {
			cout << -1;
			return;
		}
		time++;
		sort(horses.begin(), horses.end());
		for (int i = 0; i < horses.size(); i++) {
			int num = horses[i].num;
			int cx = horses[i].x;
			int cy = horses[i].y;
			int nx = horses[i].x + dir[horses[i].d][0];
			int ny = horses[i].y + dir[horses[i].d][1];
			if (!inside(nx, ny) || map[nx][ny].color == 2) {
				if (horses[i].d == 0) { horses[i].d = 1; }
				else if (horses[i].d == 1) { horses[i].d = 0; }
				else if (horses[i].d == 2) { horses[i].d = 3; }
				else { horses[i].d = 2; }
				nx = horses[i].x + dir[horses[i].d][0];
				ny = horses[i].y + dir[horses[i].d][1];
				if (!inside(nx, ny) || map[nx][ny].color == 2)continue;
			}
			if (map[nx][ny].color == 0) {
				int idx = -1;
				for (int j = 0; j < map[cx][cy].list.size(); j++) {
					if (map[cx][cy].list[j] == num) {
						idx = j;
					}
				}
				for (int j = idx; j < map[cx][cy].list.size(); j++) {
					map[nx][ny].list.push_back(map[cx][cy].list[j]);
					for (int k = 0; k < horses.size(); k++) {
						if (horses[k].num == map[cx][cy].list[j]) {
							horses[k].x = nx;
							horses[k].y = ny;
						}
					}
				}
				while (map[cx][cy].list.back() != num) {
					map[cx][cy].list.pop_back();
				}
				map[cx][cy].list.pop_back();
			}
			if (map[nx][ny].color == 1) {
				int idx = -1;
				for (int j = 0; j < map[cx][cy].list.size(); j++) {
					if (map[cx][cy].list[j] == num) {
						idx = j;
					}
				}
				for (int j = map[cx][cy].list.size() - 1; j >= idx; j--) {
					map[nx][ny].list.push_back(map[cx][cy].list[j]);
					for (int k = 0; k < horses.size(); k++) {
						if (horses[k].num == map[cx][cy].list[j]) {
							horses[k].x = nx;
							horses[k].y = ny;
						}
					}
				}
				while (map[cx][cy].list.back() != num) {
					map[cx][cy].list.pop_back();
				}
				map[cx][cy].list.pop_back();
			}
			if (is_end()) {
				cout << time;
				return;
			}
		}
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	solve();
	return 0;
}