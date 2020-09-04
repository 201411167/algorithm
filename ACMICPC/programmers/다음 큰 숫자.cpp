
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string getBinary(int n){
    string tmp = "";
    while(n){
    	if(n % 2 == 0){
    		tmp += '0';
    	}else{
    		tmp += '1';
    	}
    	n /= 2;
    }

    string binary = "";
    for(int i=tmp.size()-1;i>=0;i--){
    	binary += tmp[i];
    }
    return binary;
}

int solution(int n) {
    int answer = 0;
    
    string binary = getBinary(n);
    int cnt = 0;
    for(int i=0;i<binary.size();i++){
        if(binary[i] == '1'){
            cnt++;
        }
    }
    for(int i=n+1;i<=n*2;i++){
        string tmp = getBinary(i);
        int tmp_cnt = 0;
        for(int j=0;j<tmp.size();j++){
            if(tmp[j] == '1'){
                tmp_cnt++;
            }
        }
        if(cnt == tmp_cnt){
            answer = i;
            break;
        }
    }

    return answer;
}