#include <iostream>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
pii arr[1500002];
int drr[1500002];

int main() {
	freopen("Text.txt", "r", stdin);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int day, cost; cin >> day >> cost;
		arr[i].first = day;
		arr[i].second = cost;
	}

	int answer = 0;
	for (int i = 1; i <= n + 1; i++) {
		answer = max(answer, drr[i]);
		if (i + arr[i].first - 1 > n)continue;
		drr[i + arr[i].first] = max(answer + arr[i].second, drr[i + arr[i].first]);
	}
	cout << answer;


	return 0;
}