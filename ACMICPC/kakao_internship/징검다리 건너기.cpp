#include <string>
#include <vector>

using namespace std;

bool check(vector<int> stones, int k, int m) {
    int cnt = 0;
    for (int i = 0; i < stones.size(); i++) {
        if ((stones[i] - (m - 1)) <= 0) {
            cnt++;
            if (cnt == k) {
                return false;
            }
        }
        else {
            cnt = 0;
        }
    }
    return true;
}

int maxValue = 0;
void binary(vector<int> stones, int k, int left, int right) {
    if (left > right)return;

    int mid = (left + right) / 2;
    if (check(stones, k, mid)) {
        if (maxValue < mid) {
            maxValue = mid;
        }
        binary(stones, k, mid + 1, right);
    }
    else {
        binary(stones, k, left, mid - 1);
    }
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    binary(stones, k, 1, 200000000);
    answer = maxValue;
    return answer;
}