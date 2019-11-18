#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
struct GEAR {
	int seq[8];
	int left; // 6th index in seq 
	int right; // 2nd index in seq
}G[4];
int k;
queue<pii> rotation;
bool visit[4];

void input() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &G[i].seq[j]);
		}
		G[i].left = G[i].seq[6];
		G[i].right = G[i].seq[2];
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		int gear; cin >> gear;
		int dir; cin >> dir;
		rotation.push({ gear - 1,dir });
	}
}

void init_visit() {
	for (int i = 0; i < 4; i++) {
		visit[i] = false;
	}
}

GEAR rotate_left(GEAR g) {
	int tmp = g.seq[0];
	for (int i = 0; i < 7; i++) {
		g.seq[i] = g.seq[i + 1];
	}
	g.seq[7] = tmp;
	g.left = g.seq[6];
	g.right = g.seq[2];
	return g;
}

GEAR rotate_right(GEAR g) {
	int tmp = g.seq[7];
	for (int i = 7; i > 0; i--) {
		g.seq[i] = g.seq[i - 1];
	}
	g.seq[0] = tmp;
	g.left = g.seq[6];
	g.right = g.seq[2];
	return g;
}

void solve() {
	while (!rotation.empty()) {
		int gear = rotation.front().first;
		int dir = rotation.front().second;
		rotation.pop();

		queue<pii>turn;
		turn.push({ gear,dir });

		queue<pii>lefts;
		queue<pii>rights;
		lefts.push({ gear,dir });
		rights.push({ gear,dir });

		while (!lefts.empty()) {
			int cur = lefts.front().first;
			int cd = lefts.front().second;
			lefts.pop();
			if (cur != gear) {
				turn.push({ cur,cd });
			}
			int nxt = cur - 1;
			if (nxt >= 0) {
				if (G[nxt].right != G[cur].left) {
					lefts.push({ nxt,cd * -1 });
				}
			}
		}
		while (!rights.empty()) {
			int cur = rights.front().first;
			int cd = rights.front().second;
			rights.pop();
			if (cur != gear) {
				turn.push({ cur,cd });
			}
			int nxt = cur + 1;
			if (nxt < 4) {
				if (G[cur].right != G[nxt].left) {
					rights.push({ nxt,cd * -1 });
				}
			}
		}

		while (!turn.empty()) {
			int cur = turn.front().first;
			int cd = turn.front().second;
			turn.pop();
			if (cd == -1) {
				G[cur] = rotate_left(G[cur]);
			}
			else {
				G[cur] = rotate_right(G[cur]);
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < 4; i++) {
		if (G[i].seq[0] == 0) {

		}
		if (G[i].seq[0] == 1) {
			answer += pow(2, i);
		}
	}
	cout << answer;
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	solve();
	return 0;
}