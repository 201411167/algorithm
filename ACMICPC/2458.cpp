#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int height[501][501] = { 0, };

int main() {
	freopen("Text.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		height[a][b] = 1;
		height[b][a] = -1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (height[i][k] == 1 && height[k][j] == 1) {
					height[i][j] = 1;
					height[j][i] = -1;
				}
				if (height[i][j] == -1 && height[k][j] == -1) {
					height[i][j] = -1;
					height[j][i] = 1;
				}
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		bool is_defined = true;
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			if (height[i][j] == 0) {// undefined 
				is_defined = false;
			}
		}
		if (is_defined) {
			answer++;
		}
	}
	cout << answer;
	return 0;
}