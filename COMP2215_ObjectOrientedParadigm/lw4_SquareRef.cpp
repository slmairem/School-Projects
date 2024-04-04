#include <iostream>
using namespace std;

int squareByValue(int a) {
	return a * a;
}

void squareByReference(int* a) {
	*a = (*a) * (*a);
}

int main() {
	int num1, num2;
	cout << "Enter num1: " << endl;
	cin >> num1;

	cout << "Enter num2: " << endl;
	cin >> num2;

	squareByReference(&num2);

	cout << "Square by value: " << squareByValue(num1) << endl;
	cout << "Square by reference: " << num2 << endl;
}

