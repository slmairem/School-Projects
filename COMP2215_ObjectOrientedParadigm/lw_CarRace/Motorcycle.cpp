#include "Motorcycle.h"
using namespace std;

Motorcycle::Motorcycle(std::string type, double topSpeed, double handling, std::string manufacturer, std::string model, std::string driverName, double aerodynamics)
    : RacingVehicle("Motorcycle", topSpeed, handling, manufacturer, model, driverName), aerodynamics(aerodynamics)
{}

double Motorcycle::getAerodynamics()
{
    return aerodynamics;
}

void Motorcycle::setAerodynamics(double aerodynamics)
{
    this->aerodynamics = aerodynamics;
}

void Motorcycle::tune(double aerodynamicsBoost)
{
    aerodynamics += aerodynamicsBoost;
}

double Motorcycle::race(Track& track)
{
    double highHandlingSection;
    double mediumHandlingSection;
    int lenght = track.getLength();
    double cruiseSection = lenght * track.getCruiseSpeedPct() / (topSpeed / 2);
    double topSpeedSection = lenght * track.getTopSpeedPct() / (topSpeed);
    if (handling > 0.8) {
        highHandlingSection = lenght * track.getHighHandlingPct() / (topSpeed + aerodynamics * 0.2);
    }
    else {
        highHandlingSection = lenght * track.getHighHandlingPct() / ((topSpeed + aerodynamics * 0.2) * 0.8);
    }
    if (handling > 0.6) {
        mediumHandlingSection = lenght * track.getMediumHandlingPct() / (topSpeed + aerodynamics * 0.2);
    }
    else {
        mediumHandlingSection = lenght * track.getMediumHandlingPct() / ((topSpeed + aerodynamics * 0.2) * 0.9);
    }
    double time = mediumHandlingSection + highHandlingSection + cruiseSection + topSpeedSection;
    return time;
}