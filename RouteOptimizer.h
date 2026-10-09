
#ifndef ROUTEOPTIMIZER_H
#define ROUTEOPTIMIZER_H

#include <vector>
#include "Flight.h"
#include "Itinerary.h"
using namespace std;

class RouteOptimizer {
private:
    vector<Flight> availableFlights;

public:
    void addFlight(Flight flight);
    void findCheapestDirectFlight(string source,
                                  string destination);
};
