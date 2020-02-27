#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define MAX 101
using namespace std;

int r, c, k, answer;
int A[MAX][MAX];
int cnt[MAX];

void input() {
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> A[i][j];
		}
	}
}

void find() {
	int time = 0;
	int row = 3;
	int col = 3;
	while (1) {
		if (A[r][c] == k) {
			answer = time;
			break;
		}
		if (time > 100) {
			answer = -1;
			break;
		}
		vector<int>size;
		if (row >= col) {
			for (int i = 1; i <= row; i++) {
				vector<pair<int, int>>v;
				memset(cnt, 0, sizeof(cnt));
				for (int j = 1; j <= col; j++) {
					cnt[A[i][j]]++;
				}
				for (int j = 1; j < MAX; j++) {
					if (cnt[j] == 0)continue;
					v.push_back({ cnt[j], j });
				}
				sort(v.begin(), v.end());
				for (int j = 1; j <= col; j++) {
					A[i][j] = 0;
				}
				int idx = 1;
				for (int j = 0; j < v.size(); j++) {
					A[i][idx++] = v[j].second;
					A[i][idx++] = v[j].first;
				}
				idx--;
				size.push_back(idx);
			}
			sort(size.begin(), size.end());
			col = size.back();
		}
		else {
			for (int i = 1; i <= col; i++) {
				vector<pair<int, int>>v;
				memset(cnt, 0, sizeof(cnt));
				for (int j = 1; j <= row; j++) {
					cnt[A[j][i]]++;
				}
				for (int j = 1; j < MAX; j++) {
					if (cnt[j] == 0)continue;
					v.push_back({ cnt[j],j });
				}
				sort(v.begin(), v.end());
				for (int j = 1; j <= row; j++) {
					A[j][i] = 0;
				}
				int idx = 1;
				for (int j = 0; j < v.size(); j++) {
					A[idx++][i] = v[j].second;
					A[idx++][i] = v[j].first;
				}
				idx--;
				size.push_back(idx);
			}
			sort(size.begin(), size.end());
			row = size.back();
		}
		time++;
	}
}

void solve() {
	find();
	cout << answer;
}

int main() {
	//freopen("Text.txt", "r", stdin);
	input();
	solve();
	return 0;
}