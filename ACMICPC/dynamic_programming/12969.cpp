#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
bool visit[31][31][31][450];
void input() {
	cin >> n >> m;
}

string answer = "";
void dfs(string str, int a, int b, int c, int cnt) {
	if (str.length() > n) { return; }
	if (str.length() == n && cnt == m) {
		answer = str;
	}
	visit[a][b][c][cnt] = true;
	if (!visit[a + 1][b][c][cnt]) {
		visit[a + 1][b][c][cnt] = true;
		dfs(str + 'A', a + 1, b, c, cnt);
	}
	if (!visit[a][b + 1][c][cnt + a]) {
		visit[a][b + 1][c][cnt + a] = true;
		dfs(str + 'B', a, b + 1, c, cnt + a);
	}
	if (!visit[a][b][c + 1][cnt + a + b]) {
		visit[a][b][c + 1][cnt + a + b] = true;
		dfs(str + 'C', a, b, c + 1, cnt + a + b);
	}
}

void solve() {
	dfs("", 0, 0, 0, 0);
	if (answer == "") {
		cout << -1;
	}
	else {
		cout << answer;
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	solve();
}