#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 1001
#define pii pair<int,int>
#define piii pair<int, pii>

int n, m;
char map[MAX][MAX];
queue<pii> fq; // queue for position of fire
queue<piii> pq; // queue for position of person
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			map[i][j] = 0;
		}
	}
	while (!fq.empty()) {
		fq.pop();
	}
	while (!pq.empty()) {
		pq.pop();
	}
}

void input() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') {
				continue;
			}
			if (map[i][j] == '*') {
				fq.push({ i,j });
			}
			if (map[i][j] == '@') {
				pq.push({ 0, {i,j} });
			}
			if (map[i][j] == '.') {

			}
		}
	}
}

bool inside(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m)return false;
	return true;
}

int explore() {
	while (!fq.empty() || !pq.empty()) {
		int fsize = fq.size();
		int psize = pq.size();
		while (fsize--) {
			int fx = fq.front().first;
			int fy = fq.front().second;
			fq.pop();
			//cout << "F : " << fx << ", " << fy << "\n";
			for (int i = 0; i < 4; i++) {
				int nx = fx + dx[i];
				int ny = fy + dy[i];
				if (!inside(nx, ny))continue;
				if (map[nx][ny] == '#' || map[nx][ny] == '*')continue;
				if (map[nx][ny] == '.' || map[nx][ny] == '@') {
					map[nx][ny] = '*';
					fq.push({ nx,ny });
				}
			}
		}
		while (psize--) {
			int cnt = pq.front().first;
			int px = pq.front().second.first;
			int py = pq.front().second.second;
			pq.pop();
			//cout << "P : " << px << ", " << py << "\n";
			if (px == 0 || px == n - 1 || py == 0 || py == m - 1) {
				while (!fq.empty()) {
					fq.pop();
				}
				while (!pq.empty()) {
					pq.pop();
				}
				return cnt + 1;
			}
			for (int i = 0; i < 4; i++) {
				int nx = px + dx[i];
				int ny = py + dy[i];
				if (!inside(nx, ny))continue;
				if (map[nx][ny] == '#' || map[nx][ny] == '*' || map[nx][ny] == '@')continue;
				if (map[nx][ny] == '.') {
					map[nx][ny] = '@';
					pq.push({ cnt + 1,{nx,ny} });
				}
			}
		}
	}
	return -1;
}


int main() {
	freopen("Text.txt", "r", stdin);
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	int testCase; cin >> testCase;
	while (testCase--) {
		init();
		input();
		int result = explore();
		if (result != -1) {
			cout << result << "\n";
		}
		else {
			cout << "IMPOSSIBLE\n";
		}
	}

	return 0;
}