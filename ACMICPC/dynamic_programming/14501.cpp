#include <iostream>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
#define time first
#define pay second

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	freopen("Text.txt", "r", stdin);

	int n; cin >> n;
	pii* a = new pii[n + 1]();
	int* d = new int[n + 1]();
	for (int i = 1; i <= n; i++) {
		int t, p; cin >> t >> p;
		a[i].time = t;
		a[i].pay = p;
	}
	if (a[1].time <= n) {
		d[1] = a[1].pay;
	}
	else {
		d[1] = 0;
	}
	for (int i = 2; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j < i; j++) {
			// if there is no inversion
			if (j + a[j].time - 1 < i) {
				tmp = max(tmp, d[j]);
			}
		}
		if (i + a[i].time - 1 <= n) {
			d[i] = tmp + a[i].pay;
		}
		else {
			d[i] = tmp;
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		answer = max(answer, d[i]);
	}
	cout << answer;
	return 0;
}