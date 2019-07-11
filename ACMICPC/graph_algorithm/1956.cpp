#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int n, m;
int dist[401][401];

void init() {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dist[i][j] = 1e9;
		}
	}
}

void floyd_warshall() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

int main() {
	std::cin.tie(0); std::ios::sync_with_stdio(0);
	freopen("Text.txt", "r", stdin);

	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++) { int u, v, c; cin >> u >> v >> c; dist[u][v] = c; }

	floyd_warshall();

	int answer = 1e9;
	for (int i = 1; i <= n; i++) {
		answer = min(answer, dist[i][i]);
	}
	if (answer == 1e9) cout << -1;
	else cout << answer;
}