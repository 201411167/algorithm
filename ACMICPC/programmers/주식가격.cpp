#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());

    for(int i=0;i<prices.size()-1;i++){
    	int p = prices[i];

    	int cnt = 0;
    	for(int j=i+1;j<prices.size();j++){
    		int q = prices[j];

    		if(p <= q){
    			cnt++;
    		}
    		else{
    			cnt++;
    			break;
    		}
    	}

    	answer[i] = cnt;

    }

    return answer;
}