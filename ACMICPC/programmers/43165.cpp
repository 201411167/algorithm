// https://programmers.co.kr/learn/courses/30/lessons/43165
#include <string>
#include <queue>
#include <vector>
using namespace std;

int solution(vector<int> numbers, int target) {
	if (numbers.empty()) {
		if (target == 0)
			return 1;
		else {
			return 0;
		}
	}
	else {
		int answer = 0;
		int cur = numbers[0];
		numbers.erase(numbers.begin());
		answer += solution(numbers, target - cur);
		answer += solution(numbers, target + cur);
		return answer;
	}
}