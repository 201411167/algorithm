#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 1001
int n;

bool visit[MAX];

struct RECT {
	int x1, y1;
	int x2, y2;
}R[MAX];

bool connected(int cur, int nxt) {
	RECT a = R[cur];
	RECT b = R[nxt];
	if ((a.x1 < b.x1 && b.x2 < a.x2 && a.y1 < b.y1 && b.y2 < a.y2)
		|| (a.x1 > b.x1 && b.x2 > a.x2 && a.y1 > b.y1 && b.y2 > a.y2)
		|| a.x2 < b.x1 || a.x1 > b.x2 || a.y2 < b.y1 || a.y1 > b.y2)
		return false;
	return true;
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	freopen("Text.txt", "r", stdin);

	cin >> n;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		a += 500;
		b += 500;
		c += 500;
		d += 500;
		R[i].x1 = a;
		R[i].y1 = b;
		R[i].x2 = c;
		R[i].y2 = d;
		for (int j = a; j <= c; j++) {
			for (int k = b; k <= d; k++) {
				if (j == a || j == c || k == b || k == d) {
					if (j == 500 && k == 500) {
						answer = -1;
					}
				}
			}
		}
	}
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (visit[i])continue;
		visit[i] = true;
		q.push(i);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int j = 0; j < n; j++) {
				if (cur == j || !connected(cur, j) || visit[j]) { continue; }
				visit[j] = true;
				q.push(j);
			}
		}
		answer++;
	}
	cout << answer;
	return 0;
}