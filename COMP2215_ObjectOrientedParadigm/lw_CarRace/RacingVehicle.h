#ifndef RACINGVEHICLE_H
#define RACINGVEHICLE_H

#include <string>
#include "Track.h"

class RacingVehicle {
protected:
    std::string vehicleType;
    double topSpeed;
    double handling;
    std::string manufacturer;
    std::string model;
    std::string driverName;

public:
    RacingVehicle(std::string type, double topSpeed, double handling, std::string manufacturer, std::string model, std::string driverName);
    virtual double race(Track& track);
    void tuning(double topSpeedIncrease = 0, double handlingIncrease = 0);
    void display();
};

#endif