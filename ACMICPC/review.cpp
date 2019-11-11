#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
struct INFO {
	int day; //��¥
	int money; //���� - ���
	int number; //�ֽ� ����
};
vector<int> future;

int main() {
	freopen("Text.txt", "r", stdin);
	cin >> n;
	future.push_back(0);
	for (int i = 1; i <= n; i++) {
		int future_cost; cin >> future_cost;
		future.push_back(future_cost);
	}
	INFO start; 
	start.day = 0;
	start.money = 0;
	start.number = 0;
	queue<INFO>q;
	q.push(start);

	while (!q.empty()) {
		INFO cur = q.front();
		q.pop();
		cout << cur.day << ": " << cur.money << "\n";
		
		if (cur.day < n) {
			for (int i = 0; i < 3; i++) {
				if (i == 0) { //�ֽ� ����
					INFO nxt;
					nxt.day = cur.day + 1;
					nxt.money = cur.money - future[cur.day + 1];
					nxt.number = cur.number + 1;
					q.push(nxt);
				}
				if (i == 1) { //�ֽ� �Ǹ�
					for (int j = 1; j <= cur.number; j++) {
						INFO nxt;
						nxt.day = cur.day + 1;
						nxt.money = cur.money + future[cur.day + 1] * j;
						nxt.number = cur.number - j;
						q.push(nxt);
					}
				}
				if (1 == 2) { //�ƹ��͵� ���� ����
					continue;
				}
			}
		}
	}
}
