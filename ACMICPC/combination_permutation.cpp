#include <iostream>
#include <vector>
using namespace std;

bool visit[51];
vector<int>p_list;
void pick_p(int cnt) { // cnt : 고른 횟수
	if (cnt == 2) {
		for (int i = 0; i < p_list.size(); i++) {
			cout << p_list[i] << " ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= 4; i++) {
		if (visit[i])continue;
		visit[i] = true;
		p_list.push_back(i);
		pick_p(cnt + 1);
		visit[i] = false;
		p_list.pop_back();
	}
}

vector<int>c_list;
void pick_c(int idx, int cnt) { // idx : 마지막으로 고른 숫자, cnt : 고른 횟수
	if (cnt == 2) {
		for (int i = 0; i < c_list.size(); i++) {
			cout << c_list[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = idx; i <= 5; i++) {
			if (visit[i])continue;
			visit[i] = true;
			c_list.push_back(i);
			pick_c(i, cnt + 1);
			visit[i] = false;
			c_list.pop_back();
		}
	}
}

int main() {
	pick_p(0);
	memset(visit, false, sizeof(visit));
	cout << "\n\n";
	pick_c(1, 0);
	return 0;
}