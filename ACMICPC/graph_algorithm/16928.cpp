#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int n, m;

pii ladder[16];
pii snake[16];
int dist[101];

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		ladder[i].first = a;
		ladder[i].second = b;
	}
	for (int j = 0; j < m; j++) {
		int a, b; cin >> a >> b;
		snake[j].first = a;
		snake[j].second = b;
	}
	for (int i = 0; i < 101; i++) {
		dist[i] = 1e9;
	}
}

bool inside(int x) {
	if (x < 1 || x>100)return false;
	return true;
}

void bfs() {
	for (int i = 0; i < 101; i++) {
		dist[i] = 1e9;
	}
	dist[1] = 0;
	queue<int>q; // {count, num}
	q.push(1);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		bool go_ladder = false;
		bool go_snake = false;
		for (int i = 0; i < n; i++) {
			if (ladder[i].first == cur) {
				go_ladder = true;
				if (dist[ladder[i].second] > dist[cur]) {
					dist[ladder[i].second] = dist[cur];
					q.push(ladder[i].second);
				}
			}
		}
		for (int i = 0; i < m; i++) {
			if (snake[i].first == cur) {
				go_snake = true;
				if (dist[snake[i].second] > dist[cur]) {
					dist[snake[i].second] = dist[cur];
					q.push(snake[i].second);
				}
			}
		}
		if (!go_ladder && !go_snake) {
			for (int i = 1; i <= 6; i++) {
				int nxt = cur + i;
				if (!inside(nxt))continue;
				if (dist[nxt] > dist[cur] + 1) {
					dist[nxt] = dist[cur] + 1;
					q.push(nxt);
				}
			}
		}
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	bfs();
	cout << dist[100];
}
