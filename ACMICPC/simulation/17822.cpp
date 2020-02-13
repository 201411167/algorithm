#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, t;
vector<int> T[51];
struct action {
	int x, d, k;
};
vector<action> actions;

void input() {
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num; cin >> num;
			T[i].push_back(num);
		}
	}
	for (int i = 0; i < t; i++) {
		int xi, di, ki;
		cin >> xi >> di >> ki;
		actions.push_back({ xi,di,ki });
	}
}

void delete_adj() {
	// 인접비교
	bool same[51][51];
	memset(same, false, sizeof(same));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < T[i].size(); j++) {
			if (i < n - 1) {
				if (T[i][j] == T[i + 1][j]) {
					same[i][j] = true;
					same[i + 1][j] = true;
				}
				if (j < T[i].size() - 1) {
					if (T[i][j] == T[i][j + 1]) {
						same[i][j] = true;
						same[i][j + 1] = true;
					}
				}
				if (j == T[i].size() - 1) {
					if (T[i][j] == T[i][0]) {
						same[i][j] = true;
						same[i][0] = true;
					}
				}
			}
			if (i == n - 1) {
				if (j < T[i].size() - 1) {
					if (T[i][j] == T[i][j + 1]) {
						same[i][j] = true;
						same[i][j + 1] = true;
					}
				}
				if (j == T[i].size() - 1) {
					if (T[i][j] == T[i][0]) {
						same[i][j] = true;
						same[i][0] = true;
					}
				}
			}
		}
	}
	// 인접하면서 같은 수가 있는지 확인
	bool noSame = true;
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			if (same[i][j] && T[i][j] != -1) {
				noSame = false;
				T[i][j] = -1;
			}
		}
	}
	// 인접하면서 같은 수가 없는 경우
	if (noSame) {
		float average = 0.0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < T[i].size(); j++) {
				if (T[i][j] == -1)continue;
				average += T[i][j];
				cnt++;
			}
		}
		average = average / cnt;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < T[i].size(); j++) {
				if (T[i][j] == -1)continue;
				if (T[i][j] > average) {
					T[i][j]--;
				}
				else if (T[i][j] < average) {
					T[i][j]++;
				}
			}
		}
	}
}

void turn(int x, int d, int k) {
	if (d == 0) { //시계방향
		for (int i = 0; i < k; i++) {
			int right = T[x][T[x].size() - 1];
			for (int j = T[x].size() - 1; j > 0; j--) {
				T[x][j] = T[x][j - 1];
			}
			T[x][0] = right;
		}
	}
	if (d == 1) { //반시계방향
		for (int i = 0; i < k; i++) {
			int left = T[x][0];
			for (int j = 0; j < T[x].size() - 1; j++) {
				T[x][j] = T[x][j + 1];
			}
			T[x][T[x].size() - 1] = left;
		}
	}
}

void solve() {
	for (int i = 0; i < t; i++) {
		int x = actions[i].x;
		int d = actions[i].d;
		int k = actions[i].k;
		for (int j = 1; j <= n; j++) {
			if (j % x == 0) {
				turn(j - 1, d, k);
			}
		}
		delete_adj();
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < T[i].size(); j++) {
			if (T[i][j] == -1)continue;
			answer += T[i][j];
		}
	}
	cout << answer << "\n";;
}

int main() {
	//freopen("Text.txt", "r", stdin);
	input();
	solve();
	return 0;
}