#include "Rectangle.h"

Rectangle::Rectangle(std::string name, double width, double height) : Shape(name) {
    this->width = width;
    this->height = height;
}

double Rectangle::getArea() {
    return width * height;
}

double Rectangle::getPerimeter() {
    return 2 * (width + height);
}

double Rectangle::getWidth() {
    return this->width;
}

double Rectangle::getHeight() {
    return this->height;
}

void Rectangle::setWidth(double width) {
    this->width = width;
}

void Rectangle::setHeight(double height) {
    this->height = height;
}