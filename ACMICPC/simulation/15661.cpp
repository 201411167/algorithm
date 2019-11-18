#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int abilities[21][21];
bool visit[21];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> abilities[i][j];
		}
	}
}

void init_visit() {
	for (int i = 0; i < 21; i++) {
		visit[i] = false;
	}
}

int diff = 1e9;
void pick(int person, int depth, int total) { //전체 n명중에 total명 구하는 경우
	if (depth == total) {
		int a = 0;
		int b = 0;
		for (int i = 1; i <= n; i++) {
			if (visit[i]) {
				for (int j = 1; j <= n; j++) {
					if (visit[j]) {
						a += abilities[i][j];
					}
				}
			}
			if (!visit[i]) {
				for (int j = 1; j <= n; j++) {
					if (!visit[j]) {
						b += abilities[i][j];
					}
				}
			}
		}
		diff = min(diff, abs(a - b));
	}
	for (int i = person + 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			pick(i, depth + 1, total);
			visit[i] = false;
		}
	}
}

void solve() {
	for (int i = 1; i <= n / 2; i++) {
		pick(0, 0, i);
	}
	cout << diff;
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	solve();
	return 0;
}