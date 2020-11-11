#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int d[100003][4];

int solution(vector<vector<int> > land)
{
    int answer = 0;

    d[0][0] = land[0][0];
    d[0][1] = land[0][1];
    d[0][2] = land[0][2];
    d[0][3] = land[0][3];
    
    for(int i=1;i<land.size();i++){
        d[i][0] = max(d[i-1][1] + land[i][0],
                      max(d[i-1][2] + land[i][0],
                      d[i-1][3] + land[i][0]));
        d[i][1] = max(d[i-1][0] + land[i][1],
                      max(d[i-1][2] + land[i][1],
                      d[i-1][3] + land[i][1]));
        d[i][2] = max(d[i-1][0] + land[i][2],
                      max(d[i-1][1] + land[i][2],
                      d[i-1][3] + land[i][2]));
        d[i][3] = max(d[i-1][0] + land[i][3],
                      max(d[i-1][1] + land[i][3],
                      d[i-1][2] + land[i][3]));
    }
    
    for(int i=0;i<4;i++){
        answer = max(d[land.size()-1][0],
                     max(d[land.size()-1][1],
                     max(d[land.size()-1][2],
                     d[land.size()-1][3])));
    }

    return answer;
}