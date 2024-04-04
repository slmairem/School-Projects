#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <string>
#include "Planet.h"

class Spaceship {
public:
    Spaceship(string name, double fuel);
    string getName() const;
    double getFuel() const;
    Planet* getCurrentLocation() const;
    void travel(Planet& destination, double fuelPerDistance);
    void displayInfo() const;

private:
    string name;
    double fuel;
    Planet* currentLocation;
};

#endif