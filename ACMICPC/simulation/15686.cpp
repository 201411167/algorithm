#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int n, m;
int map[51][51];
vector<pii>chickens;
vector<pii>houses;
int chicken_total = 0;
bool visit[20];

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				chickens.push_back({ i,j });
				map[i][j] = 0;
				chicken_total++;
			}
			if (map[i][j] == 1) {
				houses.push_back({ i,j });
			}
		}
	}
}

int answer = 1e9;
vector<int>list;
void pick(int idx, int cnt) {
	if (cnt == m) {
		int sum = 0;
		for (int i = 0; i < houses.size(); i++) {
			int dist = 1e9;
			for (int j = 0; j < list.size(); j++) {
				dist = min(dist, abs(houses[i].first - chickens[list[j]].first) + abs(houses[i].second - chickens[list[j]].second));
			}
			sum += dist;
		}
		answer = min(answer, sum);
	}
	else {
		for (int i = idx; i < chicken_total; i++) {
			if (visit[i])continue;
			visit[i] = true;
			list.push_back(i);
			map[chickens[i].first][chickens[i].second] = 2;
			pick(i, cnt + 1);
			visit[i] = false;
			list.pop_back();
			map[chickens[i].first][chickens[i].second] = 0;
		}
	}
}

void solve() {
	pick(0, 0);
	cout << answer;
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	solve();
	return 0;
}