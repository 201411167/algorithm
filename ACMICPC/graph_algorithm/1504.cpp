#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define pii pair<int,int>
int n, m;
vector <pii> T[801];
int dist[801];
int v1, v2;

struct NODE { int x; int cost; };
bool operator < (NODE a, NODE b) { return a.cost > b.cost; }

int path_v1_v2() {
	for (int i = 0; i <= n; i++) { dist[i] = 1e9; }
	dist[1] = 0;
	NODE S;
	S.x = 1; S.cost = 0;
	priority_queue<NODE> Q;
	Q.push(S);
	while (!Q.empty()) {
		NODE cur = Q.top();
		Q.pop();
		for (int i = 0; i < T[cur.x].size(); i++) {
			int nxt = T[cur.x][i].first;
			int cost = T[cur.x][i].second;
			if (dist[nxt] > dist[cur.x] + cost) {
				dist[nxt] = dist[cur.x] + cost;
				NODE V;
				V.x = nxt; V.cost = dist[nxt];
				Q.push(V);
			}
		}
	}
	int until_v1 = dist[v1];
	for (int i = 0; i <= n; i++) { dist[i] = 1e9; }
	dist[v1] = until_v1;
	S.x = v1; S.cost = dist[v1];
	Q.push(S);
	while (!Q.empty()) {
		NODE cur = Q.top();
		Q.pop();
		for (int i = 0; i < T[cur.x].size(); i++) {
			int nxt = T[cur.x][i].first;
			int cost = T[cur.x][i].second;
			if (dist[nxt] > dist[cur.x] + cost) {
				dist[nxt] = dist[cur.x] + cost;
				NODE V;
				V.x = nxt; V.cost = dist[nxt];
				Q.push(V);
			}
		}
	}
	int until_v2 = dist[v2];
	for (int i = 0; i <= n; i++) { dist[i] = 1e9; }
	dist[v2] = until_v2;
	S.x = v2; S.cost = dist[v2];
	Q.push(S);
	while (!Q.empty()) {
		NODE cur = Q.top();
		Q.pop();
		for (int i = 0; i < T[cur.x].size(); i++) {
			int nxt = T[cur.x][i].first;
			int cost = T[cur.x][i].second;
			if (dist[nxt] > dist[cur.x] + cost) {
				dist[nxt] = dist[cur.x] + cost;
				NODE V;
				V.x = nxt; V.cost = dist[nxt];
				Q.push(V);
			}
		}
	}
	return dist[n];
};

int path_v2_v1() {
	for (int i = 0; i <= n; i++) { dist[i] = 1e9; }
	dist[1] = 0;
	NODE S;
	S.x = 1; S.cost = 0;
	priority_queue<NODE> Q;
	Q.push(S);
	while (!Q.empty()) {
		NODE cur = Q.top();
		Q.pop();
		for (int i = 0; i < T[cur.x].size(); i++) {
			int nxt = T[cur.x][i].first;
			int cost = T[cur.x][i].second;
			if (dist[nxt] > dist[cur.x] + cost) {
				dist[nxt] = dist[cur.x] + cost;
				NODE V;
				V.x = nxt; V.cost = dist[nxt];
				Q.push(V);
			}
		}
	}
	int until_v2 = dist[v2];
	for (int i = 0; i <= n; i++) { dist[i] = 1e9; }
	dist[v2] = until_v2;
	S.x = v2; S.cost = dist[v2];
	Q.push(S);
	while (!Q.empty()) {
		NODE cur = Q.top();
		Q.pop();
		for (int i = 0; i < T[cur.x].size(); i++) {
			int nxt = T[cur.x][i].first;
			int cost = T[cur.x][i].second;
			if (dist[nxt] > dist[cur.x] + cost) {
				dist[nxt] = dist[cur.x] + cost;
				NODE V;
				V.x = nxt; V.cost = dist[nxt];
				Q.push(V);
			}
		}
	}
	int until_v1 = dist[v1];
	for (int i = 0; i <= n; i++) { dist[i] = 1e9; }
	dist[v1] = until_v1;
	S.x = v1; S.cost = dist[v1];
	Q.push(S);
	while (!Q.empty()) {
		NODE cur = Q.top();
		Q.pop();
		for (int i = 0; i < T[cur.x].size(); i++) {
			int nxt = T[cur.x][i].first;
			int cost = T[cur.x][i].second;
			if (dist[nxt] > dist[cur.x] + cost) {
				dist[nxt] = dist[cur.x] + cost;
				NODE V;
				V.x = nxt; V.cost = dist[nxt];
				Q.push(V);
			}
		}
	}
	return dist[n];
};

int main() {
	freopen("Text.txt", "r", stdin);
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, c; cin >> u >> v >> c;
		T[u].push_back({ v,c });
		T[v].push_back({ u,c });
	}
	cin >> v1 >> v2;
	
	int a= path_v1_v2();
	int b= path_v2_v1();
	int answer = min(a, b);
	if (answer == 1e9) {
		cout << -1;
	}
	else {
		cout << answer;
	}
	return 0;
}