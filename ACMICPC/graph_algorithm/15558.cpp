#include <iostream>
#include <queue>
using namespace std;

#define MAX 100001
int n,k;
int line[2][MAX];
int visit[2][MAX];

struct info {
	int sec;
	int loc;
	int pos;
};

bool bfs(){
	for(int i=0;i<MAX;i++){
		visit[0][i]=1e9;
		visit[1][i]=1e9;
	}
	visit[0][0]=0;

	queue<info> q;
	q.push({0,0,0});
	while(!q.empty()){
		info cur = q.front();
		q.pop();
		// cout << cur.sec << ": " << cur.loc << ", " << cur.pos << "\n";

		for(int i=0;i<3;i++){
			if(i==0){
				int nxt_sec = cur.sec + 1;
				int nxt_loc = cur.loc;
				int nxt_pos = cur.pos + 1;
				if(nxt_pos >= n)return true;
				if(line[nxt_loc][nxt_pos] == 0)continue;
				if(nxt_pos < nxt_sec)continue;
				if(visit[nxt_loc][nxt_pos] > visit[cur.loc][cur.pos] + 1){
					visit[nxt_loc][nxt_pos] = visit[cur.loc][cur.pos] + 1;
					q.push({visit[nxt_loc][nxt_pos], nxt_loc, nxt_pos});
				}
			}
			if(i==1){
				int nxt_sec = cur.sec + 1;
				int nxt_loc = cur.loc;
				int nxt_pos = cur.pos - 1;
				if(nxt_pos >= n)return true;
				if(line[nxt_loc][nxt_pos] == 0)continue;
				if(nxt_pos < nxt_sec)continue;
				if(visit[nxt_loc][nxt_pos] > visit[cur.loc][cur.pos] + 1){
					visit[nxt_loc][nxt_pos] = visit[cur.loc][cur.pos] + 1;
					q.push({visit[nxt_loc][nxt_pos], nxt_loc, nxt_pos});
				}
			}
			if(i==2){
				int nxt_sec = cur.sec + 1;
				int nxt_loc = (cur.loc + 1) % 2;
				int nxt_pos = cur.pos + k;
				if(nxt_pos >= n)return true;
				if(line[nxt_loc][nxt_pos] == 0)continue;
				if(nxt_pos < nxt_sec)continue;
				if(visit[nxt_loc][nxt_pos] > visit[cur.loc][cur.pos] + 1){
					visit[nxt_loc][nxt_pos] = visit[cur.loc][cur.pos] + 1;
					q.push({visit[nxt_loc][nxt_pos], nxt_loc, nxt_pos});
				}
			}
		}
	}
	return false;
}

int main(){
	freopen("input.txt","r",stdin);
	cin >> n >> k;
	for(int i=0;i<n;i++){
		scanf("%1d", &line[0][i]);
	}
	for(int i=0;i<n;i++){
		scanf("%1d", &line[1][i]);
	}

	cout << bfs();

	return 0;
}