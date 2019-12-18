#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void swap1(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void swap2(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void increase(int arr[]) {
	for (int i = 0; i < 5; i++) {
		arr[i]++;
	}
}

void show(int arr[]) {
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main() {
	int a = 10;
	int b = 20;

	swap1(a, b);
	cout << a << ", " << b << "\n";

	swap2(a, b);
	cout << a << ", " << b << "\n";

	int arr[5]{ 0,1,2,3,4 };
	show(arr);
	increase(arr);
	show(arr);

	return 0;
}