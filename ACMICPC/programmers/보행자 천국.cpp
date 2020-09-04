#include <vector>
#include <cstring>
using namespace std;

int MOD = 20170805;

int v[501][501];
int h[501][501];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;

    memset(v, 0, sizeof(v));
    memset(h, 0, sizeof(h));
    v[1][1] = 1;
    h[1][1] = 1;
    for(int i=1;i<=m;i++){
    	for(int j=1;j<=n;j++){
    		if(city_map[i-1][j-1] == 0){
    			v[i][j] += (v[i-1][j] + h[i][j-1]) % MOD;
    			h[i][j] += (v[i-1][j] + h[i][j-1]) % MOD;
    		}
    		if(city_map[i-1][j-1] == 1){
    			v[i][j] = 0;
    			h[i][j] = 0;
    		}
    		if(city_map[i-1][j-1] == 2){
    			v[i][j] = v[i-1][j];
    			h[i][j] = h[i][j-1];
    		}
    	}
    }
    answer = v[m][n] % MOD;
    return answer;
}