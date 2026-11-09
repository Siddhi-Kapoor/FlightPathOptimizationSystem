
#ifndef ROUTEOPTIMIZER_H
#define ROUTEOPTIMIZER_H

#include <memory>
#include <string>
#include <vector>
#include "Flight.h"
#include "Itinerary.h"
#include "RouteStrategy.h"

enum class RoutePreference {
    Cheapest,
    Fastest,
    FewestStops,
    Balanced
};

class RouteOptimizationStrategy {
public:
    virtual ~RouteOptimizationStrategy() = default;
    virtual double edgeWeight(const Flight& flight,
                              double maximumPrice,
                              double maximumDuration) const = 0;
    virtual std::string name() const = 0;
};

class CheapestRouteStrategy final : public RouteOptimizationStrategy {
public:
    double edgeWeight(const Flight& flight, double, double) const override;
    std::string name() const override;
};

class FastestRouteStrategy final : public RouteOptimizationStrategy {
public:
    double edgeWeight(const Flight& flight, double, double) const override;
    std::string name() const override;
};

class FewestStopsStrategy final : public RouteOptimizationStrategy {
public:
    double edgeWeight(const Flight& flight, double, double) const override;
    std::string name() const override;
};

class BalancedRouteStrategy final : public RouteOptimizationStrategy {
public:
    double edgeWeight(const Flight& flight,
                      double maximumPrice,
                      double maximumDuration) const override;
    std::string name() const override;
};

std::unique_ptr<RouteOptimizationStrategy> createRouteStrategy(
    RoutePreference preference);

class RouteOptimizer {
private:
    std::vector<Flight> availableFlights;
    std::vector<std::string> cancelledFlightNumbers;

public:
    void addFlight(const Flight& flight);
    bool cancelFlight(const std::string& flightNumber);
    bool isCancelled(const std::string& flightNumber) const;
    const std::vector<Flight>& getFlights() const;
    std::vector<std::string> getAirportCodes() const;
    const Flight* findDirectFlight(
        const std::string& source,
        const std::string& destination) const;
    bool hasDirectFlight(
        const std::string& source,
        const std::string& destination) const;
    bool findRoute(
        const std::string& source,
        const std::string& destination,
        const RouteOptimizationStrategy& strategy,
        Itinerary& itinerary) const;
};

#endif