#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string str[51];
int n,m,k;

int main(){
	freopen("input.txt","r",stdin);

	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> str[i];
	}
	cin >> k;

	int answer = 0;

	for(int i=0;i<n;i++){
		int zero_cnt = 0;
		int tmp = 0;
		for(int j=0;j<m;j++){
			if(str[i][j]-'0' == 0){
				zero_cnt++;
			}
		}
		if(zero_cnt <= k && (zero_cnt % 2 == k % 2)){
			for(int l=0;l<n;l++){
				if(str[i] == str[l]){
					tmp++;
				}
			}
			answer = max(answer, tmp);
		}
	}

	cout << answer << "\n";

	return 0;
}