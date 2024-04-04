#include <iostream>
using namespace std;

void swap(int* a) {
	*a = (rand() % 100);
}

int main() {
	int x = 55;
	int y = x;

	cout << "x: " << x << endl;
	cout << "y: " << y << endl;

	swap(&y);

	cout << "new x: " << x << endl;
	cout << "new y: " << y << endl;

	return 0;
}
