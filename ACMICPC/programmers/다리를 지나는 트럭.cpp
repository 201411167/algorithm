#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> trucks) {
    int time = 0;
    int curWeight = 0;
    queue<int> q;

    for(int i=0;i<trucks.size();i++){
        int t = trucks[i];

        while(1){
            if(q.empty()){
                q.push(t);
                curWeight += t;
                time++;
                break;
            }
            else if(q.size() == bridge_length){
                curWeight -= q.front();
                q.pop();
            }
            else{
                if(t + curWeight > weight){
                    q.push(0);
                    time++;
                }
                else{
                    q.push(t);
                    curWeight += t;
                    time++;
                    break;
                }
            }
        }

    }

    return time + bridge_length;
}