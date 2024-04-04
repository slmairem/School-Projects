#include "Car.h"

Car::Car(std::string type, double topSpeed, double handling, std::string manufacturer, std::string model, std::string driverName, double aerodynamics)
    : RacingVehicle("Car", topSpeed, handling, manufacturer, model, driverName), aerodynamics(aerodynamics) {}

double Car::getAerodynamics() {
    return aerodynamics;
}

void Car::setAerodynamics(double aerodynamics) {
    this->aerodynamics = aerodynamics;
}

void Car::tune(double aerodynamicsBoost) {
    aerodynamics += aerodynamicsBoost;
}
double Car::race(Track& track) {
    double highHandlingSection;
    double mediumHandlingSection;
    int lenght = track.getLength();
    double cruiseSection = lenght * track.getCruiseSpeedPct() / (topSpeed / 2);
    double topSpeedSection = lenght * track.getTopSpeedPct() / (topSpeed + aerodynamics * 0.1);
    if (handling > 0.8) {
        highHandlingSection = lenght * track.getHighHandlingPct() / (topSpeed + aerodynamics * 0.1);
    }
    else {
        highHandlingSection = lenght * track.getHighHandlingPct() / ((topSpeed + aerodynamics * 0.1)*0.8);
    }
    if (handling > 0.6) {
        mediumHandlingSection = lenght * track.getMediumHandlingPct() / (topSpeed + aerodynamics * 0.1);
    }
    else {
        mediumHandlingSection = lenght * track.getMediumHandlingPct() / ((topSpeed + aerodynamics * 0.1) * 0.9);
    }
    double time = mediumHandlingSection + highHandlingSection + cruiseSection + topSpeedSection;
    return time;
}
