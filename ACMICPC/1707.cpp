#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define V 20001
#define E 200001

int n, m;
vector<int>T[V];
int Agroup[V];
int Bgroup[V];

void init() {
	for (int i = 0; i < V; i++) {
		T[i].clear();
		Agroup[i] = 0;
		Bgroup[i] = 0;
	}
}

int bfs(int x) {
	Agroup[x] = 1;
	queue<int>q;
	q.push(x);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < T[cur].size(); i++) {
			int nxt = T[cur][i];
			if (Agroup[cur] == 1 && Agroup[nxt] == 1) {
				while (!q.empty()) q.pop();
				return -1;
			}
			if (Bgroup[cur] == 1 && Bgroup[nxt] == 1) {
				while (!q.empty()) q.pop();
				return -1;
			}
			if (Agroup[cur] == 1 && Bgroup[nxt] == 0) {
				Bgroup[nxt] = 1;
				q.push(nxt);
			}
			if (Bgroup[cur] == 1 && Agroup[nxt] == 0) {
				Agroup[nxt] = 1;
				q.push(nxt);
			}
		}
	}
	return 0;
}

int main() {
	freopen("Text.txt", "r", stdin);
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	int testCase; cin >> testCase;
	while (testCase--) {
		cin >> n >> m;
		init();
		for (int i = 0; i < m; i++) {
			int u, v; cin >> u >> v;
			T[u].push_back(v);
			T[v].push_back(u);
		}
		int result = 0;
		for (int i = 1; i <= n; i++) {
			if (Agroup[i] == 0 && Bgroup[i] == 0) {
				if (bfs(i) == -1) {
					result = -1;
				}
			}
		}
		if (result == 0) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}