
#include "RouteOptimizer.h"

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

RouteOptimizer::RouteOptimizer()
{
}

void RouteOptimizer::addFlight(const Flight& flight)
{
    availableFlights.push_back(flight);
}

Flight* RouteOptimizer::findDirectFlight(
    const std::string& source,
    const std::string& destination)
{
    for (Flight& flight : availableFlights)
    {
        if (flight.getSourceCode() == source &&
            flight.getDestinationCode() == destination)
        {
            return &flight;
        }
    }

    return nullptr;
}

bool RouteOptimizer::hasDirectFlight(
    const std::string& source,
    const std::string& destination)
{
    return findDirectFlight(source, destination) != nullptr;
}

bool RouteOptimizer::findRoute(
    const std::string& source,
    const std::string& destination,
    Itinerary& itinerary)
{
    if (source == destination)
    {
        return true;
    }

    std::queue<std::string> pending;
    std::unordered_set<std::string> visited;

    // For each reached airport, store the previous airport
    // and the flight used to reach it.
    std::unordered_map<std::string, std::string> previousAirport;
    std::unordered_map<std::string, int> previousFlight;

    pending.push(source);
    visited.insert(source);

    bool found = false;

    while (!pending.empty())
    {
        std::string current = pending.front();
        pending.pop();

        for (int i = 0;
             i < static_cast<int>(availableFlights.size());
             ++i)
        {
            const Flight& flight = availableFlights[i];

            if (flight.getSourceCode() != current)
            {
                continue;
            }

            std::string next = flight.getDestinationCode();

            if (visited.count(next))
            {
                continue;
            }

            visited.insert(next);
            previousAirport[next] = current;
            previousFlight[next] = i;

            if (next == destination)
            {
                found = true;
                break;
            }

            pending.push(next);
        }

        if (found)
        {
            break;
        }
    }

    if (!found)
    {
        return false;
    }

    // Reconstruct the route from destination to source.
    std::vector<int> route;

    std::string current = destination;

    while (current != source)
    {
        int flightIndex = previousFlight[current];
        route.push_back(flightIndex);
        current = previousAirport[current];
    }

    // Reverse so flights appear in travel order.
    std::reverse(route.begin(), route.end());

    // Add the selected flights to the itinerary.
    for (int index : route)
    {
        itinerary.addFlight(availableFlights[index]);
    }

    return true;
}
