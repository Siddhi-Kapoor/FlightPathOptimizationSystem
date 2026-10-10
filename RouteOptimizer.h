#ifndef ROUTEOPTIMIZER_H
#define ROUTEOPTIMIZER_H

#include <vector>
#include "Flight.h"
#include "Airport.h"

class RouteOptimizer {
private:
    std::vector<Flight> availableFlights;

public:
    RouteOptimizer();

    void addFlight(const Flight& flight);

    Flight* findDirectFlight(const Airport& source,
                             const Airport& destination);

    bool hasDirectFlight(const Airport& source,
                         const Airport& destination);
};

#endif