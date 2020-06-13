#include <iostream>
using namespace std;

int n;
long long dp[1000002];
const long long MOD = 1000000000;

void solve(){
	dp[1]=0;
	dp[2]=1;
	dp[3]=2;
	for(int i=4;i<=n;i++){
		dp[i]=(i-1)*(dp[i-1] + dp[i-2]) % MOD;
	}
	cout << dp[n];
}

int main(){
	freopen("input.txt","r",stdin);
	cin >>n;
	solve();
	return 0;
}