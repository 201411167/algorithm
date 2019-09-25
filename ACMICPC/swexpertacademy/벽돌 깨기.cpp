#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct INFO {
	int x, y;
	int range;
};
int n, w, h;
vector<vector<int>> vmap; 
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void show(vector<vector<int>> mapinfo) {
	for (int i = 0; i < mapinfo.size(); i++) {
		for (int j = 0; j < mapinfo[0].size(); j++) {
			cout << mapinfo[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

bool float_in_the_air(vector<vector<int>> mapinfo) {
	for (int i = h - 1; i > 0; i--) {
		for (int j = 0; j < w; j++) {
			if (mapinfo[i][j] == 0 && mapinfo[i - 1][j] != 0) {
				return true;
			}
		}
	}
	return false;
}

vector<vector<int>> gravity(vector<vector<int>> mapinfo) {
	vector<vector<int>> ret;
	while (1) {
		if (float_in_the_air(mapinfo) == false)break;
		for (int i = h - 1; i > 0; i--) {
			for (int j = 0; j < w; j++) {
				if (mapinfo[i][j] == 0 && mapinfo[i - 1][j] != 0) {
					mapinfo[i][j] = mapinfo[i - 1][j];
					mapinfo[i - 1][j] = 0;
				}
			}
		}
	}
	ret = mapinfo;
	return ret;
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= h || y >= w)return false;
	return true;
}

int result = 1e9;
bool done = false;
void solve(int bead, int width, vector<vector<int>> mapinfo) {
	if (done) { // 답이 0이 나온다면, 더 이상 실행하지 않음
		return;
	}
	else {
		if (bead >= n + 1) { // 종료 조건 시 남은 벽돌을 구함
			int tmp = 0;
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (mapinfo[i][j] != 0) {
						tmp++;
					}
				}
			}
			result = min(result, tmp);
			if (result == 0) {
				done = true;
			}
			return;
		}
		else {
			if (bead != 0) { // 구슬이 벽돌을 깸
				queue<INFO>q;
				for (int i = 0; i < h; i++) {
					if (mapinfo[i][width] != 0) {
						q.push({ i,width,mapinfo[i][width] });
						break;
					}
				}
				while (!q.empty()) {
					int x = q.front().x;
					int y = q.front().y;
					int r = q.front().range;
					q.pop();
					for (int d = 0; d < 4; d++) {
						for (int k = 0; k < r; k++) {
							int nx = x + dx[d] * k;
							int ny = y + dy[d] * k;
							if (!inside(nx, ny))continue;
							if (mapinfo[nx][ny] > 0) {
								q.push({ nx,ny,mapinfo[nx][ny] });
								mapinfo[nx][ny] = 0;
							}
						}
					}
				}
			}

			mapinfo = gravity(mapinfo); // 구슬이 떨어짐

			for (int j = 0; j < w; j++) { // 다음 구슬을 던짐
				solve(bead + 1, j, mapinfo);
			}
		}
	}
}

void init() {
	for (int i = 0; i < vmap.size(); i++) {
		vmap[i].clear();
	}
	done = false;
	vmap.clear();
	result = 1e9;
}

int main() {
	freopen("Text.txt", "r", stdin);
	int testCase; cin >> testCase;
	for(int trial=1; trial <=testCase; trial++) { 
		init();

		cin >> n >> w >> h;
		for (int i = 0; i < h; i++) {
			vector<int> row;
			row.clear();
			for (int j = 0; j < w; j++) {
				int input; cin >> input;
				row.push_back(input);
			}
			vmap.push_back(row);
		}

		solve(0, 0, vmap);
		cout << "#" << trial << " ";
		cout << result << "\n";
	}
	return 0;
}