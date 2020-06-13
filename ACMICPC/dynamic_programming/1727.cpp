#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int men[1001];
int women[1001];
int dp[1001][1001];

void solve(){
	sort(men, men + n);
	sort(women, women + m);

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==j){
				dp[i][j] = dp[i-1][j-1] + abs(men[i-1] - women[j-1]);
			}
			if(i>j){
				dp[i][j] = min(dp[i-1][j-1] + abs(men[i-1] - women[j-1]),dp[i-1][j]);
			}
			if(i<j){
				dp[i][j] = min(dp[i-1][j-1] + abs(men[i-1] - women[j-1]),dp[i][j-1]);
			}
		}
	}
	cout << dp[n][m];
}

int main(){
	freopen("input.txt","r",stdin);

	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> men[i];
	}
	for(int i=0;i<m;i++){
		cin >> women[i];
	}

	solve();

	return 0;
}