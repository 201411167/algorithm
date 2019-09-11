// https://programmers.co.kr/learn/courses/30/lessons/43162
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int>T[201];
bool visit[201];

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)continue;
			if (computers[i][j] == 1) {
				T[i].push_back(j);
				T[j].push_back(i);
			}
		}
	}
	queue<int>q;
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			answer++;
			visit[i] = true;
			q.push(i);
			while (!q.empty()) {
				int cur = q.front();
				q.pop();
				for (int i = 0; i < T[cur].size(); i++) {
					int nxt = T[cur][i];
					if (!visit[nxt]) {
						visit[nxt] = true;
						q.push(nxt);
					}
				}
			}
		}
	}
	return answer;
}