#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int par[100001];
struct edge {
	int u, v, w;
}E[1000001];
bool operator <(edge a, edge b) {
	return a.w < b.w;
}

int find(int x) {
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	freopen("Text.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> E[i].u >> E[i].v >> E[i].w;
	}
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
	sort(E, E + m);

	int answer = 0;
	for (int i = 0; i < m && 2 < n; i++) {
		int a = find(E[i].u);
		int b = find(E[i].v);
		int c = E[i].w;
		if (a != b) {
			n--;
			par[b] = a;
			answer += c;
		}
	}
	cout << answer;
}