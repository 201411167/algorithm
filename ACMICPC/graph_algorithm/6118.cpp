#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int>T[20001];
int cost[20001];

struct NODE {
	int x;
	int dist;
};
bool operator < (NODE a, NODE b) {
	return a.dist > b.dist;
}

void bfs() {
	queue<NODE> q;
	NODE start;
	start.x = 1; start.dist = 0;
	cost[start.x] = 0;
	q.push(start);
	while (!q.empty()) {
		NODE cur = q.front();
		q.pop();
		for (int i = 0; i < T[cur.x].size(); i++) {
			int nxt = T[cur.x][i];
			if (cost[nxt] > cost[cur.x] + 1) {
				cost[nxt] = cost[cur.x] + 1;
				NODE next;
				next.x = nxt; next.dist = cost[nxt];
				q.push(next);
			}
		}
	}
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	freopen("Text.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		cost[i] = 1e9;
	}
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	bfs();
	int farthest_distance = 0;
	int farthest_place = -1;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (farthest_distance < cost[i]) {
			farthest_place = i;
			farthest_distance = cost[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (farthest_distance == cost[i]) {
			count++;
		}
	}
	cout << farthest_place << " " << farthest_distance << " " << count;
}
