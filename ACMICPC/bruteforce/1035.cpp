#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int total;
char map[5][5];
int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
vector<pair<int,int>> v;

void show(char tmp[5][5]){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout << tmp[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

bool inside(int x, int y){
	return x>=0 && y>=0 && x<5 && y<5;
}

bool connect(char map[5][5]){
	queue<pair<int,int>>q;
	bool visit[5][5];
	memset(visit, false, sizeof(visit));

	int x,y;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(map[i][j] == '*'){
				x = i;
				y = j;
			}
		}
	}

	int block = 0;
	q.push({x,y});
	visit[x][y]=true;
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		block++;

		for(int d=0;d<4;d++){
			int nx = cx + dir[d][0];
			int ny = cy + dir[d][1];
			if(!inside(nx,ny))continue;
			if(map[nx][ny] == map[cx][cy]){
				if(!visit[nx][ny]){
					visit[nx][ny] = true;
					q.push({nx,ny});
				}
			}
		}
	}


	if(block == total){
		return true;
	}
	return false;
}

int get_dist(int a, int b, int c, int d){
	return abs(a - c) + abs(b - d);
}

int answer = 1e9;
void dfs(int cnt, int dist, char tmp[5][5]){
	if(cnt == total){
		if(connect(tmp)){
			answer = min(answer, dist);
		}
		return;
	}

	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(tmp[i][j] == '.'){
				tmp[i][j] = '*';
				dfs(cnt + 1, dist + get_dist(v[cnt].first, v[cnt].second, i, j) ,tmp);
				tmp[i][j] = '.';				
			}
		}
	}
}

int main(){
	freopen("input.txt","r",stdin);
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin >> map[i][j];
			if(map[i][j] == '*'){
				total++;
				v.push_back({i,j});
			}
		}
	}
	
	char tmp[5][5];
	memset(tmp, '.', sizeof(tmp));
	dfs(0, 0, tmp);
	cout << answer; 

	return 0;
}