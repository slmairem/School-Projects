#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
using namespace std;

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(string name, double width, double height);
    double getArea() override;
    double getPerimeter() override;
    double getWidth();
    double getHeight();
    void setWidth(double width);
    void setHeight(double height);
};

#endif