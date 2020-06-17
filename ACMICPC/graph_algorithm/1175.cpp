#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n,m;
int sx,sy;
int map[51][51];
int visit[51][51][4][1 << 3];
int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

struct info {
	int x,y;
	int cur_d;
	int status;
	int dist;
};

void input(){
	cin >> n >> m;
	int num = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char c; cin >> c;
			if(c == '.'){
				map[i][j] = 0;
			}
			if(c == '#'){
				map[i][j] = 9;
			}
			if(c == 'S'){
				map[i][j] = 0;
				sx = i;
				sy = j;
			}
			if(c == 'C'){
				map[i][j] = ++num;
			}
		}
	}
}

bool inside(int x, int y){
	return x>=0 && y>=0 && x<n && y<m;
}

void init(){
	for(int i=0;i<51;i++){
		for(int j=0;j<51;j++){
			for(int k=0;k<4;k++){
				for(int l=0;l<(1 << 3);l++){
					visit[i][j][k][l] = 1e9;
				}
			}
		}
	}
}

int answer = 1e9;
void bfs(){	
	queue<info>q;
	for(int i=0;i<4;i++){
		init();
		visit[sx][sy][i][1]=0;
		q.push({sx,sy,i,1,0});
		while(!q.empty()){
			int cx = q.front().x;
			int cy = q.front().y;
			int cd = q.front().cur_d;
			int cs = q.front().status;
			int dist = q.front().dist;
			q.pop();

			if((cs & (1 << 1)) && (cs & (1 << 2))){
				answer = min(answer, dist);
			}

			for(int d=0;d<4;d++){
				if(cd == d)continue;
				int nx = cx + dir[d][0];
				int ny = cy + dir[d][1];
				if(!inside(nx,ny))continue;
				if(map[nx][ny] == 9)continue;
				if(map[nx][ny] == 0){
					if(visit[nx][ny][d][cs] > visit[cx][cy][cd][cs] + 1){
						visit[nx][ny][d][cs] = visit[cx][cy][cd][cs] + 1;
						q.push({nx,ny,d,cs,dist + 1});
					}
				}
				if(map[nx][ny] == 1){
					if(cs & (1 << 1))continue;
					if(visit[nx][ny][d][cs | (1 << 1)] > visit[cx][cy][cd][cs] + 1){
						visit[nx][ny][d][cs | (1 << 1)] = visit[cx][cy][cd][cs] + 1;
						q.push({nx,ny,d,cs | (1 << 1),dist + 1});
					}
				}
				if(map[nx][ny] == 2){
					if(cs & (1 << 2))continue;
					if(visit[nx][ny][d][cs | (1 << 2)] > visit[cx][cy][cd][cs] + 1){
						visit[nx][ny][d][cs | (1 << 2)] = visit[cx][cy][cd][cs] + 1;
						q.push({nx,ny,d,cs | (1 << 2),dist + 1});
					}
				}
			}
		}
	}
	if(answer != 1e9){
		cout << answer << "\n";
	}else{
		cout << -1 << "\n";
	}
}

int main(){
	freopen("input.txt","r",stdin);
	input();
	bfs();
	return 0;
}