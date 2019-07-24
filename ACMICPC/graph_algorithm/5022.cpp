#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

#define pii pair<int,int>
#define MAX 101
struct NODE { 
	int x; int y; queue<pii>trace; 
};

int n, m;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
pii a, b, c, d;
bool occupy[MAX][MAX];
int a_len, b_len;
bool a_flag, b_flag;

bool inside(int x, int y) { if (x<0 || y<0 || x>n || y>m)return false; return true; }

void bfsA() {
	NODE start;
	start.x = a.first; start.y = a.second; start.trace.push({ start.x,start.y });
	visit[start.x][start.y] = true;
	queue<NODE>q;
	q.push(start);
	while (!q.empty()) {
		NODE cur = q.front();
		q.pop();
		if (cur.x == b.first && cur.y == b.second) {
			while (!cur.trace.empty()) {
				int tx = cur.trace.front().first;
				int ty = cur.trace.front().second;
				cur.trace.pop();
				occupy[tx][ty] = true;
				a_len++;
			}
			a_len--;
			a_flag = true;
			return;
		}
		for (int di = 0; di < 4; di++) {
			int nx = cur.x + dir[di][0];
			int ny = cur.y + dir[di][1];
			if (!inside(nx, ny))continue;
			if (occupy[nx][ny])continue;
			if ((nx == c.first && ny == c.second) || (nx == d.first && ny == d.second))continue;
			if (!visit[nx][ny]) {
				visit[nx][ny] = true;
				NODE nxt;
				nxt.x = nx; nxt.y = ny; 
				for (int i = 0; i < cur.trace.size(); i++) {
					int tx = cur.trace.front().first;
					int ty = cur.trace.front().second;
					cur.trace.pop();
					cur.trace.push({ tx,ty });
					nxt.trace.push({ tx,ty });
				}
				nxt.trace.push({ nx,ny });
				q.push(nxt);
			}
		}
	}
}

void bfsB() {
	NODE start;
	start.x = c.first; start.y = c.second; start.trace.push({ start.x,start.y });
	visit[start.x][start.y] = true;
	queue<NODE>q;
	q.push(start);
	while (!q.empty()) {
		NODE cur = q.front();
		q.pop();
		if (cur.x == d.first && cur.y == d.second) {
			while (!cur.trace.empty()) {
				int tx = cur.trace.front().first;
				int ty = cur.trace.front().second;
				cur.trace.pop();
				occupy[tx][ty] = true;
				b_len++;
			}
			b_len--;
			b_flag = true;
			return;
		}
		for (int di = 0; di < 4; di++) {
			int nx = cur.x + dir[di][0];
			int ny = cur.y + dir[di][1];
			if (!inside(nx, ny))continue;
			if (occupy[nx][ny])continue;
			if ((nx == a.first && ny == a.second) || (nx == b.first && ny == b.second))continue;
			if (!visit[nx][ny]) {
				visit[nx][ny] = true;
				NODE nxt;
				nxt.x = nx; nxt.y = ny;
				for (int i = 0; i < cur.trace.size(); i++) {
					int tx = cur.trace.front().first;
					int ty = cur.trace.front().second;
					cur.trace.pop();
					cur.trace.push({ tx,ty });
					nxt.trace.push({ tx,ty });
				}
				nxt.trace.push({ nx,ny });
				q.push(nxt);
			}
		}
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	cin >> n >> m;
	cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;

	int way1 = 1e9;
	bfsA(); 
	memset(visit, false, sizeof(visit));
	bfsB();
	if (a_flag && b_flag) {
		way1 = a_len + b_len;
	}

	a_len = 0; b_len = 0; a_flag = false, b_flag = false;
	memset(visit,false,sizeof(visit));
	memset(occupy,false,sizeof(occupy));

	int way2 = 1e9;
	bfsB();
	memset(visit, false, sizeof(visit));
	bfsA();
	if (a_flag && b_flag) {
		way2 = a_len + b_len;
	}

	int answer = min(way1, way2);
	if (answer == 1e9)cout << "IMPOSSIBLE";
	else cout << answer;
	return 0;
}