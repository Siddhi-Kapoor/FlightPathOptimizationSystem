
#ifndef ROUTEOPTIMIZER_H
#define ROUTEOPTIMIZER_H

#include <vector>
#include <string>
#include "Flight.h"
#include "Itinerary.h"

class RouteOptimizer {
private:
    std::vector<Flight> availableFlights;

public:
    RouteOptimizer();

    void addFlight(const Flight& flight);

    Flight* findDirectFlight(
        const std::string& source,
        const std::string& destination
    );

    bool hasDirectFlight(
        const std::string& source,
        const std::string& destination
    );

    // Finds a route using direct or connecting flights.
    // Returns false if no route exists.
    bool findRoute(
        const std::string& source,
        const std::string& destination,
        Itinerary& itinerary
    );
};

#endif
