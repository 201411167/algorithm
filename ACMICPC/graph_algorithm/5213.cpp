#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 550
struct INFO {
	int left, right, num;
};

int n;
INFO map[MAX][MAX];
bool visit[MAX][MAX];
bool connect[MAX][MAX][8];
int path[MAX * MAX];
int dx[] = { -1,-1,-1,0,1,1,1,0 };
int dy[] = { -1,0,1,1,1,0,-1,-1 };

void input() {
	cin >> n;
	int items = n * n - n / 2;
	int i = 0;
	int j = 0;
	int number = 0;
	while (items--) {
		int a, b; cin >> a >> b;
		if (i % 2 == 0) { //È¦¼ö ¹øÂ° ÁÙ
			map[i][j].num = ++number;
			map[i][j].left = a;
			map[i][j].right = b;
			j++;
			if (j == n) {
				j = 0;
				i++;
			}
		}
		else { //Â¦¼ö ¹øÂ° ÁÙ
			map[i][j].num = ++number;
			map[i][j].left = a;
			map[i][j].right = b;
			j++;
			if (j == n - 1) {
				j = 0;
				i++;
			}
		}
	}
}

void init() {
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			visit[i][j] = false;
			path[map[i][j].num] = 0;
		}
	}
	visit[0][0] = true;
	path[map[0][0].num] = 0;
}

bool inside(int x, int y) {
	if (x % 2 == 0) {
		if (x < 0 || y < 0 || x >= n || y >= n)return false;
		return true;
	}
	if (x % 2 == 1) {
		if (x < 0 || y < 0 || x >= n || y >= n - 1)return false;
		return true;
	}
}

void set_connect() {
	int even_odd;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)even_odd = 1; //È¦¼ö
		else even_odd = 0; //Â¦¼ö
		for (int j = 0; j <= n - 1 + even_odd; j++) {
			for (int k = 0; k < 8; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (map[nx][ny].left == -1 || map[nx][ny].right == -1)continue;
				if (even_odd == 1) {
					if (k == 2 || k == 4)continue;
					else if (k == 0 || k == 6 || k == 7) {
						if (map[nx][ny].right == map[i][j].left)connect[i][j][k] = true;
					}
					else if (k == 1 || k == 3 || k == 5) {
						if (map[nx][ny].left == map[i][j].right)connect[i][j][k] = true;
					}
				}
				else {
					if (k == 0 || k == 6)continue;
					else if (k == 1 || k == 5 || k == 7) {
						if (map[nx][ny].right == map[i][j].left)connect[i][j][k] = true;
					}
					else if (k == 2 || k == 3 || k == 4) {
						if (map[nx][ny].left == map[i][j].right)connect[i][j][k] = true;
					}
				}
			}
		}
	}
}

int max_tile = 0;
void bfs() {
	queue<pair<pair<int, int>, int>>q;
	q.push({ {0,0},1 });
	path[1] = 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int num = q.front().second;
		q.pop();
		max_tile = max(max_tile, num);
		for (int d = 0; d < 8; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			int nn = map[nx][ny].num;

			if (map[nx][ny].left == -1 || map[nx][ny].right == -1)continue;
			if (connect[x][y][d]) {
				if (!visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ {nx,ny},nn });
					path[nn] = num;
				}
			}
		}
	}
}

void find_path() {
	vector<int>v;
	int tmp = max_tile;
	v.push_back(tmp);
	while (path[tmp] != 0) {
		v.push_back(path[tmp]);
		tmp = path[tmp];
	}
	cout << v.size() << "\n";
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i] << " ";
	}
}

void solve() {
	init();
	set_connect();
	bfs();
	find_path();
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	solve();
	return 0;
}