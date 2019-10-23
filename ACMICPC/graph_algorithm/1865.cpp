#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define pii pair<int,int>
int dist[501];
bool cycle = false;
vector<pii>T[501];
int n, m, w;

int main() {
	freopen("Text.txt", "r", stdin);
	int tc; cin >> tc;
	while (tc--) {
		cycle = false;
		cin >> n >> m >> w;
		for (int i = 0; i < 501; i++) {
			T[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int s, e, t; cin >> s >> e >> t;
			T[s].push_back({ e,t });
			T[e].push_back({ s,t });

		}
		for (int i = 0; i < w; i++) {
			int s, e, t; cin >> s >> e >> t;
			T[s].push_back({ e,-t });
		}

		for (int i = 2; i <= n; i++) {
			dist[i] = 1e9;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				for (auto k : T[j]) {
					int there = k.first;
					int d = k.second;
					if (dist[j] != 1e9 && (dist[there] > dist[j] + d)) {
						dist[there] = dist[j] + d;
						if (i == n)cycle = true;
					}
				}
			}
		}
		if (cycle)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}