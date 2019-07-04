#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
#define MAX 100001
int n, m;
vector<pii>T[MAX];
int start, goal;

bool bfs(int low, int high) {
	bool ret = false;
	bool visit[MAX] = { false, };
	visit[start] = true;
	queue<int>q;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == goal) {
			ret = true;
		}
		for (int i = 0; i < T[cur].size(); i++) {
			int nxt = T[cur][i].first;
			int cost = T[cur][i].second;
			if (!visit[nxt]) {
				if (high <= cost || low <= cost) {
					visit[nxt] = true;
					q.push(nxt);
				}
			}
		}
	}
	return ret;
}

int binary(int low, int high) {
	if (low >= high) {
		return low;
	}
	else {
		int mid = (low + high) / 2;
		bool possible_on_right = bfs(mid + 1, high);
		if (possible_on_right) {
			binary(mid + 1, high);
		}
		else {
			binary(low, mid);
		}
	}
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	freopen("Text.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		T[u].push_back({ v,w });
		T[v].push_back({ u,w });
	}
	cin >> start >> goal;
	cout << binary(0, 1e9);
	return 0;
}