#include <iostream>
#include <queue>
using namespace std;

#define pii pair<int,int>

int n,m;
int map[53][53];
int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int maxi;
int answer;

bool inside(int x, int y){
	return x>=0 && y>=0 && x<=n+1 && y<=m+1;
}

void bfs(int h){
	queue<pii>q;
	map[0][0] = h;
	q.push({0,0});
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for(int d=0;d<4;d++){
			int nx = cx + dir[d][0];
			int ny = cy + dir[d][1];
			if(!inside(nx,ny))continue;
			if(map[nx][ny] < h){
				map[nx][ny] = h;
				q.push({nx,ny});
			}
		}
	}
}

int main(){
	freopen("input.txt","r",stdin);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%1d", &map[i][j]);
			maxi = max(maxi, map[i][j]);
		}
	}

	for(int w = 1; w<= maxi; w++){
		bfs(w);

		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(map[i][j] < w){
					answer++;
					map[i][j]++;
				}
			}
		}
	}

	cout << answer;
	return 0;
}