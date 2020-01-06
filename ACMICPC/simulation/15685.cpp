#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int dir[4][2] = { {1,0},{0,-1},{-1,0},{0,1} };
bool visit[105][105];

void draw_line(int y, int x, int d, int g) {
	vector<int>d_list; 
	d_list.push_back(d);

	for (int i = 1; i <= g; i++) {
		int size = d_list.size();
		for (int j = size - 1; j >= 0; j--) {
			int nd = (d_list[j] + 3) % 4;
			d_list.push_back(nd);
		}
	}

	visit[x][y] = true;
	for (int i = 0; i < d_list.size(); i++) {
		if (i % 2 == 1) {
			d_list[i] = (d_list[i] + 2) % 4;
		}
		x += dir[d_list[i]][0];
		y += dir[d_list[i]][1];
		visit[x][y] = true;
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g; cin >> y >> x >> d >> g;
		draw_line(x, y, d, g);
	}
	int answer = 0;
	for (int i = 0; i < 103; i++) {
		for (int j = 0; j < 103; j++) {
			if (visit[i][j] && visit[i + 1][j] && visit[i][j + 1] && visit[i + 1][j + 1]) {
				answer++;
			}
		}
	}
	cout << answer;
}

int main() {
	freopen("Text.txt", "r", stdin);
	solve();
	return 0;
}