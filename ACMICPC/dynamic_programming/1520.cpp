#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int map[501][501];
int cache[501][501];
int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

bool inside(int x, int y){
	return x>=0 && y>=0 && x<n && y<m;
}

int dfs(int x, int y){
	if(x == n-1 && y == m-1)
		return 1;

	if(cache[x][y] != -1)
		return cache[x][y];

	cache[x][y]=0;
	for(int d=0;d<4;d++){
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];
		if(!inside(nx,ny))continue;
		if(map[nx][ny] < map[x][y]){
			cache[x][y] = cache[x][y] + dfs(nx,ny);
		}
	}

	return cache[x][y];
}


int main(){
	freopen("input.txt","r",stdin);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> map[i][j];
			cache[i][j]=-1;
		}
	}
	dfs(0,0);
	cout << cache[0][0];
	return 0;
}