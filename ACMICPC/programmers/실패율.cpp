#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

float passed[501];
float failed[501];
float rate[501];

struct INFO {
	int num;
	float rate;
};

bool operator <(INFO a, INFO b) {
	if (a.rate == b.rate) {
		return a.num < b.num;
	}
	else {
		return a.rate > b.rate;
	}
}

bool comp(int a, int b) {
	float ra = rate[a];
	float rb = rate[b];
	if (ra > rb) {
		return a > b;
	}
	else if (ra < rb) {
		return a < b;
	}
	return a < b;
}

vector<int> solution(int N, vector<int> stages) {
	for (int i = 0; i < N; i++) {
		passed[i] = 0;
		failed[i] = 0;
		rate[i] = 0;
	}
	vector<INFO>tmp;
	vector<int> answer;
	for (int i = 1; i <= N; i++) {
		tmp.push_back({ i,0 });
	}

	for (int i = 0; i < stages.size(); i++) {
		failed[stages[i]]++;
		for (int j = 1; j <= stages[i]; j++) {
			passed[j]++;
		}
	}
	for (int i = 0; i < tmp.size(); i++) {
		int stage = tmp[i].num;
		if (passed[stage] != 0) {
			tmp[i].rate = failed[stage] / passed[stage];
		}
	}
	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < tmp.size(); i++) {
		answer.push_back(tmp[i].num);
	}
	return answer;
}