#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
int n;
int relate[51][51];

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	freopen("Text.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == j)relate[i][j] = 0;
			else relate[i][j] = 1e9;
		}
	}

	while (1) {
		int a, b; cin >> a >> b;
		if (a == -1 && b == -1)break;
		relate[a][b] = 1;
		relate[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (relate[i][j] > relate[i][k] + relate[k][j]) {
					relate[i][j] = relate[i][k] + relate[k][j];
				}
			}
		}
	}

	priority_queue<pii> answers;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			tmp = max(tmp, relate[i][j]);
		}
		answers.push({ -tmp, -i });
	}

	int answer_score = -answers.top().first;
	queue<int> principle;
	int number_of_people = 0;
	while (!answers.empty()) {
		int score = -answers.top().first;
		int person = -answers.top().second;
		answers.pop();
		if (score == answer_score) {
			principle.push(person);
			number_of_people++;
		}
	}

	cout << answer_score << " " << number_of_people << "\n";
	while (!principle.empty()) {
		cout << principle.front() << " ";
		principle.pop();
	}
	return 0;
}