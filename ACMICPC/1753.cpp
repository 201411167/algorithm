#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int n, m;
int start;
vector<pii> T[20001];
int cost[20001];

void dijkstra() {
	for (int i = 1; i <= n; i++) {
		cost[i] = 1e9;
	}
	cost[start] = 0;

	priority_queue<pii> q;
	q.push({ 0,start });
	while (!q.empty()) {
		int cur = q.top().second;
		q.pop();
		for (int i = 0; i < T[cur].size(); i++) {
			int nxt = T[cur][i].first;
			int weight = T[cur][i].second;
			if (cost[nxt] > cost[cur] + weight) {
				cost[nxt] = cost[cur] + weight;
				q.push({ -cost[nxt], nxt });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (cost[i] == 1e9) {
			cout << "INF\n";
		}
		else {
			cout << cost[i] << "\n";
		}
	}
}

int main() {
	freopen("Text.txt", "r", stdin);

	cin >> n >> m;
	cin >> start;
	for (int i = 0; i < m; i++) {
		int u, v, c; cin >> u >> v >> c;
		T[u].push_back({ v,c });
	}

	dijkstra();

	return 0;
}