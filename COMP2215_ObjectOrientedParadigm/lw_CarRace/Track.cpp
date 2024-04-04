#include "Track.h"
#include <stdexcept>

Track::Track(int length, double topSpeedPct, double highHandlingPct, double mediumHandlingPct, double cruiseSpeedPct) {
    double sum = topSpeedPct + highHandlingPct + mediumHandlingPct + cruiseSpeedPct;
    if (sum != 1.0) {
        throw std::invalid_argument("Track percentage attributes must sum up to 1.0.");
    }
    this->length = length;
    this->topSpeedPct = topSpeedPct;
    this->highHandlingPct = highHandlingPct;
    this->mediumHandlingPct = mediumHandlingPct;
    this->cruiseSpeedPct = cruiseSpeedPct;
}

int Track::getLength() {
    return length;
}

double Track::getTopSpeedPct() {
    return topSpeedPct;
}

double Track::getHighHandlingPct() {
    return highHandlingPct;
}

double Track::getMediumHandlingPct() {
    return mediumHandlingPct;
}

double Track::getCruiseSpeedPct() {
    return cruiseSpeedPct;
}