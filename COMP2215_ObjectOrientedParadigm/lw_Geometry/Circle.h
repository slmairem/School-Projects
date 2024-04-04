#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include "Shape.h"
using namespace std;

class Circle : public Shape {
public:
    Circle(string name, double radius);
    double getArea() override;
    double getPerimeter() override;
    double getRadius() const;
    void setRadius(double radius);

private:
    const double PI = 3.1415;
    double radius_;
};

#endif