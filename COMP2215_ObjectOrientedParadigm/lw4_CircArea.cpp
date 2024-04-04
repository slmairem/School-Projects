#include <iostream>
using namespace std;

inline double area(double a) {
	return 3.14 * a * a;
}

int main() {
	double a[10];

	for (int i = 0; i < 10; i++) {
		cout << "Enter a radius: " << endl;
		cin >> a[i];
	}


	for (int i = 0; i < 10; i++) {
		if (a[i] < 0) {
			cout << "invalid value" << endl;
		}

		if (a[i] > 0) {
			cout << "Area: " << area(a[i]) << endl;
		}
	}
}

//Selma Irem Ozdemir 21070001028