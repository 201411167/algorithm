#include <iostream>
#include <algorithm>
using namespace std;

int n, x;
int horizontal_answer;
int vertical_answer;
int map[21][21];
bool block_use[21];

void init() {
	horizontal_answer = 0;
	vertical_answer = 0;
}

void init_block() {
	for (int i = 0; i < 21; i++) {
		block_use[i] = false;
	}
}

void input() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

bool possible_horizontally(int r) {
	//map[row][0] ~ map[row][n-1]
	init_block();
	for (int i = 1; i < n; i++) {
		if (map[r][i] == map[r][i - 1]) continue;
		if (abs(map[r][i] - map[r][i - 1]) > 1) return false;
		if (map[r][i] == map[r][i - 1] + 1) { // 1Ä­ ³ô¾ÆÁü
			if (i - x < 0) return false;
			for (int j = i - x; j < i; j++) {
				if (map[r][j] != map[r][i] - 1) return false;
				if (block_use[j]) return false;
				block_use[j] = true;
			}
		}
		if (map[r][i] == map[r][i - 1] - 1) { // 1Ä­ ³·¾ÆÁü
			if (i + x - 1 > n - 1) return false;
			for (int j = i; j < i + x; j++) {
				if (map[r][j] != map[r][i]) return false;
				if (block_use[j]) return false;
				block_use[j] = true;
			}
		}
	}
	return true;
}

bool possible_vertically(int c) {
	//map[0][column] ~ map[n-1][column]
	init_block();
	for (int i = 1; i < n; i++) {
		if (map[i][c] == map[i - 1][c]) continue;
		if (abs(map[i][c] - map[i - 1][c]) > 1) return false;
		if (map[i][c] == map[i - 1][c] + 1) { // 1Ä­ ³ô¾ÆÁü
			if (i - x < 0) return false;
			for (int j = i - x; j < i; j++) {
				if (map[j][c] != map[i][c] - 1) return false;
				if (block_use[j]) return false;
				block_use[j] = true;
			}
		}
		if (map[i][c] == map[i - 1][c] - 1) { // 1Ä­ ³·¾ÆÁü
			if (i + x - 1 > n - 1) return false;
			for (int j = i; j < i + x; j++) {
				if (map[j][c] != map[i][c]) return false;
				if (block_use[j]) return false;
				block_use[j] = true;
			}
		}
	}
	return true;
}

void solution() {
	for (int i = 0; i < n; i++) {
		if (possible_horizontally(i)) {
			horizontal_answer++;
		}
		if (possible_vertically(i)) {
			vertical_answer++;
		}
	}
}

void solve() {
	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		init();
		input();
		solution();
		cout << "#" << t << " " << horizontal_answer + vertical_answer << "\n";
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	solve();
}