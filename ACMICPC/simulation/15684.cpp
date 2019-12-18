#include <iostream>
#include <queue>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;

int n, m, rows;
bool able[33][13];

void input() {
	cin >> m >> rows >> n;
	for (int i = 0; i < rows; i++) {
		int a, b; cin >> a >> b;
		able[a][b] = true;
	}
}

bool possible() {
	vector<int>line;
	for (int i = 0; i <= m; i++) {
		line.push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < m; j++) {
			if (able[i][j]) {
				int tmp = line[j];
				line[j] = line[j + 1];
				line[j + 1] = tmp;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		if (line[i] != i) { return false; }
	}
	return true;
}

int answer = 1e9;
void go(int r, int c, int count) {
	if (count > 3)return;
	if (answer == 0)return;
	if (possible()) {
		answer = min(answer, count);
	}
	for (int i = r; i <= n; i++) {
		for (int j = c; j < m; j++) {
			if (able[i][j]) {
				continue;
			}
			else if (!able[i][j - 1] && !able[i][j] && !able[i][j + 1]) {
				able[i][j] = true;
				go(i, j - 1, count + 1);
				able[i][j] = false;
			}
		}
	}
}

void solve() {
	go(1, 1, 0);
	if (answer == 1e9) {
		cout << -1;
	}
	else {
		cout << answer;
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	solve();
	return 0;
}