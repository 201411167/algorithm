#include <iostream>
#include <queue>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

#define ls pair<long long, string>
long long start, goal;
set<long long>s;

void input() {
	cin >> start >> goal;
}

void bfs() {
	if (start == goal) {
		cout << 0;
		return;
	}
	queue<ls>q;
	q.push({ start,"" });
	s.insert(start);
	while (!q.empty()) {
		long long cx = q.front().first;
		string cs = q.front().second;
		q.pop();
		if (cx == goal) {
			cout << cs;
			return;
		}
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				long long nx = cx * cx;
				string ns = cs + "*";
				if (s.find(nx) != s.end())continue;
				s.insert(nx);
				q.push({ nx,ns });
			}
			if (i == 1) {
				long long nx = cx + cx;
				string ns = cs + "+";
				if (s.find(nx) != s.end())continue;
				s.insert(nx);
				q.push({ nx,ns });
			}
			if (i == 2) {
				long long nx = cx - cx;
				string ns = cs + "-";
				if (s.find(nx) != s.end())continue;
				s.insert(nx);
				q.push({ nx,ns });
			}
			if (i == 3) {
				if (cx == 0)continue;
				long long nx = cx / cx;
				string ns = cs + "/";
				if (s.find(nx) != s.end())continue;
				s.insert(nx);
				q.push({ nx,ns });
			}
		}
	}
	cout << -1;
	return;
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	bfs();
	return 0;
}