#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct BATTERY {
	int x, y;
	int range;
	int power;
}BT[11];
bool operator < (BATTERY a, BATTERY b) {
	return a.power > b.power;
}
int answer;
int walk;
int cnt;
int dir[5][2] = { {0,0},{-1,0},{0,1},{1,0},{0,-1} };
int user1x = 0;
int user1y = 0;
int user2x = 9;
int user2y = 9;
queue<int>user1;
queue<int>user2;

void init() {
	user1x = 0;
	user1y = 0;
	user2x = 9;
	user2y = 9;
	answer = 0;
}

void input() {
	cin >> walk >> cnt;
	for (int i = 0; i < walk; i++) {
		int tmp; cin >> tmp;
		user1.push(tmp);
	}
	for (int i = 0; i < walk; i++) {
		int tmp; cin >> tmp;
		user2.push(tmp);
	}
	for (int i = 0; i < cnt; i++) {
		int x, y, r, p; cin >> x >> y >> r >> p;
		x--; 
		y--;
		BT[i].x = y;
		BT[i].y = x;
		BT[i].range = r;
		BT[i].power = p;
	}
}

bool inner_bt_zone(int i, int x, int y) { // battery index, position_x, position_y
	int distance = abs(BT[i].x - x) + abs(BT[i].y - y);
	if (distance <= BT[i].range) {
		return true;
	}
	return false;
}

void solution() {
	sort(BT, BT + cnt);
	int user1_p = -1;
	int user1_s = -1;
	int user2_p = -1;
	int user2_s = -1;

	for (int i = 0; i < cnt; i++) {
		if (inner_bt_zone(i, user1x, user1y)) {
			if (user1_p == -1) {
				user1_p = i;
			}
			else if (user1_s == -1) {
				user1_s = i;
			}
		}
		if (inner_bt_zone(i, user2x, user2y)) {
			if (user2_p == -1) {
				user2_p = i;
			}
			else if (user2_s == -1) {
				user2_s = i;
			}
		}
	}

	int tmp = 0;
	if (user1_p != -1 && user2_p == -1) {
		tmp += BT[user1_p].power;
	}
	if (user1_p == -1 && user2_p != -1) {
		tmp += BT[user2_p].power;
	}
	if (user1_p != -1 && user2_p != -1) {
		if (user1_p == user2_p) {
			if (user1_s == -1 && user2_s == -1) {
				tmp += BT[user1_p].power;
			}
			if (user1_s != -1 && user2_s == -1) {
				tmp += BT[user1_s].power + BT[user2_p].power;
			}
			if (user1_s == -1 && user2_s != -1) {
				tmp += BT[user1_p].power + BT[user2_s].power;
			}
			if (user1_s != -1 && user2_s != -1) {
				if (BT[user1_s].power > BT[user2_s].power) {
					tmp += BT[user1_s].power + BT[user2_p].power;
				}
				else {
					tmp += BT[user1_p].power + BT[user2_s].power;
				}
			}
		}
		else {
			tmp += BT[user1_p].power + BT[user2_p].power;
		}
	}
	answer += tmp;

	while (!user1.empty() || !user2.empty()) {
		int d1 = user1.front();
		user1.pop();
		user1x += dir[d1][0];
		user1y += dir[d1][1];

		int d2 = user2.front();
		user2.pop();
		user2x += dir[d2][0];
		user2y += dir[d2][1];

		int user1_p = -1;
		int user1_s = -1;
		int user2_p = -1;
		int user2_s = -1;

		for (int i = 0; i < cnt; i++) {
			if (inner_bt_zone(i, user1x, user1y)) {
				if (user1_p == -1) {
					user1_p = i;
				}
				else if (user1_s == -1) {
					user1_s = i;
				}
			}
			if (inner_bt_zone(i, user2x, user2y)) {
				if (user2_p == -1) {
					user2_p = i;
				}
				else if (user2_s == -1) {
					user2_s = i;
				}
			}
		}
		
		int tmp = 0;
		if (user1_p != -1 && user2_p == -1) {
			tmp += BT[user1_p].power;
		}
		if (user1_p == -1 && user2_p != -1) {
			tmp += BT[user2_p].power;
		}
		if (user1_p != -1 && user2_p != -1) {
			if (user1_p == user2_p) {
				if (user1_s == -1 && user2_s == -1) {
					tmp += BT[user1_p].power;
				}
				if (user1_s != -1 && user2_s == -1) {
					tmp += BT[user1_s].power + BT[user2_p].power;
				}
				if (user1_s == -1 && user2_s != -1) {
					tmp += BT[user1_p].power + BT[user2_s].power;
				}
				if (user1_s != -1 && user2_s != -1) {
					if (BT[user1_s].power > BT[user2_s].power) {
						tmp += BT[user1_s].power + BT[user2_p].power;
					}
					else {
						tmp += BT[user1_p].power + BT[user2_s].power;
					}
				}
			}
			else {
				tmp += BT[user1_p].power + BT[user2_p].power;
			}
		}
		answer += tmp;
	}
}

void solve() {
	int testCase; cin >> testCase;
	for (int idx = 1; idx <= testCase; idx++) {
		init();
		input();
		solution();
		cout << "#" << idx << " " << answer << "\n";
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	solve();
	return 0;
}