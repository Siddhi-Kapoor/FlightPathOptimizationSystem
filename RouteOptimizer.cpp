#include <iostream>
#include "RouteOptimizer.h"
using namespace std;

void RouteOptimizer::addFlight(Flight flight) {
    availableFlights.push_back(flight);
}

void RouteOptimizer::findCheapestDirectFlight(
    string source, string destination) {

    int bestIndex = -1;

    for (int i = 0; i < availableFlights.size(); i++) {
        if (availableFlights[i].getSourceCode() == source &&
            availableFlights[i].getDestinationCode() == destination) {

            if (bestIndex == -1 ||
                availableFlights[i].getTicketPrice() <
                availableFlights[bestIndex].getTicketPrice()) {
                bestIndex = i;
            }
        }
    }

    if (bestIndex == -1) {
        cout << "No direct flight found." << endl;
    } else {
        cout << "\nCheapest direct flight:" << en