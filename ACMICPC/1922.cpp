#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

#define MAX 1001
int n, m;
int parent[MAX];

typedef struct egde {
	int a, b, w;
}edge;
edge E[100001];

bool comp_edge (edge a, edge b) {
	return a.w < b.w;
}

int find(int x) {
	if (x == parent[x])return x;
	return find(parent[x]);
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	freopen("Text.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> E[i].a >> E[i].b >> E[i].w;
	}
	sort(E, E + m, comp_edge);
	
	int answer = 0;
	for (int i = 0; i < m; i++) {
		int u = find(E[i].a);
		int v = find(E[i].b);
		int c = E[i].w;

		if (u != v) {
			parent[u] = v;
			answer += c;
		}
	}

	cout << answer;


	return 0;
}