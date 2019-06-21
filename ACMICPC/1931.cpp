#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int n;
struct INFO {
	int start;
	int end;
};
bool operator <(INFO a, INFO b) {
	if (a.end == b.end) {
		return a.start < b.start;
	}
	return a.end < b.end;
}

int main() {
	freopen("Text.txt", "r", stdin);
	cin >> n;
	INFO *E = new INFO[n];
	for (int i = 0; i < n; i++) {
		cin >> E[i].start >> E[i].end;
	}
	sort(E, E + n);
	int answer = 1;
	int endtime = E[0].end;
	for (int i = 1; i < n; i++) {
		if (E[i].start >= endtime) {
			answer++;
			endtime = E[i].end;
		}
	}
	cout << answer;
	return 0;
}