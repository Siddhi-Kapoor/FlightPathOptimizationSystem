#include "RouteOptimizer.h"

#include <algorithm>
#include <cmath>
#include <functional>
#include <queue>
#include <stdexcept>
#include <unordered_map>

double CheapestRouteStrategy::edgeWeight(const Flight& flight, double, double) const {
    return flight.getTicketPrice();
}

std::string CheapestRouteStrategy::name() const {
    return "Cheapest";
}

double FastestRouteStrategy::edgeWeight(const Flight& flight, double, double) const {
    return flight.getDuration();
}

std::string FastestRouteStrategy::name() const {
    return "Fastest";
}

double FewestStopsStrategy::edgeWeight(const Flight&, double, double) const {
    return 1.0;
}

std::string FewestStopsStrategy::name() const {
    return "Fewest stops";
}

double BalancedRouteStrategy::edgeWeight(const Flight& flight,
                                          double maximumPrice,
                                          double maximumDuration) const {
    const double normalizedPrice = maximumPrice > 0.0
        ? flight.getTicketPrice() / maximumPrice : 0.0;
    const double normalizedDuration = maximumDuration > 0.0
        ? flight.getDuration() / maximumDuration : 0.0;
    return 1.0 + normalizedPrice + normalizedDuration;
}

std::string BalancedRouteStrategy::name() const {
    return "Balanced";
}

std::unique_ptr<RouteOptimizationStrategy> createRouteStrategy(
    RoutePreference preference) {
    switch (preference) {
        case RoutePreference::Cheapest:
            return std::make_unique<CheapestRouteStrategy>();
        case RoutePreference::Fastest:
            return std::make_unique<FastestRouteStrategy>();
        case RoutePreference::FewestStops:
            return std::make_unique<FewestStopsStrategy>();
        case RoutePreference::Balanced:
            return std::make_unique<BalancedRouteStrategy>();
    }
    throw std::invalid_argument("Unknown route preference.");
}

void RouteOptimizer::addFlight(const Flight& flight) {
    const auto duplicate = std::find_if(
        availableFlights.begin(), availableFlights.end(),
        [&flight](const Flight& existing) {
            return existing.getFlightNumber() == flight.getFlightNumber();
        });
    if (duplicate != availableFlights.end()) {
        throw std::invalid_argument("Duplicate flight number: " +
                                    flight.getFlightNumber());
    }
    availableFlights.push_back(flight);
}

bool RouteOptimizer::cancelFlight(const std::string& flightNumber) {
    const auto flight = std::find_if(
        availableFlights.begin(), availableFlights.end(),
        [&flightNumber](const Flight& candidate) {
            return candidate.getFlightNumber() == flightNumber;
        });
    if (flight == availableFlights.end() || isCancelled(flightNumber)) {
        return false;
    }
    cancelledFlightNumbers.push_back(flightNumber);
    return true;
}

bool RouteOptimizer::isCancelled(const std::string& flightNumber) const {
    return std::find(cancelledFlightNumbers.begin(),
                     cancelledFlightNumbers.end(), flightNumber)
        != cancelledFlightNumbers.end();
}

const std::vector<Flight>& RouteOptimizer::getFlights() const {
    return availableFlights;
}

std::vector<std::string> RouteOptimizer::getAirportCodes() const {
    std::vector<std::string> codes;
    for (const Flight& flight : availableFlights) {
        codes.push_back(flight.getSourceCode());
        codes.push_back(flight.getDestinationCode());
    }
    std::sort(codes.begin(), codes.end());
    codes.erase(std::unique(codes.begin(), codes.end()), codes.end());
    return codes;
}

const Flight* RouteOptimizer::findDirectFlight(
    const std::string& source, const std::string& destination) const {
    for (const Flight& flight : availableFlights) {
        if (!isCancelled(flight.getFlightNumber()) &&
            flight.getSourceCode() == source &&
            flight.getDestinationCode() == destination) {
            return &flight;
        }
    }
    return nullptr;
}

bool RouteOptimizer::hasDirectFlight(const std::string& source,
                                     const std::string& destination) const {
    return findDirectFlight(source, destination) != nullptr;
}

bool RouteOptimizer::findRoute(
    const std::string& source,
    const std::string& destination,
    const RouteOptimizationStrategy& strategy,
    Itinerary& itinerary) const {
    itinerary.clear();
    if (source == destination) {
        return true;
    }

    double maximumPrice = 0.0;
    double maximumDuration = 0.0;
    for (const Flight& flight : availableFlights) {
        if (!isCancelled(flight.getFlightNumber())) {
            maximumPrice = std::max(maximumPrice, flight.getTicketPrice());
            maximumDuration = std::max(maximumDuration, flight.getDuration());
        }
    }

    using QueueEntry = std::pair<double, std::string>;
    std::priority_queue<QueueEntry, std::vector<QueueEntry>,
                        std::greater<QueueEntry>> pending;
    std::unordered_map<std::string, double> distances;
    std::unordered_map<std::string, std::size_t> previousFlight;
    distances[source] = 0.0;
    pending.push({0.0, source});

    while (!pending.empty()) {
        const auto currentEntry = pending.top();
        pending.pop();
        const double currentDistance = currentEntry.first;
        const std::string& currentAirport = currentEntry.second;
        const auto best = distances.find(currentAirport);
        if (best == distances.end() || currentDistance > best->second) {
            continue;
        }
        if (currentAirport == destination) {
            break;
        }

        for (std::size_t index = 0; index < availableFlights.size(); ++index) {
            const Flight& flight = availableFlights[index];
            if (flight.getSourceCode() != currentAirport ||
                isCancelled(flight.getFlightNumber())) {
                continue;
            }
            const double weight =
                strategy.edgeWeight(flight, maximumPrice, maximumDuration);
            if (!std::isfinite(weight) || weight < 0.0) {
                throw std::logic_error(
                    "Route optimization strategies must return finite, "
                    "non-negative edge weights.");
            }
            const double candidate = currentDistance + weight;
            const std::string& nextAirport = flight.getDestinationCode();
            const auto existing = distances.find(nextAirport);
            if (existing == distances.end() || candidate < existing->second) {
                distances[nextAirport] = candidate;
                previousFlight[nextAirport] = index;
                pending.push({candidate, nextAirport});
            }
        }
    }

    if (distances.find(destination) == distances.end()) {
        return false;
    }

    std::vector<std::size_t> route;
    std::string currentAirport = destination;
    while (currentAirport != source) {
        const auto previous = previousFlight.find(currentAirport);
        if (previous == previousFlight.end()) {
            itinerary.clear();
            return false;
        }
        const Flight& flight = availableFlights[previous->second];
        route.push_back(previous->second);
        currentAirport = flight.getSourceCode();
    }
    std::reverse(route.begin(), route.end());
    for (const std::size_t index : route) {
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
