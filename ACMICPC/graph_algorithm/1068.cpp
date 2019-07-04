#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> T[51];
int root;
int erase;
bool never[51];
int child[51];
int parent[51];

void bfs(int x) { // erase
	bool visit[51] = { false, };
	visit[erase] = true;
	queue<int>q;
	q.push(erase);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		never[cur] = true;
		child[parent[cur]]--;
		for (int i = 0; i < T[cur].size(); i++) {
			int nxt = T[cur][i];
			if (visit[nxt] == false) {
				visit[nxt] = true;
				q.push(nxt);
			}
		}
	}
}

int answer = 0;
void show() {
	for (int i = 0; i < n; i++) {
		if (never[i] == false && child[i] == 0) { // nodes which are reachable and leaf node
			answer++;
		}
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int par; cin >> par;
		child[par]++;
		parent[i] = par;
		if (par == -1) {
			root = i;
		}
		else {
			T[par].push_back(i);
		}
	}
	cin >> erase;

	bfs(erase);
	show();
	cout << answer << "\n";
	return 0;
}