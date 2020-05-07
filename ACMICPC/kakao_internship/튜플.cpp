#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b) {
	return a.length() < b.length();
}

vector<int> solution(string s) {
	s.erase(s.begin(), s.begin() + 1);
	s.pop_back();

	vector<string> list;
	string tmp = "";
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		tmp += c;
		if (c == '}') {
			i++;
			list.push_back(tmp);
			tmp = "";
			continue;
		}
	}

	sort(list.begin(), list.end(), comp);

	vector<int>answer;

	for (int i = 0; i < list.size(); i++) {
		string str = list[i];
		str.erase(str.begin(), str.begin() + 1);
		str.pop_back();
		for (int j = 0; j < str.size(); j++) {
			tmp += str[j];
			if (str[j] == ',') {

				int t = stoi(tmp);
				if (answer.empty()) {
					answer.push_back(t);
				}
				else {
					bool include = false;
					for (int i = 0; i < answer.size(); i++) {
						if (answer[i] == t) {
							include = true;
						}
					}
					if (include == false) {
						answer.push_back(t);
					}
				}
				tmp = "";
				continue;
			}
			else if (j == str.size() - 1) {
				int t = stoi(tmp);
				if (answer.empty()) {
					answer.push_back(t);
				}
				else {
					bool include = false;
					for (int i = 0; i < answer.size(); i++) {
						if (answer[i] == t) {
							include = true;
						}
					}
					if (include == false) {
						answer.push_back(t);
					}
				}
				tmp = "";
				continue;
			}
		}
	}
	return answer;
}