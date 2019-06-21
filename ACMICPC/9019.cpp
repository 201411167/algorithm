#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int A, B;
bool visit[10000];

struct INFO {
	int num;
	int count;
	string order;
};

bool operator <(INFO a, INFO b) {
	return a.count > b.count;
}

void init() {
	for (int i = 0; i <= 9999; i++) {
		visit[i] = false;
	}
}

void bfs(int x, int y) {
	queue<INFO>q;
	INFO start;
	start.num = x;
	start.count = 0;
	visit[x] = true;
	q.push(start);
	while (!q.empty()) {
		INFO c = q.front();
		int cur = c.num;
		int cnt = c.count;
		q.pop();
		if (cur == y) {
			while (!q.empty())q.pop();
			cout << c.order << "\n";
			return;
		}
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				int tmp = (cur * 2) % 10000;
				if (visit[tmp] == false) {
					visit[tmp] = true;
					INFO nxt;
					nxt.num = tmp;
					nxt.count = cnt + 1;
					nxt.order = c.order + "D";
					q.push(nxt);
				}
			}
			if (i == 1) {
				int tmp;
				if (cur == 0) {
					tmp = 9999;
				}
				else {
					tmp = cur - 1;
				}
				if (visit[tmp] == false) {
					visit[tmp] = true;
					INFO nxt;
					nxt.num = tmp;
					nxt.count = cnt + 1;
					nxt.order = c.order + "S";
					q.push(nxt);
				}
			}
			if (i == 2) {
				int a = cur / 1000;
				int tmp = (cur - 1000 * a) * 10 + a;
				if (visit[tmp] == false) {
					visit[tmp] = true;
					INFO nxt;
					nxt.num = tmp;
					nxt.count = cnt + 1;
					nxt.order = c.order + "L";
					q.push(nxt);
				}
			}
			if (i == 3) {
				int a = cur / 10;
				int b = cur - a * 10;
				int tmp = 1000 * b + a;
				if (visit[tmp] == false) {
					visit[tmp] = true;
					INFO nxt;
					nxt.num = tmp;
					nxt.count = cnt + 1;
					nxt.order = c.order + "R";
					q.push(nxt);
				}
			}
		}
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	int testCase; cin >> testCase;
	while (testCase--) {
		cin >> A >> B;
		init();
		bfs(A, B);
	}

	return 0;
}