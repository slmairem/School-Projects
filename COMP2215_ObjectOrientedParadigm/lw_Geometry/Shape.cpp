#include "Shape.h"
#include <iostream>


Shape::Shape(std::string name) {
    this->name = name;
}

double Shape::getArea() {
    return 0.0;
}

double Shape::getPerimeter() {
    return 0.0;
}

std::string Shape::getName() {
    return name;
}

void Shape::setName(std::string name) {
    this->name = name;
}