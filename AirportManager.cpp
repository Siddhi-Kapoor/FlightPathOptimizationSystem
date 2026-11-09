#include <iostream>
#include "AirportManager.h"
using namespace std;
bool AirportManager::addAirport(const Airport& airport) {
    for (int i = 0; i < airports.size(); i++) {
        if (airports[i].getCode() == airport.getCode()) {
            cout << "Airport already exists!" << endl;
            return false;
        }
    }
    airports.push_back(airport);
    cout << "Airport added successfully!" << endl;
    return true;
}
const Airport* AirportManager::findAirport(const string& code) const {
    for (int i = 0; i < airports.size(); i++) {
        if (airports[i].getCode() == code) {
            return &airports[i];
        }
    }

    return nullptr;
}
void AirportManager::displayAllAirports() const {
    if (airports.empty()) {
        cout << "No airports available." << endl;
        return;
    }

    for (int i = 0; i < airports.size(); i++) {
        airports[i].display();
        cout << endl;
    }
}
