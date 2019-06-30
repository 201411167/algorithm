#include <iostream>
using namespace std;

int a[40][40];

int main() {
	freopen("Text.txt", "r", stdin);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 40; j++) {
			a[i][j] = 0;
		}
	}
	for (int i = 0; i <= 40; i++) {
		a[1][i] = i;
	}
	for (int i = 2; i <= 40; i++) {
		for (int j = i; j <= 40; j++) {
			for (int k = i - 1; k < j; k++) {
				a[i][j] += a[i - 1][k];
			}
		}
	}

	int testCase; cin >> testCase;
	while (testCase--) {
		int n, m; cin >> n >> m;
		cout << a[n][m] << "\n";
	}
	return 0;
}