#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> aware;
vector<vector<int>> map;
bool chk[51];
int answer;

void dfs(int person){
	if(chk[person]) return;
	chk[person] = true;

	for(int i=0;i<m;i++){
		bool included = false;
		for(int j=0;j<map[i].size();j++){
			if(map[i][j] == person){
				included = true;
			}
		}
		if(included){
			for(int j=0;j<map[i].size();j++){
				int nxt = map[i][j];
				dfs(nxt);
			}
		}
	}
}

int main(){
	freopen("input.txt","r",stdin);

	cin >> n >> m;
	
	// 벡터 <진실을 아는 사람>
	int aware_size; cin >> aware_size;
	while(aware_size--){
		int num; cin >> num;
		aware.push_back(num);
	}

	// 파티장의 사람들 
	for(int i=0;i<m;i++){
		int num; cin >> num;
		vector<int> tmp;
		for(int j=0;j<num;j++){
			int p; cin >> p;
			tmp.push_back(p);
		}
		map.push_back(tmp);
	}

	// 진실을 아는 사람들로부터 dfs 탐색
	for(int i=0;i<aware.size();i++){
		dfs(aware[i]);
	}

	// 진실을 아는 사람이 전혀 없는 파티장이라면 answer++;
	for(int i=0;i<m;i++){
		int cnt = 0;
		for(int j=0;j<map[i].size();j++){
			if(!chk[map[i][j]]){
				cnt++;
			}
		}
		if(cnt == map[i].size()){
			answer++;
		}
	}

	cout << answer;

	return 0;

}