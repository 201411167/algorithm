/*
	문제 해결 전략

		큐에 넣는 경우, 큐에서 빼는 경우만 생각하면 됨

		1. 큐에서 빼는 경우 
			if(q.size() == bridge_length)
			큐의 front값이 다리의 끝에 도달한 경우 

		2. 큐에 넣는 경우
			if(cur_weight + truck_weights[idx] <= weight)
			다리 무게를 초과하지 않았기 때문에 새로운 트럭으로 밀어줄 수 있음 

			else ---> q.push(0);
			다리 무게를 초과하는 경우이므로 무게가 '0'인 가상의 트럭으로 밀어줄 수 있음 

*/

#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
        
    queue<int> q;
    int cur_weight = 0;
    int idx = 0;
    int finished_truck = 0;
       
    while(1){
        if(finished_truck == truck_weights.size()){break;}
        answer++;
        if(q.size() == bridge_length){
            int last = q.front();
            q.pop();
            cur_weight -= last;
            if(last != 0){
                finished_truck++;
            }
        }
        if(cur_weight + truck_weights[idx] <= weight){
            q.push(truck_weights[idx]);
            cur_weight += truck_weights[idx];
            idx++;
        }
        else{
            q.push(0);
        }
    }
    return answer;
}