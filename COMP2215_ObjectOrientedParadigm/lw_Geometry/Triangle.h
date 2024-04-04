#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <cmath>
using namespace std;

class Triangle : public Shape {
public:
    Triangle(string name, double sideA, double sideB, double sideC);
    double getArea() override;
    double getPerimeter() override;
    double getSideA();
    double getSideB();
    double getSideC();
    void setSideA(double sideA);
    void setSideB(double sideB);
    void setSideC(double sideC);

private:
    double sideA, sideB, sideC;
};

#endif