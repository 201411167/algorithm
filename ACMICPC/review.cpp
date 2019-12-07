#include <iostream>
using namespace std;

void func_by_value(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void func_by_ref(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void call_by_ref_pointer(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	int a = 10;
	int b = 20;
	func_by_value(a, b);
	cout << a << ", " << b << "\n";
	func_by_ref(a, b);
	cout << a << ", " << b << "\n";
	call_by_ref_pointer(&a, &b);
	cout << a << ", " << b << "\n";
}