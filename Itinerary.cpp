
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Itinerary.h"

void Itinerary::addFlight(const Flight& flight) {
    flights.push_back(flight);
}

void Itinerary::clear() {
    flights.clear();
}

double Itinerary::getTotalPrice() const {
    double total = 0.0;
    for (const Flight& flight : flights) {
        total += flight.getTicketPrice();
    }
    return total;
}

double Itinerary::getTotalDuration() const {
    double total = 0.0;
    for (const Flight& flight : flights) {
        total += flight.getDuration();
    }
    return total;
}

std::size_t Itinerary::getNumberOfStops() const {
    return flights.empty() ? 0 : flights.size() - 1;
}

const std::vector<Flight>& Itinerary::getFlights() const {
    return flights;
}

void Itinerary::display(std::ostream& output) const {
    output << "\n  Recommended route\n";
    if (flights.empty()) {
        output << "  You are already at your destination.\n";
        return;
    }

    output << "  ";
    for (std::size_t index = 0; index < flights.size(); ++index) {
        if (index != 0) {
            output << " -> ";
        }
        output << flights[index].getSourceCode();
    }
    output << " -> " << flights.back().getDestinationCode() << "\n\n";

    output << "  Flight details\n";
    for (const Flight& flight : flights) {
        const auto flightMinutes = static_cast<long long>(
            std::llround(flight.getDuration() * 60.0));
        output << "    " << flight.getFlightNumber() << "  "
               << flight.getSourceCode() << " -> "
               << flight.getDestinationCode() << "  Rs. "
               << std::fixed << std::setprecision(2) << flight.getTicketPrice()
               << "  " << flightMinutes / 60 << "h " << flightMinutes % 60
               << "m\n";
    }

    const auto totalMinutes = static_cast<long long>(
        std::llround(getTotalDuration() * 60.0));
    output << "\n  Total cost     : Rs. " << std::fixed << std::setprecision(2)
           << getTotalPrice()
           << "\n  Total duration : " << totalMinutes / 60 << "h "
           << totalMinutes % 60 << "m"
           << "\n  Number of stops: " << getNumberOfStops() << '\n';
}
