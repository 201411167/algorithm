#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> str_list;

void input() {
	while (1) {
		string str; cin >> str;
		str_list.push_back(str);
		if (str[str.length() - 1] == ';') {
			break;
		}
	}
}

string func(string str) {
	string variable = "";
	string type = "";

	for (int i = 0; i < str.length(); i++) {
		if (str[i] != '[' && str[i] != ']' && str[i] != '&' && str[i] != '*') {
			variable += str[i];
		}
		else {
			type += str[i];
		}
	}
	string re_type = "";
	for (int i = type.length() - 1; i >= 0; i--) {
		if (type[i] == '[') {
			re_type += ']';
		}
		else if (type[i] == ']') {
			re_type += '[';
		}
		else {
			re_type += type[i];
		}
	}
	variable = variable.substr(0, variable.length() - 1);
	return re_type + " " + variable;
}

void solve() {
	for (int i = 1; i < str_list.size(); i++) {
		str_list[i] = str_list[0] + func(str_list[i]) + ";";
	}
	
	for (string s : str_list) {
		if (s == str_list[0])continue;
		cout << s << "\n";
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	input();
	solve();
	return 0;
}