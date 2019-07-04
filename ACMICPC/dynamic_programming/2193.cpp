#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	int n; cin >> n;
	long long* d = new long long[n + 1]();
	d[1] = 1;
	d[2] = 1;
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}
	cout << d[n];
}