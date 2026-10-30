#include "RouteStrategy.h"

#include "Flight.h"

#include <stdexcept>

double CheapestStrategy::edgeWeight(const Flight& flight) const {
    return flight.getTicketPrice();
}

std::string CheapestStrategy::getName() const {
    return "Cheapest";
}

double FastestStrategy::edgeWeight(const Flight& flight) const {
    return flight.getDuration();
}

std::string FastestStrategy::getName() const {
    return "Fastest";
}

double FewestStopsStrategy::edgeWeight(const Flight&) const {
    return 1.0;
}

std::string FewestStopsStrategy::getName() const {
    return "Fewest Stops";
}

double BalancedStrategy::edgeWeight(const Flight& flight) const {
    return flight.getTicketPrice() / 1000.0 + flight.getDuration() + 2.0;
}

std::string BalancedStrategy::getName() const {
    return "Balanced";
}

std::unique_ptr<RouteStrategy> createRouteStrategy(int choice) {
    switch (choice) {
    case 1:
        return std::unique_ptr<RouteStrategy>(new CheapestStrategy());
    case 2:
        return std::unique_ptr<RouteStrategy>(new FastestStrategy());
    case 3:
        return std::unique_ptr<RouteStrategy>(new FewestStopsStrategy());
    case 4:
        return std::unique_ptr<RouteStrategy>(new BalancedStrategy());
    default:
        throw std::invalid_argument("Please choose a preference from 1 to 4.");
    }
}
