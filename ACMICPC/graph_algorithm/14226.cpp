#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
struct EMOTICON {
	int screen; //ȭ��
	int clipboard; //Ŭ������
};
queue<EMOTICON>q;
int dist[1001][1001];

void init() {
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			dist[i][j] = 1e9;
		}
	}
	dist[1][0] = 0;
}

void input() {
	cin >> n;
}

void bfs() {
	q.push({ 1,0 });
	while (!q.empty()) {
		int cur = q.front().screen;
		int clip = q.front().clipboard;
		q.pop();
		if (cur == n) {
			int answer = 1e9;
			for (int i = 0; i < 1001; i++) {
				answer = min(answer, dist[n][i]);
			}
			cout << answer;
			return;
		}
		int next, next_clip;
		for (int i = 0; i < 3; i++) {
			if (i == 0) { //ȭ�鿡 �ִ� �̸�Ƽ���� ��� �����ؼ� Ŭ�����忡 �����Ѵ�.
				next = cur;
				next_clip = cur;
			}
			if (i == 1 && clip != 0) { //Ŭ�����忡 �ִ� ��� �̸�Ƽ���� ȭ�鿡 �ٿ��ֱ� �Ѵ�.
				next = cur + clip;
				next_clip = clip;
			}
			if (i == 2 && cur > 0) { //ȭ�鿡 �ִ� �̸�Ƽ�� �� �ϳ��� �����Ѵ�.
				next = cur - 1;
				next_clip = clip;
			}
			if (dist[next][next_clip] > dist[cur][clip] + 1) {
				dist[next][next_clip] = dist[cur][clip] + 1;
				q.push({ next,next_clip });
			}
		}
	}
}

void solve() {
	input();
	init();
	bfs();
}

int main() {
	freopen("Text.txt", "r", stdin);
	solve();
	return 0;
}