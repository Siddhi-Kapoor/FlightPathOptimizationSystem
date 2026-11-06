
#ifndef ROUTEOPTIMIZER_H
#define ROUTEOPTIMIZER_H

#include <vector>
#include <string>
#include "Flight.h"
#include "Itinerary.h"
#include "RouteStrategy.h"

class RouteOptimizer
{
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
    ) const;

    bool cancelFlight(const std::string& flightNumber);

    // Strategy-based route optimization
    bool findRoute(
        const std::string& source,
        const std::string& destination,
        const RouteStrategy& strategy,
        Itinerary& itinerary
    ) const;

    // Default route search: fewest stops
    bool findRoute(
        const std::string& source,
        const std::string& destination,
        Itinerary& itinerary
    ) const;

    const std::vector<Flight>& getFlights() const;
};

#endif