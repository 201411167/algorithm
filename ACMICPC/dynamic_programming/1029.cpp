#include <iostream>
#include <cstring>
using namespace std;

int n;
int arr[16][16];
int cache[16][1 << 17][10];

int dfs(int cur, int visited, int cost){

	int& ret = cache[cur][visited][cost];

	if(ret != 0){
		return ret;
	}

	// ret = 1;
	for(int i=0;i<n;i++){
		if(visited & (1 << i))continue;
		if(i == cur)continue;
		if(arr[cur][i] >= cost){
			ret = max(ret, dfs(i, visited | 1 << i, arr[cur][i]) +1);
		}
	}

	return ret;
}

void solve(){
	cout << dfs(0, 1 , 0);
}

int main(){
	freopen("input.txt","r",stdin);

	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%1d", &arr[i][j]);
		}
	}

	solve();

	return 0;
}