#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[51][51];
int b[51][51];
int answer = 0;

int main() {
	freopen("Text.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &b[i][j]);
		}
	}
	
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (a[i][j] != b[i][j]) {
				answer++;
				for (int x = i; x < i + 3; x++) {
					for (int y = j; y < j + 3; y++) {
						if (a[x][y] = (a[x][y] + 1) % 2);
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << answer;
	return 0;
}