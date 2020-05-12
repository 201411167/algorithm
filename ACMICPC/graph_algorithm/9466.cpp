#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100001

int n, cnt;
int want[MAX];
bool visit[MAX];
bool done[MAX];

void dfs(int num) {
	visit[num] = true;

	int nxt = want[num];
	if (!visit[nxt]) {
		dfs(nxt);
	}
	else if (!done[nxt]) {
		for (int i = nxt; i != num; i = want[i]) {
			cnt++;
		}
		cnt++;
	}
	done[num] = true;

}
int main() {
	freopen("text.txt", "r", stdin);
	int testCase; cin >> testCase;
	while (testCase--) {
		cin >> n;
		memset(visit, false, sizeof(visit));
		memset(done, false, sizeof(done));

		for (int i = 1; i <= n; i++) {
			cin >> want[i];
		}
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				dfs(i);
			}
		}
		cout << n - cnt << "\n";
	}
}