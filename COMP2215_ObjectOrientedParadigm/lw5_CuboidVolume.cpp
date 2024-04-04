#include <iostream>
#include <stdio.h>
using namespace std;

int volume(int x = 5, int y = 6, int z = 7) {
	return x * y * z;
}

int* generate_values() {
	int* arr = new int[30];
	int i;
	for (i = 0; i < 30; i++) {
		arr[i] = (rand() % 90) + 10;
	}
	return arr;
}

int main() {
	srand(time(NULL));
	int* array = generate_values();
	int a = rand() % 30;
	int b = rand() % 30;
	int c = rand() % 30;

	cout << "A) " << volume() << endl;
	cout << "B) " << volume(array[a]) << endl;
	cout << "C) " << volume(array[a], array[b]) << endl;
	cout << "D) " << volume(array[a], array[b], array[c]) << endl;

	return 0;
}