#include "Triangle.h"

Triangle::Triangle(std::string name, double sideA, double sideB, double sideC) : Shape(name) {
    setSideA(sideA);
    setSideB(sideB);
    setSideC(sideC);
}

double Triangle::getArea() {
    double s = (sideA + sideB + sideC) / 2.0;
    return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

double Triangle::getPerimeter() {
    return sideA + sideB + sideC;
}

double Triangle::getSideA() {
    return sideA;
}

double Triangle::getSideB() {
    return sideB;
}

double Triangle::getSideC() {
    return sideC;
}

void Triangle::setSideA(double sideA) {
    if (sideA > 0) {
        this->sideA = sideA;
    }
}

void Triangle::setSideB(double sideB) {
    if (sideB > 0) {
        this->sideB = sideB;
    }
}

void Triangle::setSideC(double sideC) {
    if (sideC > 0) {
        this->sideC = sideC;
    }
}