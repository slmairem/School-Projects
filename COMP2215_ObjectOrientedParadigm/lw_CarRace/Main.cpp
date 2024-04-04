#include <iostream>
#include "Car.h"
#include "Motorcycle.h"
#include "FormulaCar.h"
#include "Track.h"
using namespace std;

int main() {
    Car Car("Car", 200, 0.7, "Toyota", "Supra", "John Doe", 0.9);
    Car.display();
    cout << "\n";

    Motorcycle Motorcycle("Motorcycle", 180, 0.9, "Yamaha", "YZF-R1", "Jane Doe", 0.9);
    Motorcycle.display();
    cout << "\n";

    FormulaCar FormulaCar("FormulaCar", 300, 0.95, "Ferrari", "SF21", "Charles Roberts", 0.9);
    FormulaCar.display();
    cout << "\n";
    
    Track track(100,0.3,0.2,0.3,0.2);
    cout << "Race Track: Australian Outback" << "\n" <<
        "Total Length: " << track.getLength() << "\n" <<
        "Top Speed Distance: " << track.getTopSpeedPct()*track.getLength() <<  "\n" <<
        "High Speed Distance: " << track.getHighHandlingPct()*track.getLength() << "\n" <<
        "Medium Speed Distance: " << track.getMediumHandlingPct()* track.getLength() << "\n" <<
        "Cruise Speed Distance: " << track.getCruiseSpeedPct()* track.getLength() <<  "\n" << endl;

    cout << "Race starts..." << "\n" <<
        "Car race time: "<< Car.race(track) << "\n" <<
        "Motorcycle race time: "<< Motorcycle.race(track) << "\n" <<
        "FormulaCar race time: "<< FormulaCar.race(track) << "\n" << endl;
        
    cout << "After Tuning" << endl;
        Car.tuning(10, 120.86);
        Motorcycle.tuning(15, 11.2);
        FormulaCar.tuning(20, 6);

    Car.display();
    cout << "\n";

    Motorcycle.display();
    cout << "\n";

    FormulaCar.display();
    cout << "\n";

    cout << "Car race time: " << Car.race(track) << "\n" <<
        "Motorcycle race time: " << Motorcycle.race(track) << "\n" <<
        "FormulaCar race time: " << FormulaCar.race(track) << "\n" << endl;

    cout << "Selma Irem Ozdemir 21070001028" << endl;
}