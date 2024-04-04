#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "RacingVehicle.h"
#include "Track.h"

class Motorcycle : public RacingVehicle {
private:
    double aerodynamics;

public:
    Motorcycle(std::string type, double topSpeed, double handling, std::string manufacturer, std::string model, std::string driverName, double aerodynamics);
    double getAerodynamics();
    void setAerodynamics(double aerodynamics);
    void tune(double aerodynamicsBoost);
    double race(Track& track) override;
};

#endif