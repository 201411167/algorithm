#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

string a, b, c;
struct INFO {
	string str;
	int ax, bx, cx;
};

bool visit[210][210];

bool possible() {

	INFO start;
	start.ax = 0; start.bx = 0; start.cx = 0; start.str = "";
	queue<INFO>q;
	q.push(start);

	while (!q.empty()) {
		INFO cur = q.front();
		q.pop();

		if (cur.str.compare(c) == 0) {
			return true;
		}

		for (int i = 0; i < 2; i++) {
			if (i == 0) {
				INFO nxt;
				nxt.ax = cur.ax + 1;
				nxt.bx = cur.bx;
				nxt.cx = cur.cx + 1;
				if (0 <= nxt.ax && nxt.ax <= a.length() && a[cur.ax] == c[cur.cx]) {
					if (visit[nxt.ax][nxt.bx] == false) {
						visit[nxt.ax][nxt.bx] = true;
						nxt.str = cur.str + a[cur.ax];
						q.push(nxt);
					}
				}
			}
			if (i == 1) {
				INFO nxt;
				nxt.ax = cur.ax;
				nxt.bx = cur.bx + 1;
				nxt.cx = cur.cx + 1;
				if (0 <= nxt.bx && nxt.bx <= b.length() && b[cur.bx] == c[cur.cx]) {
					if (visit[nxt.ax][nxt.bx] == false) {
						visit[nxt.ax][nxt.bx] = true;
					}
					nxt.str = cur.str + b[cur.bx];
					q.push(nxt);
				}
			}
		}
	}

	return false;
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	freopen("Text.txt", "r", stdin);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		cin >> a >> b >> c;
		cout << "Data set " << i << ": ";
		if (possible()) { cout << "yes\n"; }
		else { cout << "no\n"; }
	}

	return 0;
}