#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int n, m, w;
vector<int> T[1001];
vector<int> R[1001];
int cost[1001];
int indegree[1001];

void bfs() {
	queue<int> q;

	for (int i = 1; i <= 1000; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < T[cur].size(); i++) { // exploring to the next node
			int nxt = T[cur][i];
			indegree[nxt]--;
			if (indegree[nxt] == 0) {
				int maxCost = 0;
				for (int j = 0; j < R[nxt].size(); j++) {
					int pre = R[nxt][j];
					if (maxCost < cost[pre])
						maxCost = cost[pre];
				}
				cost[nxt] += maxCost;
				q.push(nxt);
			}
		}
	}
}

void clean() {
	for (int i = 0; i < 1001; i++) {
		T[i].clear();
		R[i].clear();
		cost[i] = 0;
		indegree[i] = 0;
	}
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	freopen("Text.txt", "r", stdin);

	int testCase; cin >> testCase;
	while (testCase--) {
		clean();
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			int c; cin >> c;
			cost[i] = c;
		}
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			T[a].push_back(b);
			R[b].push_back(a);
			indegree[b]++;
		}
		cin >> w;

		bfs();
		cout << cost[w] << "\n";
	}

	return 0;
}