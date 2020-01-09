#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int paper[10][10];
bool paste[10][10];

void input(){
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> paper[i][j];
		}
	}
}

bool inside(int x, int y) {
	if (x < 0 || y < 0 || x >= 10 || y >= 10) { return false; }
	else { return true; }
}

int answer = 1e9;
void attach(int x, int y, int size_1, int size_2, int size_3, int size_4, int size_5) {
	// 같은 종이를 5개 이상 사용할 수 없다
	if (size_1 > 5 || size_2 > 5 || size_3 > 5 || size_4 > 5 || size_5 > 5) { return; }

	// 1이 적혀있는 다음 위치를 찾는다
	int nx = -1;
	int ny = -1;
	bool stop = false;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (paper[i][j] == 1 && paste[i][j] == false) {
				nx = i;
				ny = j;
				stop = true;
			}
			if (stop) { break; }
		}
		if (stop) { break; }
	}

	// 다음 1인 칸이 없다면 끝이다
	if (nx == -1 && ny == -1) {
		answer = min(answer, size_1 + size_2 + size_3 + size_4 + size_5);
		return;
	}


	// nx, ny 위치에서 (1x1) ~ (5x5)의 종이를 붙일 수 있는지 판별
	for (int type = 0; type < 5; type++) {
		int ex = nx + type;
		int ey = ny + type;
		if (!inside(ex, ey)) { continue; }
		bool possible = true;
		for (int i = nx; i <= ex; i++) {
			for (int j = ny; j <= ey; j++) {
				if (paste[i][j] || paper[i][j] == 0) {
					possible = false;
				}
			}
		}
		if (possible) {
			for (int i = nx; i <= ex; i++) {
				for (int j = ny; j <= ey; j++) {
					paste[i][j] = true;
				}
			}
			if (type == 0) {
				attach(nx, ny, size_1 + 1, size_2, size_3, size_4, size_5);
			}
			if (type == 1) {
				attach(nx, ny, size_1, size_2 + 1, size_3, size_4, size_5);
			}
			if (type == 2) {
				attach(nx, ny, size_1, size_2, size_3 + 1, size_4, size_5);
			}
			if (type == 3) {
				attach(nx, ny, size_1, size_2, size_3, size_4 + 1, size_5);
			}
			if (type == 4) {
				attach(nx, ny, size_1, size_2, size_3, size_4, size_5 + 1);
			}
			for (int i = nx; i <= ex; i++) {
				for (int j = ny; j <= ey; j++) {
					paste[i][j] = false;
				}
			}
		}
	}
}

void solve() {
	memset(paste, false, sizeof(paste));
	attach(0, 0, 0, 0, 0, 0, 0);
	if (answer == 1e9) { cout << -1; }
	else { cout << answer; }
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	solve();
	return 0;
}
