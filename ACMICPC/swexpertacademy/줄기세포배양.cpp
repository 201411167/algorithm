#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define pii pair<int,int>
struct INFO {
	int x, y;
	int value;
};
bool operator < (INFO a, INFO b) {
	return a.value < b.value;
}
int n, m, k;
pii map[501][501];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };

void init() {
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			map[i][j].first = 0;
			map[i][j].second = 0;
		}
	}
}

void input() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j].first;
			map[i][j].second = map[i][j].first;
		}
	}
}

void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j].first == 0) {
				cout << "  ";
			}
			else {
				cout << map[i][j].first << " ";
			}
		}
		cout << "\n";
	}
	cout << "\n";
}

bool is_full() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i != 0 && j != 0 && i != n - 1 && j != m - 1) {
				continue;
			}
			if (map[i][j].first != 0) {
				return true;
			}
		}
	}
	return false;
}

void expand() {
	m += 2;
	
	for (int i = 0; i < n; i++) {
		for (int j = m - 2; j > 0; j--) {
			map[i][j].first = map[i][j - 1].first;
			map[i][j].second = map[i][j - 1].second;
		}
		map[i][0] = { 0,0 };
	}

	n += 2;
	for (int i = n - 2; i > 0; i--) {
		for (int j = 0; j < m; j++) {
			map[i][j].first = map[i - 1][j].first;
			map[i][j].second = map[i - 1][j].second;
		}
	}
	for (int j = 0; j < m; j++) {
		map[0][j] = { 0,0 };
	}
}

void ticking() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j].first > 0) {
				map[i][j].second--;
			}
		}
	}
}

void solve() {
	for (int trial = 1; trial < k; trial++) {
		if (is_full()) {
			expand();
		}

		ticking();

		priority_queue<INFO>q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j].first > 0 && map[i][j].second == 0) {
					q.push({ i,j,map[i][j].first });
				}
			}
		}

		while (!q.empty()) {
			int cx = q.top().x;
			int cy = q.top().y;
			int cv = q.top().value;
			q.pop();
			for (int d = 0; d < 4; d++) {
				int nx = cx + dir[d][0];
				int ny = cy + dir[d][1];
				if (map[nx][ny].first == 0) {
					map[nx][ny].first = cv;
					map[nx][ny].second = cv + 1;
				}
			}
		}
	}
	
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j].first > 0) {
				if (map[i][j].first + map[i][j].second > 1) {
					result++;
				}
			}
		}
	}
	cout << result << "\n";
}

int main() {
	freopen("Text.txt", "r", stdin);
	int testCase; cin >> testCase;
	for (int testIdx = 1; testIdx <= testCase; testIdx++) {
		init();
		input();
		cout << "#" << testIdx << " ";
		solve();
	}
	return 0;
}