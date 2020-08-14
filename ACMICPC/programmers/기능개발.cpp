#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct info{
	int prior;
	int date;
};
bool operator <(info a, info b){
	return a.prior > b.prior;
}

priority_queue<info> pq;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int size = progresses.size();
    for(int i=0;i<size;i++){
    	int p = 100 - progresses[i];
    	int d = 0;
    	if(p % speeds[i] == 0){
    		d = p / speeds[i];
    	}else{
    		d = p / speeds[i] + 1;
    	}

    	pq.push({i, d});
    }

    int idx = 0;
    int lastDate = 0;
    while(!pq.empty()){
    	int date = pq.top().date;
    	pq.pop();

    	if(answer.empty()){
    		lastDate = date;
    		answer.push_back(1);
    		++idx;
    	}
    	else{
    		if(lastDate >= date){
    			answer[idx-1]++;
    		}else{
    			lastDate = date;
    			answer.push_back(1);
    			++idx;
    		}
    	}
    }


    return answer;
}