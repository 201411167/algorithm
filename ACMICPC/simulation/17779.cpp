#include <iostream>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int n;
pii map[21][21];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j].second;
			map[i][j].first = 5;
		}
	}
}

bool isAbleToDivide(int x, int y, int d1, int d2) {
	if (1 <= d1 && 1 <= d2 &&
		1 <= x && x < x + d1 && x < x + d2 && x + d1 < x + d1 + d2 && x + d2 < x + d1 + d2 && x + d1 + d2 <= n &&
		1 <= y - d1 && y - d1 < y && y < y + d2 && y + d2 <= n) {
		return true;
	}
	else {
		return false;
	}
}

void divide(int x, int y, int d1, int d2) {
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			if (x <= r && r <= x + d1 + d2 && y - d1 <= c && c <= y + d2 && x + y <= r + c && r + c <= x + y + d2 + d2 &&
				x + y <= r + c && r + c <= x + y + d2 + d2 &&
				x - y <= r - c && r - c <= x - y + d1 + d1) {
				map[r][c].first = 5;
			}
			else {
				if (1 <= r && r < x + d1 && 1 <= c && c <= y) {
					map[r][c].first = 1;
				}
				if (1 <= r && r <= x + d2 && y < c && c <= n) {
					map[r][c].first = 2;
				}
				if (x + d1 <= r && r <= n && 1 <= c && c < y - d1 + d2) {
					map[r][c].first = 3;
				}
				if (x + d2 < r && r <= n && y - d1 + d2 <= c && c <= n) {
					map[r][c].first = 4;
				}
			}
		}
	}
}

void solve() {
	int diff = 1e9;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int a = 1; a <= n; a++) {
				for (int b = 1; b <= n; b++) {
					int one = 0;
					int two = 0;
					int three = 0;
					int four = 0;
					int five = 0;
					int biggest = 0;
					int smallest = 1e9;
					if (isAbleToDivide(i, j, a, b)) {
						divide(i, j, a, b);
						for (int x = 1; x <= n; x++) {
							for (int y = 1; y <= n; y++) {
								if (map[x][y].first == 1) {
									one += map[x][y].second;
								}
								if (map[x][y].first == 2) {
									two += map[x][y].second;
								}
								if (map[x][y].first == 3) {
									three += map[x][y].second;
								}
								if (map[x][y].first == 4) {
									four += map[x][y].second;
								}
								if (map[x][y].first == 5) {
									five += map[x][y].second;
								}
							}
						}
						biggest = max(one, max(two, max(three, max(four, five))));
						smallest = min(one, min(two, min(three, min(four, five))));
						diff = min(diff, biggest - smallest);
					}
				}
			}
		}
	}
	cout << diff;
}

int main() {
	//freopen("Text.txt", "r", stdin);
	input();
	solve();
	return 0;
}