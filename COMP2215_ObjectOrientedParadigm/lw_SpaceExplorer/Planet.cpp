#include "Planet.h"
#include <cmath>
using namespace std;


Planet::Planet(string name, double distanceFromSun, double diameter)
    : name(name), distanceFromSun(distanceFromSun), diameter(diameter) {
}

std::string Planet::getName() const {
    return name;
}

double Planet::getDistanceFromSun()const{
    return distanceFromSun;
}

double Planet::getDiameter() const {
    return diameter;
}

double Planet::distanceTo(const Planet& destination)
{
    double x = pow(destination.getDistanceFromSun() - distanceFromSun, 2);
    double y = pow(destination.getDiameter() - diameter, 2);
    return sqrt(x + y);
}
