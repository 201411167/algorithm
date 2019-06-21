#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define pii pair<int,int>
int n, m;
vector<int>T[10001];

int bfs(int x) {
	int ret = 0;
	int visit[10001] = { 0, };
	queue<int>q;
	q.push(x);
	visit[x] = 1;
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		ret++;
		for (int i = 0; i < T[c].size(); i++) {
			int nxt = T[c][i];
			if (visit[nxt] == 0) {
				visit[nxt] = 1;
				q.push(nxt);
			}
		}
	}
	return ret;
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	freopen("Text.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		T[v].push_back(u);
	}

	priority_queue<pii>q;
	for (int i = 1; i <= n; i++) {
		int result = bfs(i);
		q.push({ result, -i });
	}
	int pre = q.top().first;
	while (!q.empty()) {
		if (q.top().first == pre) {
			cout << -q.top().second << " ";
		}
		q.pop();
	}
	return 0;
}