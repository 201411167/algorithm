#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

#define pii pair<int,int>

queue<int>q;

int required = 123456789;
int MAP[3][3];
map<int, int>visit;
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= 3 || y >= 3)return false;
	return true;
}

void input() {
	int start = 0;
	int index = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int item; cin >> item;
			if (item == 0) {
				item = 9;
			}
			start += item * pow(10, 8 - index++);
		}
	}
	string str = to_string(start);
	q.push(start);
	visit.insert({ start,0 });
}

void bfs() {
	while (!q.empty()) {
		int cur = q.front();
		string curstr = to_string(cur);
		int cx = curstr.find('9') / 3;
		int cy = curstr.find('9') % 3;
		int cur_pos = 3 * cx + cy;
		q.pop();

		if (cur == required) {
			break;
		}

		for (int d = 0; d < 4; d++) {
			int nx = cx + dir[d][0];
			int ny = cy + dir[d][1];
			if (!inside(nx, ny))continue;

			string nextstr = curstr;
			int next_pos = 3 * nx + ny;
			char tmp = nextstr[next_pos];
			nextstr[next_pos] = nextstr[cur_pos];
			nextstr[cur_pos] = tmp;
			int next = stoi(nextstr);

			if (!visit.count(next)) {
				visit[next] = visit[cur] + 1;
				q.push(next);
			}
		}
	}

	if (!visit.count(required)) {
		cout << -1;
	}
	else {
		cout << visit[required];
	}
}

void solve() {
	input();
	bfs();
}

int main() {
	freopen("Text.txt", "r", stdin);
	solve();
	return 0;
}