#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <set>
#include <string>
using namespace std;

int n, k;
set<string>s;

priority_queue<string>infoQ;

string solve() {
	cin >> n >> k;
	int pack = n / 4;
	deque<char>q;
	for (int i = 0; i < n; i++) {
		char item; cin >> item;
		q.push_back(item);
	}

	int size = q.size();

	for (int i = 0; i < pack; i++) {
		string str = "";
		int idx = 0;

		for (int i = 0; i < size; i++) {
			char front = q.front();
			q.pop_front();
			q.push_back(front);
			str += front;
			idx++;
			if (idx == pack) {
				if (s.find(str) == s.end()) {
					s.insert(str);
					infoQ.push(str);
				}
				str = "";
				idx = 0;
			}
		}

		char back = q.back();
		q.pop_back();
		q.push_front(back);
	}

	int orderIdx = 1;
	string result;
	while (!infoQ.empty()) {
		string front = infoQ.top();
		if (orderIdx == k) {
			result = front;
		}
		orderIdx++;
		infoQ.pop();
	}

	return result;
}

int main() {
	freopen("Text.txt", "r", stdin);

	int testCase; cin >> testCase;
	int testIdx = 0;
	while (testCase--) {
		string result = solve();
		s.clear();
		cout << "#" << ++testIdx << " ";
		cout << stoi(result, nullptr, 16) << "\n";
	}

	return 0;
}