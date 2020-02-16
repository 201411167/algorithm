#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[101];
vector<int>cal;
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int plus, minus, multiply, divide;
	cin >> plus >> minus >> multiply >> divide;
	for (int i = 0; i < plus; i++) {
		cal.push_back(0);
	}
	for (int i = 0; i < minus; i++) {
		cal.push_back(1);
	}
	for (int i = 0; i < multiply; i++) {
		cal.push_back(2);
	}
	for (int i = 0; i < divide; i++) {
		cal.push_back(3);
	}
}

int MAX = -1e9;
int MIN = 1e9;
bool chk[101];
vector<int>p_list;
void pick(int cnt) {
	if (cnt == n - 1) {
		int result = a[0];
		for (int i = 0; i < p_list.size(); i++) {
			if (p_list[i] == 0) {
				result += a[i + 1];
			}
			if (p_list[i] == 1) {
				result -= a[i + 1];
			}
			if (p_list[i] == 2) {
				result *= a[i + 1];
			}
			if (p_list[i] == 3) {
				result /= a[i + 1];
			}
		}
		MAX = max(MAX, result);
		MIN = min(MIN, result);
	}
	else {
		for (int i = 0; i < cal.size(); i++) {
			if (chk[i])continue;
			chk[i] = true;
			p_list.push_back(cal[i]);
			pick(cnt + 1);
			chk[i] = false;
			p_list.pop_back();
		}
	}
}

void solve() {
	pick(0);
	cout << MAX << "\n";
	cout << MIN << "\n";
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	solve();
	return 0;
}