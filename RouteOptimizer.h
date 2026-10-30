
#ifndef ROUTEOPTIMIZER_H
#define ROUTEOPTIMIZER_H

#include <vector>
#include <string>
#include "Flight.h"
#include "Itinerary.h"
<<<<<<< HEAD
#include "RouteStrategy.h"

class FlightNetwork {
=======

class RouteOptimizer {
>>>>>>> c9f580d44513af20c55948b9716a7c0b7764bc7e
private:
    std::vector<Flight> availableFlights;

public:
<<<<<<< HEAD
    FlightNetwork();
=======
    RouteOptimizer();
>>>>>>> c9f580d44513af20c55948b9716a7c0b7764bc7e

    void addFlight(const Flight& flight);

    Flight* findDirectFlight(
        const std::string& source,
        const std::string& destination
    );

    bool hasDirectFlight(
        const std::string& source,
        const std::string& destination
    );

<<<<<<< HEAD
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

=======
    // Finds a route using direct or connecting flights.
    // Returns false if no route exists.
    bool findRoute(
        const std::string& source,
        const std::string& destination,
        Itinerary& itinerary
    );
};

>>>>>>> c9f580d44513af20c55948b9716a7c0b7764bc7e
#endif
