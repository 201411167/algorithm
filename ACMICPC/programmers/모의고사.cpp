#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int one[5] = { 1,2,3,4,5 };
int two[8] = { 2,1,2,3,2,4,2,5 };
int three[10] = { 3,3,1,1,2,2,4,4,5,5 };

//int student[3] = { 0,0,0 };

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int>they(3);
    for (int i = 0; i < answers.size(); i++) {
        if (one[i % 5] == answers[i]) {
            //student[0]++;
            they[0]++;
        }
        if (two[i % 8] == answers[i]) {
            //student[1]++;
            they[1]++;
        }
        if (three[i % 10] == answers[i]) {
            //student[2]++;
            they[2]++;
        }
    }

    int they_max = *max_element(they.begin(), they.end());
    for (int i = 0; i < 3; i++) {
        if (they[i] == they_max) answer.push_back(i + 1);
    }

    /*if (student[0] == student[1] && student[1] == student[2]) {
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
    }
    else if (student[0] == student[1]) {
        if (student[2] > student[0]) {
            answer.push_back(3);
        }
        else {
            answer.push_back(1);
            answer.push_back(2);
        }
    }
    else if (student[1] == student[2]) {
        if (student[0] > student[1]) {
            answer.push_back(1);
        }
        else {
            answer.push_back(2);
            answer.push_back(3);
        }
    }
    else if (student[2] == student[0]) {
        if (student[1] > student[2]) {
            answer.push_back(2);
        }
        else {
            answer.push_back(1);
            answer.push_back(3);
        }
    }
    else {
        if (student[0] > student[1] && student[0] > student[2]) {
            answer.push_back(1);
        }
        if (student[1] > student[0] && student[1] > student[2]) {
            answer.push_back(2);
        }
        if (student[2] > student[0] && student[2] > student[1]) {
            answer.push_back(3);
        }
    }*/



    sort(answer.begin(), answer.end());
    return answer;
}