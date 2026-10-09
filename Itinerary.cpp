#include <iostream>
#include "Itinerary.h"
using namespace std;

void Itinerary::addFlight(Flight flight) {
    flights.push_back(flight);
}

double Itinerary::getTotalPrice() {
    double total = 0;

    for (int i = 0; i < flights.size(); i++) {
        total += flights[i].getTicketPrice();
    }

    return total;
}

double Itinerary::getTotalDuration() {
    double total = 0;

    for (int i = 0; i < flights.size(); i++) {
        total += flights[i].getDuration();
    }

    return total;
}

void Itinerary::display() {
    cout << "\n--- Your Itinerary ---" << endl;

    for (int i = 0; i < flights.size(); i++) {
        flights[i].display();
        cout << endl;
    }

    cout << "Total Price: Rs. " << getTotalPrice() << endl;
    cout << "Total Duration: " << getTotalDuration()
         << " hours" << endl;
}
