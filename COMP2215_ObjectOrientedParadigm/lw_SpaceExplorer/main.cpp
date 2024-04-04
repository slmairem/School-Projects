#include <iostream>
#include <string>
#include "Planet.h"
#include "Spaceship.h"

using namespace std;

int main() {
    Planet planets[9] = {
        Planet("Mercury", 5.79107, 4879),
        Planet("Venus", 1.08208, 12104),
        Planet("Earth", 1.49608, 12742),
        Planet("Mars", 2.27908, 6779),
        Planet("Jupiter", 7.78308, 139822),
        Planet("Saturn", 1.4209, 116460),
        Planet("Uranus", 2.8709, 50724),
        Planet("Neptune", 4.509, 49244),
        Planet("Pluto", 5.9109, 2370)
    };

    string uname;
    double ufuel;
    cout << "Enter your spaceship's name: ";
    getline(cin, uname);
    cout << "Enter the initial fuel of your spaceship (in units): ";
    cin >> ufuel;
    Spaceship spaceship(uname, ufuel);

    int choice = -1;
    while (choice != 0) {
        cout << "Select the planet number you want to travel to (1-9) or enter 0 to exit:" << endl;
        for (int i = 0; i < 9; i++) {
            cout << i + 1 << ". " << planets[i].getName() << " - " << "Distance from Sun: " << planets[i].getDistanceFromSun() << " km, Diameter: " << planets[i].getDiameter() << " km" << endl;
        }
        cout << "0. Exit\n" << endl;

        cin >> choice;

        if (choice >= 1 && choice <= 9) {
            Planet& destination = planets[choice - 1];
            double fuelPerDistance = 0.1;
            spaceship.travel(destination, fuelPerDistance);
            spaceship.displayInfo();
        }
        else if (choice == 0) {
            cout << "Exiting!" << endl;
            cout << "Selma Irem Ozdemir 21070001028" << endl;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}