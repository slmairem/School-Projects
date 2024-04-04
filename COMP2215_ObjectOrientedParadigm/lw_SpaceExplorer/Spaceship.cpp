#include "Spaceship.h"
#include <iostream>
using namespace std;

Spaceship::Spaceship(std::string name, double fuel)
    : name(name), fuel(fuel), currentLocation(nullptr) {
}

std::string Spaceship::getName() const {
    return name;
}

double Spaceship::getFuel() const {
    return fuel;
}

Planet* Spaceship::getCurrentLocation() const {
    return currentLocation;
}

void Spaceship::travel(Planet& destination, double fuelPerDistance)
{
    if (currentLocation != nullptr) {
        double distance = currentLocation->distanceTo(destination);
        double fuelNeeded = distance * fuelPerDistance;
        if (fuel >= fuelNeeded) {
            fuel -= fuelNeeded;
            currentLocation = &destination;
            cout << "Travel to " << destination.getName() << " successful!\n";
        }
        else {
            cout << "Not enough fuel to travel to " << destination.getName() << ".\n";
        }
    }
    else {
        double fuelNeeded = destination.getDistanceFromSun() * fuelPerDistance;
        if (fuel >= fuelNeeded) {
            fuel -= fuelNeeded;
            currentLocation = &destination;
            cout << "Travel to " << destination.getName() << " successful!\n";
        }
        else {
            cout << "Not enough fuel to travel to " << destination.getName() << ".\n";
        }
    }
}

 void Spaceship::displayInfo() const {
    cout << "Name name: " << name << endl;
    cout << "Fuel: " << fuel << endl;
    if (currentLocation != nullptr) {
        cout << "Current location: " << currentLocation->getName() << endl;
    }
    else {
        cout << "Current location: Unknown" << endl;
    }
}