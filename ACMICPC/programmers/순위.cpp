#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool floyd[103][103];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    for(int i=0;i<results.size();i++){
    	int a = results[i][0];
    	int b = results[i][1];
    	floyd[a][b] = true;
    }

    for(int k=1;k<=n;k++){
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=n;j++){
    			if(floyd[i][k] && floyd[k][j]){
    				floyd[i][j] = true;
    			}
    		}
    	}
    }

    for(int i=1;i<=n;i++){
    	int cnt = 0;
    	for(int j=1;j<=n;j++){
    		if(floyd[i][j] || floyd[j][i]){
    			cnt++;
    		}
    	}
    	if(cnt == n - 1){
    		answer++;
    	}
    }

    return answer;
}