#include <iostream>
#include "RacingVehicle.h"

using namespace std;

RacingVehicle::RacingVehicle(string type, double topSpeed, double handling, string manufacturer, string model, string driverName) {
    this->vehicleType = type;
    this->topSpeed = topSpeed;
    this->handling = handling;
    this->manufacturer = manufacturer;
    this->model = model;
    this->driverName = driverName;
}

double RacingVehicle::race(Track& track) {
    double time = track.getLength() / this->topSpeed;
    return time;
}

void RacingVehicle::tuning(double topSpeedIncrease, double handlingIncrease) {
    this->topSpeed += this->topSpeed * (topSpeedIncrease / 100.0);
    this->handling += this->handling * (handlingIncrease / 100.0);
    if (handling > 1) {
        handling = 1;
    }
}

void RacingVehicle::display() {
    cout << "Vehicle type: " << this->vehicleType << endl;
    cout << "Top speed: " << this->topSpeed << endl;
    cout << "Handling: " << this->handling << endl;
    cout << "Manufacturer: " << this->manufacturer << endl;
    cout << "Model: " << this->model << endl;
    cout << "Driver name: " << this->driverName << endl;
}