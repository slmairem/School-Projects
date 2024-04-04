#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using namespace std;

class Shape {
protected:
    string name;
public:
    Shape(string name);
    virtual double getArea();
    virtual double getPerimeter();
    string getName();
    void setName(string name);
};

#endif