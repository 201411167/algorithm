#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int n;
long long d[31][31]; // d[w_num][h_num] w_num개의 w와 h_num개의 h로 만들 수 있는 경우의 수

//int solve(int w, int h, int day, int goal) {
//	if (day == goal) {
//		return 1;
//	}
//	if (w < n && h == n) {
//		return solve(w + 1, h, day + 1, goal);
//	}
//	if (w == n && h < n) {
//		return solve(w, h + 1, day + 1, goal);
//	}
//	else {
//		if (w == h) {
//			return solve(w + 1, h, day + 1, goal);
//		}
//		if (w > h) {
//			return solve(w + 1, h, day + 1, goal) + solve(w, h + 1, day + 1, goal);
//		}
//	}
//}


void solve() {
	for (int i = 1; i <= 30; i++) {
		d[i][1] = i;
	}
	for (int i = 2; i <= 30; i++) {
		for (int j = 2; j < i; j++) {
			d[i][j] = d[i][j - 1] + d[i - 1][j];
		}
		d[i][i] = d[i][i - 1];
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	solve();
	while (1) {
		cin >> n;
		if (n == 0)break;
		cout << d[n][n] << "\n";
		//cout << solve(0,0,0,2 * n) << "\n";
	}
	return 0;
}