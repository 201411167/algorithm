#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int cost[16][16];
int dp[16][1 << 16];

int TSP(int cur, int visited) {
	int result;
	int ret = dp[cur][visited];

	if (ret != 0) {
		return ret;
	}
	if (visited == (1 << n) - 1) {
		if (cost[cur][0] != 0) {
			return cost[cur][0];
		}
		return 1e9;
	}
	ret = 1e9;
	for (int i = 0; i < n; i++) {
		if ((visited & (1 << i)) || (cost[cur][i] == 0)) {
			continue;
		}
		result = TSP(i, (visited | 1 << i)) + cost[cur][i];
		if (result < ret)
			ret = result;
	}
	dp[cur][visited] = ret;
	return ret;
}

int main() {
	freopen("Text.txt", "r", stdin);
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}

	cout << TSP(0, 1);

	return 0;
}