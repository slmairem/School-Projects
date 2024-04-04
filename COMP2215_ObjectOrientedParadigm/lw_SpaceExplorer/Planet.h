#ifndef PLANET_H
#define PLANET_H

#include <string>
using namespace std;

class Planet {
public:
    Planet(string name, double distanceFromSun, double diameter);
    string getName() const;
    double getDistanceFromSun()const;
    double getDiameter() const;
    double distanceTo(const Planet& other);

private:
    string name;
    double distanceFromSun;
    double diameter;
};

#endif