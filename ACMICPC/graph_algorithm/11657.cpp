	#include <iostream>
	#include <queue>
	#include <vector>
	#include <algorithm>
	using namespace std;

	#define pii pair<int,int>
	int n, m;
	vector<pii>T[501];
	int cost[501];

	int main() {
		freopen("Text.txt", "r", stdin);
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b, c; cin >> a >> b >> c;
			T[a].push_back({ b,c });
		}
		for (int i = 1; i <= n; i++) {
			cost[i] = 1e9;
		}
		cost[1] = 0;
		bool cycle = false;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (auto k : T[j]) {
					if (cost[j] != 1e9 && cost[k.first] > k.second + cost[j]) {
						cost[k.first] = k.second + cost[j];
						if (i == n) cycle = true;
					}
				}
			}
		}
		if (cycle) cout << -1 << "\n";
		else {
			for (int i = 2; i <= n; i++) {
				if (cost[i] == 1e9)cout << "-1" << "\n";
				else cout << cost[i] << "\n";
			}
		}
	}