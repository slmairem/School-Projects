#include "FormulaCar.h"

FormulaCar::FormulaCar(std::string vehicleType, double topSpeed, double handling,std::string manufacturer,std::string model,std::string driverName, double aerodynamics)
	: RacingVehicle(vehicleType, topSpeed, handling, manufacturer, model, driverName), aerodynamics(aerodynamics)
{
}

double FormulaCar::getAerodynamics() {
	return aerodynamics;
}

void FormulaCar::setAerodynamics(double aerodynamics) {
	this->aerodynamics = aerodynamics;
}

void FormulaCar::tune(double aerodynamicsBoost) {
	aerodynamics += aerodynamicsBoost;
}

double FormulaCar::race(Track& track) {
    double highHandlingSection;
    double mediumHandlingSection;
    int lenght = track.getLength();
    double cruiseSection = lenght * track.getCruiseSpeedPct() / ((topSpeed + aerodynamics * 0.3) / 2 );
    double topSpeedSection = lenght * track.getTopSpeedPct() / (topSpeed + aerodynamics * 0.3);
    if (handling > 0.8) {
        highHandlingSection = lenght * track.getHighHandlingPct() / (topSpeed + aerodynamics * 0.3);
    }
    else {
        highHandlingSection = lenght * track.getHighHandlingPct() / ((topSpeed + aerodynamics * 0.3) * 0.8);
    }
    if (handling > 0.6) {
        mediumHandlingSection = lenght * track.getMediumHandlingPct() / (topSpeed + aerodynamics * 0.3);
    }
    else {
        mediumHandlingSection = lenght * track.getMediumHandlingPct() / ((topSpeed + aerodynamics * 0.3) * 0.9);
    }
    double time = mediumHandlingSection + highHandlingSection + cruiseSection + topSpeedSection;
    return time;
}