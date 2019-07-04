#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	int n; cin >> n;
	int* a = new int[n + 1]();

	a[1] = 0;
	a[2] = 1;
	a[3] = 1;
	for (int i = 4; i <= n; i++) {
		if (((i % 3) == 0) && ((i % 2) == 0)) {
			a[i] = min(a[i / 3], min(a[i / 2], a[i - 1])) + 1;
		}
		if (((i % 3) != 0) && ((i % 2) == 0)) {
			a[i] = min(a[i / 2], a[i - 1]) + 1;
		}
		if (((i % 3) == 0) && ((i % 2) != 0)) {
			a[i] = min(a[i / 3], a[i - 1]) + 1;
		}
		if (((i % 3) != 0) && ((i % 2) != 0)) {
			a[i] = a[i - 1] + 1;
		}
	}
	cout << a[n];
	return 0;
}