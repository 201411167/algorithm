#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int dp[1001];

int main() {
	freopen("Text.txt", "r", stdin);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		answer = max(answer, dp[i]);
	}
	cout << answer;
	return 0;
}