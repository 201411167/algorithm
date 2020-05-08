#include <string>
#include <vector>
#include <map>
using namespace std;

map<long long, long long> m;

long long getNextRoom(long long num) {
    if (m[num] == 0)return num;
    return m[num] = getNextRoom(m[num]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    for (long long num : room_number) {
        long long emptyRoom = getNextRoom(num);
        answer.push_back(emptyRoom);
        m[emptyRoom] = emptyRoom + 1;
    }

    return answer;
}