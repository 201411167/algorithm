#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct SHARK {
	int x, y;
	int z, s, d;
};
struct INFO {
	int z, s, d;
};
bool operator <(INFO a, INFO b) {
	return a.z > b.z;
}
int n, m, k;
vector<INFO>map[101][101];
queue<SHARK>sharks;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int fisher = -1;

void input() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int x, y, s, d, z; cin >> x >> y >> s >> d >> z;
		map[x - 1][y - 1].push_back({ z,s,d - 1 });
		sharks.push({ x - 1,y - 1,z,s,d - 1 });
	}
	if (k == 0) {
		cout << 0;
		exit(0);
	}
}

void move() {
	int size = sharks.size();
	while (size--) {
		int cx = sharks.front().x;
		int cy = sharks.front().y;
		int cz = sharks.front().z;
		int cs = sharks.front().s;
		int cd = sharks.front().d;
		sharks.pop();
		map[cx][cy].clear();
		int nx = cx;
		int ny = cy;
		if (cd == 0 || cd == 1) {
			for (int i = 0; i < cs; i++) {
				nx += dir[cd][0];
				if (nx < 0) {
					cd = 1;
					nx += 2;
				}
				if (nx >= n) {
					cd = 0;
					nx -= 2;
				}
			}
		}
		if (cd == 2 || cd == 3) {
			for (int i = 0; i < cs; i++) {
				ny += dir[cd][1];
				if (ny < 0) {
					cd = 2;
					ny += 2;
				}
				if (ny >= m) {
					cd = 3;
					ny -= 2;
				}
			}
		}
		sharks.push({ nx,ny,cz,cs,cd });
		map[nx][ny].push_back({ cz,cs,cd });
	}
}

int catch_shark() {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (!map[i][fisher].empty()) {
			ret = map[i][fisher][0].z;
			map[i][fisher].clear();
			return ret;
		}
	}
	return ret;
}

void kill_shark() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j].size() > 1) {
				sort(map[i][j].begin(), map[i][j].end());
				int z = map[i][j][0].z;
				int s = map[i][j][0].s;
				int d = map[i][j][0].d;
				map[i][j].clear();
				map[i][j].push_back({ z,s,d });
			}
		}
	}
}

void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!map[i][j].empty()) {
				cout << map[i][j][0].z << " ";
			}
			else {
				cout << 0 << " ";
			}
		}
		cout << "\n";
	}
	cout << "\n";
}

int solve() {
	int answer = 0;
	while (1) {
		fisher++;
		if (fisher >= m)break;
		answer += catch_shark();
		move();
		kill_shark();
	}
	return answer;
}

int main() {
	freopen("Text.txt", "r", stdin);
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	input();
	cout << solve();
	return 0;
}