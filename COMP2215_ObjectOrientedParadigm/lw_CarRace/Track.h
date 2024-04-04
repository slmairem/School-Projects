#ifndef TRACK_H
#define TRACK_H

class Track {
private:
    int length;
    double topSpeedPct;
    double highHandlingPct;
    double mediumHandlingPct;
    double cruiseSpeedPct;

public:
    Track(int length, double topSpeedPct, double highHandlingPct, double mediumHandlingPct, double cruiseSpeedPct);
    int getLength();
    double getTopSpeedPct();
    double getHighHandlingPct();
    double getMediumHandlingPct();
    double getCruiseSpeedPct();
};

#endif