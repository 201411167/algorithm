#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int a, b, n, m;

bool inside(int x) {
	if (x < 0 || x > 100000)return false;
	return true;
}

void bfs() {
	bool visit[100001] = { false, };
	priority_queue<pii> q;
	q.push({ 0,n });
	while (!q.empty()) {
		int cnt = -q.top().first;
		int cur = q.top().second;
		q.pop();
		if (cur == m) {
			cout << cnt;
			while (!q.empty()) {
				q.pop();
			}
			return;
		}
		for (int i = 0; i < 8; i++) {
			int nxt;
			if (i == 0) {
				nxt = cur + 1;
			}
			if (i == 1) {
				nxt = cur - 1;
			}
			if (i == 2) {
				nxt = cur + a;
			}
			if (i == 3) {
				nxt = cur - a;
			}
			if (i == 4) {
				nxt = cur + b;
			}
			if (i == 5) {
				nxt = cur - b;
			}
			if (i == 6) {
				nxt = cur * a;
			}
			if (i == 7) {
				nxt = cur * b;
			}
			if (!inside(nxt))continue;
			if (!visit[nxt]) {
				visit[nxt] = true;
				q.push({ -cnt - 1,nxt });
			}
		}
	}
	return;
}

int main() {
	freopen("Text.txt", "r", stdin);

	cin >> a >> b >> n >> m;

	bfs();

	return 0;
   }