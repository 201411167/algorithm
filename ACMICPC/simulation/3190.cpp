#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
#define pic pair<int,char>
int n, k, l;
int map[101][101];
bool apple[101][101];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} }; // up, left, down, right
vector<pic> command;

void input() {
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x, y; cin >> x >> y;
		apple[x - 1][y - 1] = true; // there is an apple in this area
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int t; char d;
		cin >> t >> d;
		command.push_back({ t,d });
	}
}

void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

int play_game() {
	deque<pii>q;
	q.push_front({ 0,0 });
	int time = 0;
	int d = 3;
	map[0][0] = 1;
	while (1) {
		if (command.size() != 0) {
			int nxt_time = command[0].first;
			char nxt_dir = command[0].second;
			if (time == nxt_time) {
				command.erase(command.begin());
				if (nxt_dir == 'L') {
					d = (d + 1) % 4;
				}
				if (nxt_dir == 'D') {
					d = (d + 3) % 4;
				}
			}
		}

		int hx = q.front().first;
		int hy = q.front().second;
		int tx = q.back().first;
		int ty = q.back().second;
		int nhx = hx + dir[d][0];
		int nhy = hy + dir[d][1];

		if (nhx < 0 || nhy < 0 || nhx >= n || nhy >= n || map[nhx][nhy] == 1) { break; }
		else {
			if (apple[nhx][nhy] == true) {
				apple[nhx][nhy] = false;
				map[nhx][nhy] = 1;
				q.push_front({ nhx,nhy });
			}
			else {
				map[nhx][nhy] = 1;
				q.push_front({ nhx,nhy });
				map[tx][ty] = 0;
				q.pop_back();
			}
		}

		time++;
	}
	return time + 1;
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	cout << play_game();
	return 0;
}