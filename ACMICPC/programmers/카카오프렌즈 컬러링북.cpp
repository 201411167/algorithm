#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define pii pair<int,int>

bool visit[101][101];

void init(){
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			visit[i][j] = false;
		}
	}
}

pii bfs(vector<vector<int>> map){
	pii rtn;
	int area = 0;
	int max_area = 0;

	int n = map.size();
	int m = map[0].size();
	init();
	queue<pii> q;
	int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j] != 0 && visit[i][j] == false){
				area++;
				visit[i][j]=true;
				q.push({i,j});
				int cnt_area = 0;
				while(!q.empty()){
					int cx = q.front().first;
					int cy = q.front().second;
					q.pop();
					cnt_area++;
					max_area = max(max_area, cnt_area);
					for(int d=0;d<4;d++){
						int nx = cx + dir[d][0];
						int ny = cy + dir[d][1];
						if(nx < 0 || ny <0 || nx >= n || ny >= m) continue;
						if(map[nx][ny] == map[cx][cy] && visit[nx][ny] == false){

							visit[nx][ny] = true;
							q.push({nx,ny});
						}
					}
				}
			}
		}
	}
	rtn = {area, max_area};
	return rtn;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    pii result = bfs(picture);

    vector<int> answer(2);
    answer[0] = result.first;
    answer[1] = result.second;
    return answer;
}