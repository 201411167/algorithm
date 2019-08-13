#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int n;
char map[51][51];
int height[51][51];
bool visit[51][51];
int sx, sy, k;
vector<int>heights;

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
	sort(heights.begin(), heights.end());
	heights.erase(unique(heights.begin(), heights.end()), heights.end());
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n)return false;
	return true;
}

bool bfs(int low, int high) {
	int dir[8][2] = { {-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };
	queue<pii>q;
	int tmpk = 0;
	if (height[sx][sy] >= low && height[sx][sy] <= high) {
		q.push({ sx,sy });
		visit[sx][sy] = true;
		while (!q.empty()) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();
			if (tmpk == k) {
				return true;
			}
			for (int d = 0; d < 8; d++) {
				int nx = cx + dir[d][0];
				int ny = cy + dir[d][1];
				if (!inside(nx, ny))continue;
				if (height[nx][ny] >= low && height[nx][ny] <= high) {
					if (!visit[nx][ny]) {
						visit[nx][ny] = true;
						if (map[nx][ny] == 'K') {
							tmpk++;
						}
						q.push({ nx,ny });
					}
				}
			}
		}
	}
	return false;
}

int search() {
	int i = 0;
	int j = 0;
	int ans = 1e9;
	for (i = 0; i < heights.size(); i++) {
		while (1) {
			memset(visit, false, sizeof(visit));
			if (!bfs(heights[j], heights[i])) {
				break;
			}
			ans = min(ans, heights[i] - heights[j]);
			j++;
		}
	}
	return ans;
}

int main() {
	freopen("Text.txt", "r", stdin);
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	input();
	cout << search();
	return 0;
}