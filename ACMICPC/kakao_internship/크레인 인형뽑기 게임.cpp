#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int R = board.size();
    int C = board[0].size();

    stack<int> list;

    for (int i = 0; i < moves.size(); i++) {
        int c = moves[i] - 1;
        for (int i = 0; i < R; i++) {
            if (board[i][c] != 0) {
                if (list.size() > 0) {
                    if (list.top() == board[i][c]) {
                        answer += 2;
                        board[i][c] = 0;
                        list.pop();
                    }
                    else {
                        list.push(board[i][c]);
                        board[i][c] = 0;
                    }
                }
                else {
                    list.push(board[i][c]);
                    board[i][c] = 0;
                }
                break;
            }
        }
    }
    while (!list.empty()) {
        cout << list.top() << " ";
        list.pop();
    }
    return answer;
}