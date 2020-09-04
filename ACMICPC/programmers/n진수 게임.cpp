#include <iostream>
#include <string>
#include <vector>

using namespace std;

string transform(int num, int n){
	string rtn = "";

	string tmp = "";
	while(num){
		int a = num % n;
		if(a == 10){
			tmp += 'A';
		}
		else if(a == 11){
			tmp += 'B';
		}
		else if(a == 12){
			tmp += 'C';
		}
		else if(a == 13){
			tmp += 'D';
		}
		else if(a == 14){
			tmp += 'E';
		}
		else if(a == 15){
			tmp += 'F';
		}
		else{
			tmp += a + '0';
		}
		num /= n;
	}

	for(int i=tmp.length()-1; i>=0; i--){
		rtn += tmp[i];
	}

	return rtn;
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    int num = 0;
    string list = "0";
    while(1){
    	if(list.size() > (t * m)) break;
    	list += transform(num++, n);
    }
    
    for(int i=0;i<list.size();i++){
    	if(i % m == p - 1){
    		answer += list[i];
    	}
    }
    if(answer.size() > t){
    	answer.pop_back();
	}
    return answer;
}