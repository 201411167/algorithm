#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, string> m;
map<string, string> ::iterator iter;
vector<pair<string, string>>actions;

vector<string> solution(vector<string> record) {

	vector<string> answer;
	for (int i = 0; i < record.size(); i++) {
		string str = record[i];
		string action = "";
		string id = "";
		string nickname = "";
		int index = 0;
		for (int j = 0; j < str.length(); j++) {
			if (index == 0) {
				if (str[j] != ' ') {
					action += str[j];
				}
				if (str[j] == ' ') {
					index++;
					continue;
				}
			}
			if (index == 1) {
				if (str[j] != ' ') {
					id += str[j];
				}
				if (str[j] == ' ') {
					index++;
					continue;
				}
			}
			if (index == 2) {
				if (str[j] != NULL) {
					nickname += str[j];
				}
			}
		}
		actions.push_back({ action, id });
		if (action == "Enter" || action == "Change") {
			if (m.find(id) != m.end()) {
				m.erase(id);
				m.insert({ id, nickname });
			}
			else {
				m.insert({ id, nickname });
			}
		}
	}
	for (int i = 0; i < actions.size(); i++) {
		string action = actions[i].first;
		string id = actions[i].second;
		string nickname = m.find(id)->second;
		if (action == "Enter") {
			string result = nickname + "님이 들어왔습니다.";
			answer.push_back(result);
		}
		if (action == "Leave") {
			string result = nickname + "님이 나갔습니다.";
			answer.push_back(result);
		}
	}
	return answer;
}