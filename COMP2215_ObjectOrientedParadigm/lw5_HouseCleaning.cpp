#include <iostream>
#include <string>
using namespace std;

class MyDate {
	public:
		int day;
		string month;
		int year;
};

class MyTime {
	public:
		int hour;
		int minute;
		int seconds;
};

void printDate(MyDate date, MyTime time) {
	cout << "Printing date and time with MyDate and MyTime Parameters" << endl;
	cout << "Current date is " << date.day << " " << date.month << " " << date.year << " " << time.hour << ":" << time.minute << ":" << time.seconds << endl;
}

void printDate(MyDate date) {
	cout << "Printing date and time with MyDate Parameter" << endl;
	cout << "Current date is " << date.day << " " << date.month << " " << date.year << " " << endl;

}

int main() {
	MyDate x;
	x.day = 10;
	x.month = "March";
	x.year = 2023;
	MyTime y;
	y.hour = 16;
	y.minute = 17;
	y.seconds = 20;
	printDate(x, y);
	printDate(x);

	return 0;
}