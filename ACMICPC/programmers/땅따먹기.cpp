#include <iostream>
#include <vector>
using namespace std;


int answer;

void solve(vector<vector<int>> land, int cur_step, int prev_col, int total){

	answer = max(answer, total);
	if(cur_step + 1 >= land.size()) return;


	vector<int> next_values = land[cur_step + 1];

	for(int i=0;i<next_values.size();i++){
		if(i == prev_col) continue;

		solve(land, cur_step + 1, i, total + next_values[i]);
	}

}

int solution(vector<vector<int>> land){

	solve(land, -1, -1, 0);

	return answer;
}