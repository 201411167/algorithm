#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    vector<int>v;
    getline(cin, s);
    int idx = 0;
    for (int i = 0; i < s.size(); i++)
    {
        // if(s[i] == ', ') <- 구분자 조건
        if (s[i] == ' ')
        {
            v.push_back(stoi(s.substr(idx, i - idx)));
            idx = i + 1;
        }
    }
    v.push_back(stoi(s.substr(idx)));
}