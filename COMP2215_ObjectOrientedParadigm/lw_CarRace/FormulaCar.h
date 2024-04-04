#ifndef FORMULACAR_H
#define FORMULACAR_H

#include "RacingVehicle.h"
#include "Track.h"

class FormulaCar : public RacingVehicle {
private:
    double aerodynamics;

public:

    FormulaCar(std::string type, double topSpeed, double handling, std::string manufacturer, std::string model, std::string driverName,double aerodynamics);
    double getAerodynamics();
    void setAerodynamics(double aerodynamics);
    void tune(double aerodynamicsBoost);
    double race(Track& track) override;
};

#endif