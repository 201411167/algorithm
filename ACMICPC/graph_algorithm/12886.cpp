#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct ROCK {
	int a, b, c;
};
ROCK start;
bool visit[2000][2000];

void input() {
	cin >> start.a >> start.b >> start.c;
}

void bfs() {
	queue<ROCK>q;
	q.push(start);
	visit[start.a][start.b] = true;
	visit[start.a][start.c] = true;
	visit[start.b][start.a] = true;
	visit[start.b][start.c] = true;
	visit[start.c][start.a] = true;
	visit[start.c][start.b] = true;
	while (!q.empty()) {
		ROCK cur = q.front();
		q.pop();
		if (cur.a == cur.b && cur.b == cur.c) {
			cout << "1";
			return;
		}
		for (int i = 0; i < 3; i++) {
			if (i == 0) { // a, b
				if (cur.a > cur.b) {
					int diff = cur.b;
					int na = cur.a - diff;
					int nb = cur.b + diff;
					int nc = cur.c;
					if (!visit[na][nb]) {
						visit[na][nb] = true;
						visit[na][nc] = true;
						visit[nb][na] = true;
						visit[nb][nc] = true;
						visit[nc][na] = true;
						visit[nc][nb] = true;
						q.push({ na,nb,nc });
					}
				}
				if (cur.a < cur.b) {
					int diff = cur.a;
					int na = cur.a + diff;
					int nb = cur.b - diff;
					int nc = cur.c;
					if (!visit[na][nb]) {
						visit[na][nb] = true;
						visit[na][nc] = true;
						visit[nb][na] = true;
						visit[nb][nc] = true;
						visit[nc][na] = true;
						visit[nc][nb] = true;
						q.push({ na,nb,nc });
					}
				}
			}
			if (i == 1) { // a, c
				if (cur.a > cur.c) {
					int diff = cur.c;
					int na = cur.a - diff;
					int nb = cur.b;
					int nc = cur.c + diff;
					if (!visit[na][nb]) {
						visit[na][nb] = true;
						visit[na][nc] = true;
						visit[nb][na] = true;
						visit[nb][nc] = true;
						visit[nc][na] = true;
						visit[nc][nb] = true;
						q.push({ na,nb,nc });
					}
				}
				if (cur.a < cur.c) {
					int diff = cur.a;
					int na = cur.a + diff;
					int nb = cur.b;
					int nc = cur.c - diff;
					if (!visit[na][nb]) {
						visit[na][nb] = true;
						visit[na][nc] = true;
						visit[nb][na] = true;
						visit[nb][nc] = true;
						visit[nc][na] = true;
						visit[nc][nb] = true;
						q.push({ na,nb,nc });
					}
				}
			}
			if (i == 2) { // b, c
				if (cur.b > cur.c) {
					int diff = cur.c;
					int na = cur.a;
					int nb = cur.b - diff;
					int nc = cur.c + diff;
					if (!visit[na][nb]) {
						visit[na][nb] = true;
						visit[na][nc] = true;
						visit[nb][na] = true;
						visit[nb][nc] = true;
						visit[nc][na] = true;
						visit[nc][nb] = true;
						q.push({ na,nb,nc });
					}
				}
				if (cur.b < cur.c) {
					int diff = cur.b;
					int na = cur.a;
					int nb = cur.b + diff;
					int nc = cur.c - diff;
					if (!visit[na][nb]) {
						visit[na][nb] = true;
						visit[na][nc] = true;
						visit[nb][na] = true;
						visit[nb][nc] = true;
						visit[nc][na] = true;
						visit[nc][nb] = true;
						q.push({ na,nb,nc });
					}
				}
			}
		}
	}
	cout << "0";
	return;
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	bfs();
	return 0;
}