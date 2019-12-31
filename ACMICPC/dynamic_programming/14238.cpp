#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <time.h>
using namespace std;

string str_input;
string str_permu;
bool visit_permu[51];
int d[51][51][51][3][3];
int a_num, b_num, c_num;
vector<string>list;

void input() {
	cin >> str_input;
	for (int i = 0; i < str_input.length(); i++) {
		if (str_input[i] == 'A') {
			a_num++;
		}
		if (str_input[i] == 'B') {
			b_num++;
		}
		if (str_input[i] == 'C') {
			c_num++;
		}
	}
}

int go(int a, int b, int c, int p1, int p2) {
	if (a + b + c == 0) {
		return d[a][b][c][p1][p2] = 1;
	}
	if (d[a][b][c][p1][p2] != -1) {
		return d[a][b][c][p1][p2];
	}
	if (a > 0 && go(a - 1, b, c, 0, p1) == 1) {
		return d[a][b][c][p1][p2] = 1;
	}
	if (b > 0 && p1 != 1 && go(a, b - 1, c, 1, p1) == 1) {
		return d[a][b][c][p1][p2] = 1;
	}
	if (c > 0 && p1 != 2 && p2 != 2 && go(a, b, c - 1, 2, p1) == 1) {
		return d[a][b][c][p1][p2] = 1;
	}
	d[a][b][c][p1][p2] = 0;
	return 0;
}

string back(int a, int b, int c, int p1, int p2) {
	if (a + b + c == 0) {
		return "";
	}
	if (a > 0 && go(a - 1, b, c, 0, p1) == 1) {
		return "A" + back(a - 1, b, c, 0, p1);
	}
	if (b > 0 && p1 != 1 && go(a, b - 1, c, 1, p1) == 1) {
		return "B" + back(a, b - 1, c, 1, p1);
	}
	if (c > 0 && p1 != 2 && p2 != 2 && go(a, b, c - 1, 2, p1) == 1) {
		return "C" + back(a, b, c - 1, 2, p1);
	}
	return "";
}

void solve() {
	memset(d, -1, sizeof(d));
	int ans = go(a_num, b_num, c_num, 0, 0);
	if (ans == 0) {
		cout << -1;
	}
	else {
		cout << back(a_num, b_num, c_num, 0, 0);
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	input();
	solve();
	return 0;
}