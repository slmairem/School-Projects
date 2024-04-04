#include "Circle.h"

Circle::Circle(std::string name, double radius)
    : Shape{ name }, radius_{ radius } {}

double Circle::getArea() {
    return PI * radius_ * radius_;
}

double Circle::getPerimeter() {
    return 2 * PI * radius_;
}

double Circle::getRadius() const {
    return radius_;
}

void Circle::setRadius(double radius) {
    radius_ = radius;
}




