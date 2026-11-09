#include <iostream>
#include "AirportManager.h"
using namespace std;
bool AirportManager::addAirport(const Airport& airport) {
    for (const Airport& existing : airports) {
        if (existing.getCode() == airport.getCode()) {
            cout << "Airport already exists!" << endl;
            return false;
        }
    }
    airports.push_back(airport);
    cout << "Airport added successfully!" << endl;
    return true;
}
const Airport* AirportManager::findAirport(const string& code) const {
    for (const Airport& airport : airports) {
        if (airport.getCode() == code) {
            return &airport;
        }
    }

    return nullptr;
}
void AirportManager::displayAllAirports() const {
    if (airports.empty()) {
        cout << "No airports available." << endl;
        return;
    }

    for (const Airport& airport : airports) {
        airport.display();
        cout << endl;
    }
}
