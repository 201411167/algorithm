#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
#define piii pair<int, pair<int,int>>
int n;
char map[51][51];
int height[51][51];
int sx, sy;
int k;
vector<int>heights;
int visit[51][51];
int dir[8][2] = { {-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'P') {
				sx = i; sy = j;
			}
			if (map[i][j] == 'K') {
				k++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> height[i][j];
			heights.push_back({ height[i][j] });
		}
	}
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n)return false;
	return true;
}

int dfs(int x, int y, int mn, int mx) {
	if (visit[x][y] || height[x][y] < mn || height[x][y] > mx || !inside(x, y)) {
		return 0;
	}
	visit[x][y] = 1;
	int ret = 0;
	if (map[x][y] == 'K') {
		ret++;
	}
	for (int i = 0; i < 8; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		ret += dfs(nx, ny, mn, mx);
	}
	return ret;
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	freopen("Text.txt", "r", stdin);
	input();
	sort(heights.begin(), heights.end());
	heights.erase(unique(heights.begin(), heights.end()), heights.end());

	int i = 0;
	int j = 0;
	int ans = 1e9;
	for (i = 0; i < heights.size(); i++) {
		while (1) {
			memset(visit, 0, sizeof(visit));
			if (dfs(sx, sy, heights[j], heights[i]) != k) {
				break;
			}
			ans = min(ans, heights[i] - heights[j]);
			j++;
		}
	}
	cout << ans;
	return 0;
}