#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
	freopen("Text.txt", "r", stdin);
	//input & make the sentence into the answer
	string input;  cin >> input;
	int index= 1e9;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '-') {
			index = i;
		}
		if (input[i] == '+' && i > index) {
			input[i] = '-';
		}
	}

	//make the sentence to the result of integer
	int *arr = new int[input.length()];
	index = 0;
	string num;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] != '-' && input[i] != '+') {
			num += input[i];
		}
		if (input[i] == '-' || input[i] == '+' || i == input.length() - 1) {
			arr[index] = stoi(num);
			index++;
			num = input[i];
		}
	}

	//find the answer
	int answer = 0;
	for (int i = 0; i < index; i++) {
		answer += arr[i];
	}

	cout << answer;
	return 0;
}