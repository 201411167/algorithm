#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<long long> ans;

void solve(long long num, int cnt){
	if(cnt > 10){
		return;
	}
	else{
		ans.push_back(num);
		for(int i=0;i<=9;i++){
			if(num % 10 > i){
				solve(num * 10 + i, cnt + 1);
			}
		}
	}
}

int main(){
	freopen("input.txt","r",stdin);
	cin >> n;

	for(int i=0;i<=9;i++){
		solve(i,1);
	}
	sort(ans.begin(), ans.end());

	long long result = (ans.size() <= n ? -1 : ans[n]);
	cout << result;

	return 0;
}