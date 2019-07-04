#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m; // 101, 2001

int heavier[101][101] = { 0, }; // bigger[1][2] = '1' is heavier than '2' if heavier[1][2] = 1

int main() {
	freopen("Text.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		heavier[a][b] = 1;
		heavier[b][a] = -1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (heavier[i][k] == 1 && heavier[k][j] == 1) {
					heavier[i][j] = 1;
				}
				if (heavier[i][k] == -1 && heavier[k][j] == -1) {
					heavier[i][j] = -1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int not_defined = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			if (heavier[i][j] == 0) {
				not_defined++;
			}
		}
		cout << not_defined << "\n";
	}
	return 0;
}
