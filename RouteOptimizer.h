
#ifndef ROUTEOPTIMIZER_H
#define ROUTEOPTIMIZER_H

#include <vector>
#include <string>
#include "Flight.h"
#include "Itinerary.h"
#include "RouteStrategy.h"

class FlightNetwork {
private:
    std::vector<Flight> availableFlights;

public:
    FlightNetwork();

    void addFlight(const Flight& flight);

    Flight* findDirectFlight(
        const std::string& source,
        const std::string& destination
    );

    bool hasDirectFlight(
        const std::string& source,
        const std::string& destination
    );

    bool cancelFlight(const std::string& flightNumber);

    bool findRoute(
        const std::string& source,
        const std::string& destination,
        const RouteStrategy& strategy,
        Itinerary& itinerary
    ) const;

    const std::vector<Flight>& getFlights() const;
};

typedef FlightNetwork RouteOptimizer;

#endif
