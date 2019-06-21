#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n, m;
char map[13][13];
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };

struct node {
	int rx, ry;
	int bx, by;
	int count;
};
node start;

int bfs() {
	int answer = 1e9;
	int visit[13][13][13][13] = { 0, };
	queue<node>q;
	start.count = 0;
	q.push(start);
	while (!q.empty()) {
		node cur = q.front();
		int crx = cur.rx;
		int cry = cur.ry;
		int cbx = cur.bx;
		int cby = cur.by;
		q.pop();
		if (map[crx][cry] == 'O' && map[cbx][cby] != 'O') {
			answer = min(answer, cur.count);
		}
		for (int i = 0; i < 4; i++) {
			int nrx = crx; 
			int nry = cry;
			int nbx = cbx;
			int nby = cby;
			while (1) {
				if (map[nrx][nry] != '#' && map[nrx][nry] != 'O') {
					nrx += dx[i];
					nry += dy[i];
				}
				else {
					if (map[nrx][nry] == '#') {
						nrx -= dx[i];
						nry -= dy[i];
					}
					break;
				}
			}
			while (1) {
				if (map[nbx][nby] != '#' && map[nbx][nby] != 'O') {
					nbx += dx[i];
					nby += dy[i];
				}
				else {
					if (map[nbx][nby] == '#') {
						nbx -= dx[i];
						nby -= dy[i];
					}
					break;
				}
			}
			if (nrx == nbx && nry == nby) {
				if (map[nrx][nry] != 'O') {
					int r_dist = abs(nrx - crx) + abs(nry - cry);
					int b_dist = abs(nbx - cbx) + abs(nby - cby);
					if (r_dist > b_dist) {
						nrx -= dx[i];
						nry -= dy[i];
					}
					else {
						nbx -= dx[i];
						nby -= dy[i];
					}
				}
			}
			if (visit[nrx][nry][nbx][nby] == 0) {
				visit[nrx][nry][nbx][nby] = 1;
				node nxt;
				nxt.rx = nrx; nxt.ry = nry; 
				nxt.bx = nbx; nxt.by = nby;
				nxt.count = cur.count + 1;
				q.push(nxt);
			}
		}
	}
	if (answer <= 10)return answer;
	else return -1;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				start.rx = i;
				start.ry = j;
			}
			if (map[i][j] == 'B') {
				start.bx = i;
				start.by = j;
			}
		}
	}
	cout << bfs() << "\n";
}

int main() {
	freopen("Text.txt", "r", stdin);
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	solve();
	
	return 0;
}