#include <iostream>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int cnt = 0;
bool used[13] = { false, };
int map[5][9];
pii node[12];

void show() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j] == 0) {
				cout << '.';
			}
			else {
				char q = map[i][j] + 'A' - 1;
				cout << q;
			}
		}
		cout << "\n";
	}
	cout << "\n";
}

void dfs(int index) {
	int x = node[index].first;
	int y = node[index].second;
	if (index == cnt) {
		if (map[0][4] + map[1][3] + map[2][2] + map[3][1] == 26&&
			map[0][4] + map[1][5] + map[2][6] + map[3][7] == 26&&
			map[1][1] + map[2][2] + map[3][3] + map[4][4] == 26&&
			map[1][1] + map[1][3] + map[1][5] + map[1][7] == 26&&
			map[3][1] + map[3][3] + map[3][5] + map[3][7] == 26&& 
			map[4][4] + map[3][5] + map[2][6] + map[1][7] == 26){
			show();
			exit(0);
		}
		return;
	}
	for (int i = 1; i <= 12; i++) {
		if (!used[i]) {
			map[x][y] = i;
			used[i] = true;
			dfs(index + 1);
			map[x][y] = 0;
			used[i] = false;
		}
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	int index = 0;
	for (int i = 0; i < 12; i++) {
		node[i].first = -1;
		node[i].second = -1;
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			char q; cin >> q;
			if (q == '.') {
				map[i][j] = 0;
				continue;
			}
			if (q == 'x') {
				node[index].first = i;
				node[index].second = j;
				index++;
				cnt++;
				continue;
			}
			else {
				map[i][j] = q - 'A' + 1;
				used[q - 'A' + 1] = true;
			}
		}
	}
	dfs(0);
	return 0;
}