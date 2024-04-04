#ifndef CAR_H
#define CAR_H

#include "RacingVehicle.h"

class Car : public RacingVehicle {
private:
    double aerodynamics;

public:
    Car(std::string type, double topSpeed, double handling, std::string manufacturer, std::string model, std::string driverName, double aerodynamics);
    double getAerodynamics();
    void setAerodynamics(double aerodynamics);
    void tune(double aerodynamicsBoost);
    double race(Track& track) override;
};

#endif