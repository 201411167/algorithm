#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[1000001];
int b, c;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> b >> c;
}

long supervisor = 0;
void solve() {
	for (int i = 0; i < n; i++) {
		if (a[i] - b >= 0) {
			a[i] = a[i] - b;
			supervisor++;
		}
		else {
			a[i] = 0;
			supervisor++;
		}
	}
	for (int i = 0; i < n; i++) {
		supervisor += a[i] / c;
		if (a[i] % c != 0) {
			supervisor++;
		}
	}
}

int main() {
	//freopen("Text.txt", "r", stdin);
	input();
	solve();
	cout << supervisor;
	return 0;
}