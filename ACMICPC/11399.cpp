#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int n;

struct INFO {
	int person;
	int time;
}T[10001];

bool operator <(INFO a, INFO b) {
	return a.time < b.time;
}

int main() {
	freopen("Text.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		T[i].person = i;
		T[i].time = input;
	}

	sort(T, T + n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			sum += T[j].time;
		}
	}
	cout << sum;
	return 0;
}