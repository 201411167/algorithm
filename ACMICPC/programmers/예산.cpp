#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long chk(int cut, vector<int> budgets) {
    long long val = 0;
    for (int i = 0; i < budgets.size(); i++) {
        val += min(cut, budgets[i]);
    }
    return val;
}

int final_answer;
void binary(vector<int> budgets, int l, int r, int M) {
    if (l > r)return;
    int mid = (l + r) / 2;
    long long val = 0;
    val = chk(mid, budgets);

    if (val > M) {
        binary(budgets, l, mid - 1, M);
    }
    else {
        if (final_answer <= mid) {
            final_answer = mid;
        }
        binary(budgets, mid + 1, r, M);
    }
}

int solution(vector<int> budgets, int M) {
    int answer = 0;
    int MIN = 0;
    int MAX = 0;
    for (int i = 0; i < budgets.size(); i++) {
        MAX = max(budgets[i], MAX);
    }
    binary(budgets, MIN, MAX, M);
    answer = final_answer;
    return answer;
}