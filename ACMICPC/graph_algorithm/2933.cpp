#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define pii pair<int,int>
int r, c;
int map[101][101];
int n;
int stick[101];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };

void input() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char input_item; cin >> input_item;
			if (input_item == '.') {
				map[i][j] = 0;
			}
			else {
				map[i][j] = 1;
			}
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stick[i];
	}
}

void print() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

void destroy(int x, int index) {
	int height = r - x;
	if (index % 2 == 0) { // left
		for (int i = 0; i < c; i++) {
			if (map[height][i] == 0)continue;
			if (map[height][i] != 0) {
				map[height][i] = 0;
				break;
			}
		}
	}
	if (index % 2 == 1) { // right
		for (int i = c - 1; i >= 0; i--) {
			if (map[height][i] == 0)continue;
			if (map[height][i] != 0) {
				map[height][i] = 0;
				break;
			}
		}
	}
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= r || y >= c)return false; return true;
}

int max_label;
void labeling() {
	bool visit[101][101] = { false, };
	queue<pii>q;
	int label = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!visit[i][j] && map[i][j] != 0) {
				visit[i][j] = true;
				label++;
				q.push({ i,j });
				while (!q.empty()) {
					int cx = q.front().first;
					int cy = q.front().second;
					q.pop();
					map[cx][cy] = label;
					for (int d = 0; d < 4; d++) {
						int nx = cx + dir[d][0];
						int ny = cy + dir[d][1];
						if (!inside(nx, ny))continue;
						if (map[nx][ny] == 0)continue;
						if (!visit[nx][ny]) {
							visit[nx][ny] = true;
							q.push({ nx,ny });
						}
					}
				}
			}
		}
	}
	max_label = label;
}

bool in_the_air(int label) {
	int x, y;
	bool aerial = true;
	bool stop = false;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == label) {
				x = i;
				y = j;
				stop = true;
				break;
			}
		}
		if (stop)break;
	}

	bool visit[101][101] = { false, };
	queue<pii>q;
	q.push({ x,y });
	visit[x][y] = true;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		if (map[cx + 1][cy] != 0 && map[cx + 1][cy] != label) {
			aerial = false;
		}
		if (!inside(cx + 1, cy)) {
			aerial = false;
		}
		for (int d = 0; d < 4; d++) {
			int nx = cx + dir[d][0];
			int ny = cy + dir[d][1];
			if (!inside(nx, ny))continue;
			if (map[nx][ny] == label) {
				if (!visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
	bool moved[101][101] = { false, };
	if (aerial == true) { // when it is aerial
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (visit[i][j]) {
					map[i + 1][j] = label;
					moved[i + 1][j] = true;
				}
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (visit[i][j] && !moved[i][j]) {
					map[i][j] = 0;
				}
			}
		}
	}
	return aerial;
}

void solution() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 0) {
				cout << '.';
			}
			else {
				cout << 'x';
			}
		}
		cout << "\n";
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	for (int i = 0; i < n; i++) {
		destroy(stick[i], i);
		labeling();
		for (int j = 1; j <= max_label; j++) {
			while (in_the_air(j));
		}
	}
	solution();

	return 0;
}