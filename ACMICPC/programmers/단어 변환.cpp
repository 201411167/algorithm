#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool chk[51];
struct info {
    string str;
    int step;
};

int getDiff(string before, string after) {
    int rtn = 0;
    for (int i = 0; i < before.size(); i++) {
        if (before[i] != after[i]) {
            rtn++;
        }
    }
    return rtn;
}

int minValue = 1e9;
void bfs(vector<string> words, string target) {
    info start = { words[0], 0 };
    queue<info>q;
    q.push(start);
    chk[0] = true;
    while (!q.empty()) {
        info cur = q.front();
        q.pop();
        if (cur.str == target) {
            minValue = min(minValue, cur.step);
        }
        for (int i = 0; i < words.size(); i++) {
            string nxt = words[i];
            int diff = getDiff(cur.str, nxt);
            if (diff > 1)continue;
            if (!chk[i]) {
                chk[i] = true;
                q.push({ nxt, cur.step + diff });
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    vector<string>list;
    list.push_back(begin);
    for (int i = 0; i < words.size(); i++) {
        list.push_back(words[i]);
    }

    bfs(list, target);
    if (minValue == 1e9) {
        answer = 0;
    }
    else {
        answer = minValue;
    }
    return answer;
}