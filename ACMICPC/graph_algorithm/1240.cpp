#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<pair<int,int>> T[1001];
int dist[1001][1001];

void init(){
	for(int i=0;i<1001;i++){
		for(int j=0;j<1001;j++){
			dist[i][j] = 1e9;
		}
	}
}

int main(){
	freopen("input.txt","r",stdin);
	init();

	cin >> n >> m;
	for(int i=0;i<n-1;i++){
		int a,b,c;
		cin >> a >> b >> c;
		T[a].push_back({b,c});
		T[b].push_back({a,c});
		dist[a][b] = min(dist[a][b], c);
		dist[b][a] = min(dist[b][a], c);
	}

	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		cout << dist[x][y] << "\n";
	}


	return 0;
}