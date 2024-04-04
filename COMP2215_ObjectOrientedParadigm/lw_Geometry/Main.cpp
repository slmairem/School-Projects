#include <iostream>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
using namespace std;


int main() {
	Rectangle rect("Rectangle", 5.0, 4.0);

	Circle circle("Circle", 10.0);

	Triangle triangle("Triangle", 3.0, 4.0, 5.0);

	cout << "Shape: " << rect.getName() << endl;
	cout << "Width: " << rect.getWidth() << endl;
	cout << "Height: " << rect.getHeight() << endl;
	cout << "Area: " << rect.getArea() << endl;
	cout << "Perimeter: " << rect.getPerimeter() << endl;

	cout << "Shape: " << circle.getName() << endl;
	cout << "Radius: " << circle.getRadius() << endl;
	cout << "Area: " << circle.getArea() << endl;
	cout << "Perimeter: " << circle.getPerimeter() << endl;

	cout << "Shape: " << triangle.getName() << endl;
	cout << "Side A: " << triangle.getSideA() << endl;
	cout << "Side B: " << triangle.getSideB() << endl;
	cout << "Side C: " << triangle.getSideC() << endl;
	cout << "Area: " << triangle.getArea() << endl;
	cout << "Perimeter: " << triangle.getPerimeter() << endl;


	cout << "Selma Irem Ozdemir 21070001028 " << endl;
	return 0;
}