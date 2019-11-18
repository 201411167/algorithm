#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int n;
pii map[501][501];
int number[501][501];
int dir0[6][2] = { {-1,-1},{-1,0},{0,-1},{0,1},{1,-1},{1,0} };
int dir1[6][2] = { {-1,0},{-1,1},{0,-1},{0,1},{1,0},{1,1} };
int visit[501][501];

struct INFO {
	int first;
	int second;
	queue<int>trace;
};

void init_visit() {
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			visit[i][j] = 1e9;
		}
	}
	visit[0][0] = 1;
}

void input() {
	int num = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {

		if ((i % 2) == 0) {
			for (int j = 0; j < n; j++) {
				int a, b; cin >> a >> b;
				map[i][j].first = a;
				map[i][j].second = b;
				number[i][j] = ++num;
			}
		}
		else {
			for (int j = 0; j < n - 1; j++) {
				int a, b; cin >> a >> b;
				map[i][j].first = a;
				map[i][j].second = b;
				number[i][j] = ++num;
			}
		}
	}
}

bool inside(int x, int y) {
	if ((x % 2) == 0) {
		if (x < 0 || y < 0 || x >= n || y >= n)return false;
		return true;
	}
	else {
		if (x < 0 || y < 0 || x >= n || y >= n - 1)return false;
		return true;
	}
}

queue<int>answer;

void solve() {
	int destination = 0;
	init_visit();
	queue<INFO>q;
	INFO start;
	start.first = 0;
	start.second = 0;
	start.trace.push(1);
	q.push(start);
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		queue<int> ct = q.front().trace;
		q.pop();

		if (destination < number[cx][cy]) {
			destination = number[cx][cy];
			while (!answer.empty()) {
				answer.pop();
			}
			for (int i = 0; i < ct.size(); i++) {
				int path = ct.front();
				ct.pop();
				answer.push(path);
				ct.push(path);
			}
		}

		if ((cx % 2) == 0) {
			for (int d = 0; d < 6; d++) {
				int nx = cx + dir0[d][0];
				int ny = cy + dir0[d][1];
				if (!inside(nx, ny))continue;
				if (d == 0) { // 왼쪽 위
					if (map[cx][cy].first != map[nx][ny].second)continue;
				}
				if (d == 1) { // 위
					if (map[cx][cy].second != map[nx][ny].first)continue;
				}
				if (d == 2) { // 왼쪽
					if (map[cx][cy].first != map[nx][ny].second)continue;
				}
				if (d == 3) { // 오른쪽
					if (map[cx][cy].second != map[nx][ny].first)continue;
				}
				if (d == 4) { // 왼쪽 아래
					if (map[cx][cy].first != map[nx][ny].second)continue;
				}
				if (d == 5) { // 아래
					if (map[cx][cy].second != map[nx][ny].first)continue;
				}
				if (visit[nx][ny] > visit[cx][cy] + 1) {
					visit[nx][ny] = visit[cx][cy] + 1;
					INFO nxt;
					nxt.first = nx;
					nxt.second = ny;
					for (int i = 0; i < ct.size(); i++) {
						int path = ct.front();
						ct.pop();
						ct.push(path);
						nxt.trace.push(path);
					}
					nxt.trace.push(number[nx][ny]);
					q.push(nxt);
				}
			}
		}
		else {
			for (int d = 0; d < 6; d++) {
				int nx = cx + dir1[d][0];
				int ny = cy + dir1[d][1];
				if (!inside(nx, ny))continue;
				if (d == 0) { // 위
					if (map[cx][cy].first != map[nx][ny].second)continue;
				}
				if (d == 1) { // 오른쪽 위
					if (map[cx][cy].second != map[nx][ny].first)continue;
				}
				if (d == 2) { // 왼쪽
					if (map[cx][cy].first != map[nx][ny].second)continue;
				}
				if (d == 3) { // 오른쪽
					if (map[cx][cy].second != map[nx][ny].first)continue;
				}
				if (d == 4) { // 아래
					if (map[cx][cy].first != map[nx][ny].second)continue;
				}
				if (d == 5) { // 오른쪽 아래
					if (map[cx][cy].second != map[nx][ny].first)continue;
				}
				if (visit[nx][ny] > visit[cx][cy] + 1) {
					visit[nx][ny] = visit[cx][cy] + 1;
					INFO nxt;
					nxt.first = nx;
					nxt.second = ny;
					for (int i = 0; i < ct.size(); i++) {
						int path = ct.front();
						ct.pop();
						ct.push(path);
						nxt.trace.push(path);
					}
					nxt.trace.push(number[nx][ny]);
					q.push(nxt);
				}
			}
		}
	}

	cout << answer.size() << "\n";
	while (!answer.empty()) {
		cout << answer.front() << " ";
		answer.pop();
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	solve();
	return 0;
}