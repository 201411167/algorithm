#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool chk[8];
int blen, ulen;
set<string> s;

void solve(int idx, string res, vector<string>user_id, vector<string> banned_id) {
    if (idx == blen) {
        sort(res.begin(), res.end());
        s.insert(res);
        return;
    }

    string bid = banned_id[idx];
    int bidlen = bid.size();

    for (int i = 0; i < ulen; i++) {
        string uid = user_id[i];
        if (uid.size() != bidlen)continue;
        if (chk[i])continue;

        bool flag = true;

        for (int j = 0; j < bidlen; j++) {
            if (bid[j] == '*')continue;
            if (uid[j] != bid[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            chk[i] = true;
            solve(idx + 1, res + to_string(i), user_id, banned_id);
            chk[i] = false;
        }
    }
}

int solution(vector<string>user_id, vector<string>banned_id) {
    int answer = 0;
    ulen = user_id.size();
    blen = banned_id.size();

    solve(0, "", user_id, banned_id);

    answer = s.size();

    return answer;
}