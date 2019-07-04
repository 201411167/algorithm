#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int n, m;
int s, d;
vector<pii> T[501];
vector<pii> R[501];
int dist[501];
int edge_to_remove[501][501];

void init_dist() {
	for (int i = 0; i < 501; i++) {
		dist[i] = 1e9;
	}
	dist[s] = 0;
}

void edge_init() {
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			edge_to_remove[i][j] = 0;
		}
	}
}

void vector_init() {
	for (int i = 0; i < 501; i++) {
		T[i].clear();
		R[i].clear();
	}
}

void bfs() {
	priority_queue<pii> q; //first = cost, second = node
	q.push({ 0,s });
	dist[s] = 0;
	while (!q.empty()) {
		int cur = q.top().second;
		int cost = -q.top().first;
		q.pop();
		for (int i = 0; i < T[cur].size(); i++) {
			int nxt = T[cur][i].first;
			int nxtCost = T[cur][i].second;
			if (edge_to_remove[cur][nxt] == 1)continue;
			if (dist[nxt] > dist[cur] + nxtCost) {
				dist[nxt] = dist[cur] + nxtCost;
				q.push({ -dist[nxt],nxt });
			}
		}
	}
}

void find_shortest_path() { 
	queue <int>q;
	q.push(d);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < R[cur].size(); i++) {
			int pre = R[cur][i].first;
			int payed = R[cur][i].second;
			if (edge_to_remove[pre][cur] == 0 && dist[pre] + payed == dist[cur]) {
				edge_to_remove[pre][cur] = 1;
				q.push(pre);
			}
		}
	}
}


int main() {
	freopen("Text.txt", "r", stdin);
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	
	while (true) {
		cin >> n >> m;
		if (n == 0 && n == 0)break;
		cin >> s >> d;
		init_dist();
		vector_init();
		edge_init();
		for (int i = 0; i < m; i++) {
			int u, v, p; cin >> u >> v >> p;
			T[u].push_back({ v,p });
			R[v].push_back({ u,p });
		}

		bfs();
		find_shortest_path();
		init_dist();
		bfs();

		if (dist[d] != 1e9)
			cout << dist[d] << "\n";
		else
			cout << -1 << "\n";
	}

	return 0;
}