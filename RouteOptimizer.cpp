#include "RouteOptimizer.h"

RouteOptimizer::RouteOptimizer()
{
}

void RouteOptimizer::addFlight(const Flight& flight)
{
    availableFlights.push_back(flight);
}

Flight* RouteOptimizer::findDirectFlight(const std::string& source,
                                         const std::string& destination)
{
    for (Flight& flight : availableFlights)
    {
        if (flight.getSource() == source &&
            flight.getDestination() == destination)
        {
            return &flight;
        }
    }

    return nullptr;
}

bool RouteOptimizer::hasDirectFlight(const std::string& source,
                                     const std::string& destination)
{
    return findDirectFlight(source, destination) != nullptr;
}