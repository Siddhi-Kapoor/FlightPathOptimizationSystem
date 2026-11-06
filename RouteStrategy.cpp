#include "RouteOptimizer.h"

#include <algorithm>
#include <cmath>
#include <functional>
#include <queue>
#include <stdexcept>
#include <unordered_map>

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
        if (!flight.isCancelled() &&
            flight.getSourceCode() == source &&
            flight.getDestinationCode() == destination)
        {
            return &flight;
        }
    }

    return nullptr;
}

bool RouteOptimizer::hasDirectFlight(
    const std::string& source,
    const std::string& destination) const
{
    for (const Flight& flight : availableFlights)
    {
        if (!flight.isCancelled() &&
            flight.getSourceCode() == source &&
            flight.getDestinationCode() == destination)
        {
            return true;
        }
    }

    return false;
}

bool RouteOptimizer::cancelFlight(
    const std::string& flightNumber)
{
    for (Flight& flight : availableFlights)
    {
        if (flight.getFlightNumber() == flightNumber &&
            !flight.isCancelled())
        {
            flight.cancel();
            return true;
        }
    }

    return false;
}

bool RouteOptimizer::findRoute(
    const std::string& source,
    const std::string& destination,
    const RouteStrategy& strategy,
    Itinerary& itinerary) const
{
    itinerary.clear();

    if (source == destination)
    {
        return true;
    }

    typedef std::pair<double, std::string> QueueEntry;

    std::priority_queue<
        QueueEntry,
        std::vector<QueueEntry>,
        std::greater<QueueEntry>
    > pending;

    std::unordered_map<std::string, double> distance;

    std::unordered_map<std::string, std::string>
        previousAirport;

    std::unordered_map<std::string, std::size_t>
        previousFlight;

    distance[source] = 0.0;
    pending.push(QueueEntry(0.0, source));

    while (!pending.empty())
    {
        QueueEntry entry = pending.top();
        pending.pop();

        double currentDistance = entry.first;
        std::string current = entry.second;

        if (currentDistance > distance[current])
        {
            continue;
        }

        if (current == destination)
        {
            break;
        }

        for (std::size_t i = 0;
             i < availableFlights.size(); ++i)
        {
            const Flight& flight = availableFlights[i];

            if (flight.isCancelled() ||
                flight.getSourceCode() != current)
            {
                continue;
            }

            std::string next = flight.getDestinationCode();

            double weight = strategy.edgeWeight(flight);

            if (!std::isfinite(weight) || weight < 0.0)
            {
                throw std::invalid_argument(
                    "Route weights must be finite and non-negative."
                );
            }

            double candidate = currentDistance + weight;

            if (!std::isfinite(candidate))
            {
                throw std::overflow_error(
                    "Route weight total overflowed."
                );
            }

            auto known = distance.find(next);

            if (known != distance.end() &&
                candidate >= known->second)
            {
                continue;
            }

            distance[next] = candidate;
            previousAirport[next] = current;
            previousFlight[next] = i;

            pending.push(QueueEntry(candidate, next));
        }
    }

    if (distance.find(destination) == distance.end())
    {
        return false;
    }

    // Reconstruct the selected route.

    std::vector<std::size_t> route;

    std::string current = destination;

    while (current != source)
    {
        auto flight = previousFlight.find(current);
        auto airport = previousAirport.find(current);

        if (flight == previousFlight.end() ||
            airport == previousAirport.end())
        {
            return false;
        }

        route.push_back(flight->second);
        current = airport->second;
    }

    std::reverse(route.begin(), route.end());

    // Store flights in the itinerary.

    for (std::size_t index : route)
    {
        itinerary.addFlight(availableFlights[index]);
    }

    return true;
}

// Default search uses the fewest-stops strategy.

bool RouteOptimizer::findRoute(
    const std::string& source,
    const std::string& destination,
    Itinerary& itinerary) const
{
    FewestStopsStrategy strategy;

    return findRoute(
        source,
        destination,
        strategy,
        itinerary
    );
}

const std::vector<Flight>&
RouteOptimizer::getFlights() const
{
    return availableFlights;
}