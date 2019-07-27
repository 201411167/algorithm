#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int FOE[1001][1001]; // 1 for friend, -1 for enemy

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		char foe;
		int a, b;
		cin >> foe >> a >> b;
		if (foe == 'F') {
			FOE[a][b] = 1;
			FOE[b][a] = 1;
		}
		if (foe == 'E') {
			FOE[a][b] = -1;
			FOE[b][a] = -1;
		}
	}
}

void who_is_friend() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (FOE[i][k] == 1 && FOE[k][j] == 1) {
					FOE[i][j] = 1;
					FOE[j][i] = 1;
				}
				if (FOE[i][k] == -1 && FOE[k][j] == -1) {
					FOE[i][j] = 1;
					FOE[j][i] = 1;
				}
			}
		}
	}
}

bool visit[1001];
void bfs(int x) {
	queue<int>q;
	q.push(x);
	visit[x] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			int nxt = i;
			if (nxt == cur)continue;
			if (FOE[cur][nxt] == 1) {
				if (!visit[nxt]) {
					visit[nxt] = true;
					q.push(nxt);
				}
			}
		}
	}
}

int solution() {
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			answer++;
			bfs(i);
		}
	}
	return answer++;
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	who_is_friend();
	cout << solution();
	return 0;
}