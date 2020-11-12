#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct branch{
    int from;
    int to;
    int cost;
};
bool comp(branch a, branch b){
    if(a.cost < b.cost){
        return true;
    }
    return false;
}

int parent[101];
int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<branch>v;
    
    for(int i=0;i<costs.size();i++){
        v.push_back({costs[i][0], costs[i][1], costs[i][2]});
    }
    
    sort(v.begin(), v.end(), comp);
    
    for(int i=0;i<101;i++){
        parent[i] = i;
    }
    
    for(int i=0;i<v.size();i++){
        int a = find(v[i].from);
        int b = find(v[i].to);
        int c = v[i].cost;
        if(a != b){
            parent[a] = b;
            answer += c;
        }
    }
    
    return answer;
}