#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define pii pair<int,int>

int getDiff(int x1, int y1, int x2, int y2){
    int diff = abs(x1-x2) + abs(y1-y2);
    return diff;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    pii l,r;
    l = {3,0};
    r = {3,2};
    
    if(hand == "left"){
        for(int i=0;i<numbers.size();i++){
            if(numbers[i] == 1){
                l={0,0};
                answer+="L";
            }
            if(numbers[i] == 4){
                l={1,0};
                answer+="L";
            }
            if(numbers[i] == 7){
                l={2,0};
                answer+="L";
            }
            if(numbers[i] == 3){
                r={0,2};
                answer+="R";
            }
            if(numbers[i] == 6){
                r={1,2};
                answer+="R";
            }
            if(numbers[i] == 9){
                r={2,2};
                answer+="R";
            }
            if(numbers[i] == 2){
                int lDiff = getDiff(l.first, l.second, 0, 1);
                int rDiff = getDiff(r.first, r.second, 0, 1);
                if(lDiff < rDiff){
                    l = {0,1};
                    answer+="L";
                }
                else if(lDiff > rDiff){
                    r = {0,1};
                    answer+="R";
                }else{
                    l = {0,1};
                    answer+="L";
                }
            }
            if(numbers[i] == 5){
                int lDiff = getDiff(l.first, l.second, 1, 1);
                int rDiff = getDiff(r.first, r.second, 1, 1);
                if(lDiff < rDiff){
                    l = {1,1};
                    answer+="L";
                }
                else if(lDiff > rDiff){
                    r = {1,1};
                    answer+="R";
                }else{
                    l = {1,1};
                    answer+="L";
                }
            }
            if(numbers[i] == 8){
                int lDiff = getDiff(l.first, l.second, 2, 1);
                int rDiff = getDiff(r.first, r.second, 2, 1);
                if(lDiff < rDiff){
                    l = {2,1};
                    answer+="L";
                }
                else if(lDiff > rDiff){
                    r = {2,1};
                    answer+="R";
                }else{
                    l = {2,1};
                    answer+="L";
                }
            }
            if(numbers[i] == 0){
                int lDiff = getDiff(l.first, l.second, 3, 1);
                int rDiff = getDiff(r.first, r.second, 3, 1);
                if(lDiff < rDiff){
                    l = {3,1};
                    answer+="L";
                }
                else if(lDiff > rDiff){
                    r = {3,1};
                    answer+="R";
                }else{
                    l = {3,1};
                    answer+="L";
                }
            }
        }
    }
    if(hand == "right"){
        for(int i=0;i<numbers.size();i++){
            if(numbers[i] == 1){
                l={0,0};
                answer+="L";
            }
            if(numbers[i] == 4){
                l={1,0};
                answer+="L";
            }
            if(numbers[i] == 7){
                l={2,0};
                answer+="L";
            }
            if(numbers[i] == 3){
                r={0,2};
                answer+="R";
            }
            if(numbers[i] == 6){
                r={1,2};
                answer+="R";
            }
            if(numbers[i] == 9){
                r={2,2};
                answer+="R";
            }
            if(numbers[i] == 2){
                int lDiff = getDiff(l.first, l.second, 0, 1);
                int rDiff = getDiff(r.first, r.second, 0, 1);
                if(lDiff < rDiff){
                    l = {0,1};
                    answer+="L";
                }
                else if(lDiff > rDiff){
                    r = {0,1};
                    answer+="R";
                }else{
                    r = {0,1};
                    answer+="R";
                }
            }
            if(numbers[i] == 5){
                int lDiff = getDiff(l.first, l.second, 1, 1);
                int rDiff = getDiff(r.first, r.second, 1, 1);
                if(lDiff < rDiff){
                    l = {1,1};
                    answer+="L";
                }
                else if(lDiff > rDiff){
                    r = {1,1};
                    answer+="R";
                }else{
                    r = {1,1};
                    answer+="R";
                }
            }
            if(numbers[i] == 8){
                int lDiff = getDiff(l.first, l.second, 2, 1);
                int rDiff = getDiff(r.first, r.second, 2, 1);
                if(lDiff < rDiff){
                    l = {2,1};
                    answer+="L";
                }
                else if(lDiff > rDiff){
                    r = {2,1};
                    answer+="R";
                }else{
                    r = {2,1};
                    answer+="R";
                }
            }
            if(numbers[i] == 0){
                int lDiff = getDiff(l.first, l.second, 3, 1);
                int rDiff = getDiff(r.first, r.second, 3, 1);
                if(lDiff < rDiff){
                    l = {3,1};
                    answer+="L";
                }
                else if(lDiff > rDiff){
                    r = {3,1};
                    answer+="R";
                }else{
                    r = {3,1};
                    answer+="R";
                }
            }
        }
    }
    return answer;
}