#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int solution(int n, vector<int> coins) {
    vector<int> ways(n+1);
    ways[0] = 1;
    
    for(int coin : coins){
        for(int i=coin; i<=n; i++){
            ways[i] += ways[i-coin] % MOD;
        }
    }
    
    return ways[n];
}