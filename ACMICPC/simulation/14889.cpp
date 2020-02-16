#include <iostream>
#include <algorithm>
using namespace std;

int n;
int ability[21][21];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ability[i][j];
		}
	}
}

bool chk[21];
int answer = 1e9;
void pick(int idx, int cnt) {
	if (cnt == n / 2) {
		int teamA = 0;
		int teamB = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)continue;
				if (chk[i] && chk[j]) {
					teamA += ability[i][j];
				}
				if (!chk[i] && !chk[j]) {
					teamB += ability[i][j];
				}
			}
		}
		answer = min(answer, abs(teamA - teamB));
	}
	else {
		for (int i = idx; i < n; i++) {
			if (chk[i])continue;
			chk[i] = true;
			pick(i, cnt + 1);
			chk[i] = false;
		}
	}
}

void solve() {
	pick(0, 0);
	cout << answer;
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	solve();
}