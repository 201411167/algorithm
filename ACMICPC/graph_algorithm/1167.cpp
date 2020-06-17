#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100001

int n;
vector<pair<int,int>> T[MAX];
bool visit[MAX];

void init(){
	for(int i=0;i<MAX;i++){
		visit[i]=false;
	}
}

int answer;
int destination;
void dfs(int v, int d){
	if(visit[v]){
		return;
	}

	visit[v]=true;

	if(answer < d){
		answer = d;
		destination = v;
	}

	for(int i=0;i<T[v].size();i++){
		dfs(T[v][i].first, d + T[v][i].second);
	}
}

int main(){
	freopen("input.txt","r",stdin);
	cin >> n;
	for(int i=1;i<=n;i++){
		int x; cin >> x;
		while(1){
			int a; cin >> a;
			if(a == -1)break;
			int b; cin >> b;
			if(b == -1)break;
			T[x].push_back({a,b});
			T[a].push_back({x,b});
		}
	}

	init();
	dfs(1,0);
	answer = 0;
	init();
	dfs(destination,0);


	cout << answer;
	return 0;
}