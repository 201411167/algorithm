#include <iostream>
using namespace std;

int dp[501][501];
int map[501][501];
int dir[4][2] ={{-1,0},{0,-1},{1,0},{0,1}};
int n;

int dfs(int x, int y){
	if(dp[x][y])return dp[x][y];

	dp[x][y]=1;
	for(int d=0;d<4;d++){
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];
		if(nx<0 || ny<0 || nx>=n || ny>=n)continue;
		if(map[nx][ny] <= map[x][y])continue;
		dp[x][y] = max(dp[x][y], dfs(nx,ny) + 1);
	}
	return dp[x][y];
}

int main(){
	freopen("input.txt","r",stdin);
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> map[i][j];
		}
	}
	int answer = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			answer = max(answer, dfs(i,j));
		}
	}
	cout << answer;
	return 0;
}