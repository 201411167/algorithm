#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int,int>

struct GEAR {
	int seq[8];
	int top;
	int left;
	int right;
}G[1001];

int t;
int k;
pii order[1001];

void input() {
	cin >> t;
	for (int i = 1; i <= t; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &G[i].seq[j]);
			G[i].top = G[i].seq[0];
			G[i].left = G[i].seq[6];
			G[i].right = G[i].seq[2];
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> order[i].first >> order[i].second;
	}
}

GEAR rotate_left(int g) {
	int tmp = G[g].seq[0];
	for (int i = 0; i < 7; i++) {
		G[g].seq[i] = G[g].seq[i + 1];
	}
	G[g].seq[7] = tmp;
	G[g].top = G[g].seq[0];
	G[g].left = G[g].seq[6];
	G[g].right = G[g].seq[2];
	return G[g];
}

GEAR rotate_right(int g) {
	int tmp = G[g].seq[7];
	for (int i = 7; i > 0; i--) {
		G[g].seq[i] = G[g].seq[i - 1];
	}
	G[g].seq[0] = tmp;
	G[g].top = G[g].seq[0];
	G[g].left = G[g].seq[6];
	G[g].right = G[g].seq[2];
	return G[g];
}

void solve() {
	for (int i = 0; i < k; i++) {
		int moving_gear = order[i].first;
		int rotate_dir = order[i].second;

		queue<pii>left_q;
		queue<pii>right_q;
		queue<pii>turning_q;
		turning_q.push({ moving_gear,rotate_dir });

		if (moving_gear > 1) {
			left_q.push({ moving_gear,rotate_dir });
		}
		if (moving_gear < t) {
			right_q.push({ moving_gear,rotate_dir });
		}

		while (!left_q.empty()) {
			int cg = left_q.front().first;
			int cd = left_q.front().second;
			left_q.pop();
			int ng = cg - 1;
			if (ng >= 1) {
				if (G[ng].right != G[cg].left) {
					left_q.push({ ng,cd * -1 });
					turning_q.push({ ng,cd * -1 });
				}
			}
		}

		while (!right_q.empty()) {
			int cg = right_q.front().first;
			int cd = right_q.front().second;
			right_q.pop();
			int ng = cg + 1;
			if (ng <= t) {
				if (G[ng].left != G[cg].right) {
					right_q.push({ ng,cd * -1 });
					turning_q.push({ ng,cd * -1 });
				}
			}
		}

		while (!turning_q.empty()) {
			int cg = turning_q.front().first;
			int cd = turning_q.front().second;
			turning_q.pop();
			if (cd == 1) { // turn right
				G[cg] = rotate_right(cg);
			}
			if (cd == -1) { // turn left
				G[cg] = rotate_left(cg);
			}
		}
	}
	int total = 0;
	for (int i = 1; i <= t; i++) {
		if (G[i].top == 1) {
			total++;
		}
	}
	cout << total;
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	solve();
	return 0;
}