
#include "RouteOptimizer.h"

<<<<<<< HEAD
#include <algorithm>
#include <cmath>
#include <functional>
#include <queue>
#include <stdexcept>
#include <unordered_map>

FlightNetwork::FlightNetwork() {
}

void FlightNetwork::addFlight(const Flight& flight) {
    availableFlights.push_back(flight);
}

Flight* FlightNetwork::findDirectFlight(
    const std::string& source,
    const std::string& destination) {
    for (Flight& flight : availableFlights)
    {
        if (!flight.isCancelled() &&
            flight.getSourceCode() == source &&
=======
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
>>>>>>> c9f580d44513af20c55948b9716a7c0b7764bc7e
            flight.getDestinationCode() == destination)
        {
            return &flight;
        }
    }

    return nullptr;
}

<<<<<<< HEAD
bool FlightNetwork::hasDirectFlight(
    const std::string& source,
    const std::string& destination) {
    return findDirectFlight(source, destination) != nullptr;
}

bool FlightNetwork::cancelFlight(const std::string& flightNumber) {
    for (Flight& flight : availableFlights) {
        if (flight.getFlightNumber() == flightNumber &&
            !flight.isCancelled()) {
            flight.cancel();
            return true;
        }
    }
    return false;
}

bool FlightNetwork::findRoute(
    const std::string& source,
    const std::string& destination,
    const RouteStrategy& strategy,
    Itinerary& itinerary) const {
    itinerary.clear();

    if (source == destination) {
        return true;
    }

    typedef std::pair<double, std::string> QueueEntry;
    std::priority_queue<QueueEntry,
                        std::vector<QueueEntry>,
                        std::greater<QueueEntry> > pending;
    std::unordered_map<std::string, double> distance;
    std::unordered_map<std::string, std::string> previousAirport;
    std::unordered_map<std::string, std::size_t> previousFlight;

    distance[source] = 0.0;
    pending.push(QueueEntry(0.0, source));

    while (!pending.empty()) {
        const QueueEntry entry = pending.top();
        pending.pop();

        const double currentDistance = entry.first;
        const std::string& current = entry.second;
        if (currentDistance > distance[current]) {
            continue;
        }
        if (current == destination) {
            break;
        }

        for (std::size_t i = 0; i < availableFlights.size(); ++i) {
            const Flight& flight = availableFlights[i];
            if (flight.isCancelled() || flight.getSourceCode() != current) {
                continue;
            }

            const std::string next = flight.getDestinationCode();
            const double edgeWeight = strategy.edgeWeight(flight);
            if (!std::isfinite(edgeWeight) || edgeWeight < 0.0) {
                throw std::invalid_argument(
                    "Route strategy weights must be finite and non-negative.");
            }
            const double candidate = currentDistance + edgeWeight;
            if (!std::isfinite(candidate)) {
                throw std::overflow_error("Route weight total overflowed.");
            }
            std::unordered_map<std::string, double>::const_iterator known =
                distance.find(next);
            if (known != distance.end() && candidate >= known->second) {
                continue;
            }

            distance[next] = candidate;
            previousAirport[next] = current;
            previousFlight[next] = i;
            pending.push(QueueEntry(candidate, next));
        }
    }

    if (distance.find(destination) == distance.end()) {
        return false;
    }

    std::vector<std::size_t> route;
    std::string current = destination;
    while (current != source) {
        std::unordered_map<std::string, std::size_t>::const_iterator flight =
            previousFlight.find(current);
        std::unordered_map<std::string, std::string>::const_iterator airport =
            previousAirport.find(current);
        if (flight == previousFlight.end() ||
            airport == previousAirport.end()) {
            return false;
        }
        route.push_back(flight->second);
        current = airport->second;
    }

    std::reverse(route.begin(), route.end());
    for (std::size_t index : route) {
=======
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
>>>>>>> c9f580d44513af20c55948b9716a7c0b7764bc7e
        itinerary.addFlight(availableFlights[index]);
    }

    return true;
}
<<<<<<< HEAD

const std::vector<Flight>& FlightNetwork::getFlights() const {
    return availableFlights;
}
=======
>>>>>>> c9f580d44513af20c55948b9716a7c0b7764bc7e
