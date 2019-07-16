#include <iostream>
#include <algorithm>
using namespace std;

int n;
int connect[51][51];

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	freopen("Text.txt", "r", stdin);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char result; cin >> result;
			if (result == 'Y') { connect[i][j] = 1; }
			if (result == 'N') { connect[i][j] = 1e9; }
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)continue;
				if (i == k)continue;
				if (j == k)continue;
				if (connect[i][j] > connect[i][k] + connect[k][j]) {
					connect[i][j] = connect[i][k] + connect[k][j];
				}
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			if (connect[i][j] <= 2)
				tmp++;
		}
		answer = max(answer, tmp);
	}
	cout << answer;
}