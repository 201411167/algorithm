#include <iostream>
#include <algorithm>
using namespace std;

int n, len;
int map[101][101];

void input() {
	cin >> n >> len;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n)return false;
	return true;
}

bool flat_row(int x, int y1, int y2) {
	int initial = map[x][y1];
	for (int i = y1; i <= y2; i++) {
		if (map[x][i] != initial) {
			return false;
		}
	}
	return true;
}

bool flat_col(int y, int x1, int x2) {
	int initial = map[x1][y];
	for (int i = x1; i <= x2; i++) {
		if (map[i][y] != initial) {
			return false;
		}
	}
	return true;
}

int explore_row() {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == n - 1) {
				//cout << "R[" << i << "]\n";
				ret++;
			}
			else {
				if (map[i][j] == map[i][j + 1]) {
					continue;
				}
				else if (map[i][j] + 1 == map[i][j + 1]) {
					int a = j - len - len + 1;
					int b = j - len;
					int c = j - len + 1;
					int d = j;
					if (!inside(c, d) || !flat_row(i, c, d)) { break; }
					bool stop = false;
					for (int k = a; k <= b; k++) {
						if (inside(k, b)) {
							if (map[i][k] == map[i][j] + 1) {
								stop = true;
							}
						}
					}
					if (stop) { break; }
				}
				else if (map[i][j] - 1 == map[i][j + 1]) {
					int a = j + 1;
					int b = j + len;
					int c = j + len + 1;
					int d = j + len + len;
					if (!inside(a, b) || !flat_row(i, a, b)) { break; }
					bool stop = false;
					for (int k = c; k <= d; k++) {
						if (inside(k, d)) {
							if (map[i][k] == map[i][j]) {
								stop = true;
							}
						}
					}
					if (stop) { break; }
				}
				else {
					break;
				}
			}
		}
	}
	return ret;
}

int explore_col() {
	int ret = 0;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (i == n - 1) {
				//cout << "C[" << j << "]\n";
				ret++;
			}
			else {
				if (map[i][j] == map[i + 1][j]) {
					continue;
				}
				else if (map[i][j] + 1 == map[i + 1][j]) {
					int a = i - len - len + 1;
					int b = i - len;
					int c = i - len + 1;
					int d = i;
					if (!inside(c, d) || !flat_col(j, c, d)) { break; }
					bool stop = false;
					for (int k = a; k <= b; k++) {
						if (inside(k, b)) {
							if (map[k][j] == map[i][j] + 1) {
								stop = true;
							}
						}
					}
					if (stop) { break; }
				}
				else if (map[i][j] - 1 == map[i + 1][j]) {
					int a = i + 1;
					int b = i + len;
					int c = i + len + 1;
					int d = i + len + len;
					if (!inside(a, b) || !flat_col(j, a, b)) { break; }
					bool stop = false;
					for (int k = c; k <= d; k++) {
						if (inside(k, d)) {
							if (map[k][j] == map[i][j]) {
								stop = true;
							}
						}
					}
					if (stop) { break; }
				}
				else {
					break;
				}
			}
		}
	}
	return ret;
}

void solve() {
	input();
	cout << explore_row() + explore_col();
}

int main() {
	//freopen("Text.txt", "r", stdin);
	solve();
	return 0;
}