#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

#define pii pair<int,int>
priority_queue<int> pq;
queue<pii> q;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    for(int i=0;i<priorities.size();i++){
    	q.push({priorities[i],i});
    	pq.push(priorities[i]);
    }

    
   	int trial = 0;
    while(!q.empty()){
    	int prior = q.front().first;
    	int idx = q.front().second;
    	q.pop();
    	
    	if(prior < pq.top()){
    		q.push({prior, idx});
    	}
    	else if(prior == pq.top()){
    		trial++;
    		if(idx == location){
    			answer = trial;
    		}
    		pq.pop();
    	}
    }

    return answer;
}