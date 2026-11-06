
#include <iostream>
#include <iomanip>
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

std::size_t Itinerary::getStops() const {
    return flights.empty() ? 0 : flights.size() - 1;
}

const std::vector<Flight>& Itinerary::getFlights() const {
    return flights;
}

void Itinerary::display() const {
    std::cout << "\nFlight Itinerary:\n";

    if (flights.empty()) {
        std::cout << "No flights in the itinerary.\n";
    } else {
        std::cout << "Route: " << flights.front().getSourceCode();

        for (const Flight& flight : flights) {
            std::cout << " -> " << flight.getDestinationCode();
        }

        std::cout << "\nFlights:";

        for (const Flight& flight : flights) {
            std::cout << ' ' << flight.getFlightNumber();
        }

        std::cout << '\n';
    }

    const double duration = getTotalDuration();
    const int totalMinutes =
        static_cast<int>(duration * 60.0 + 0.5);

    std::cout << "Total Fare: Rs. "
              << std::fixed << std::setprecision(2)
              << getTotalPrice() << '\n';

    std::cout << "Total Duration: "
              << totalMinutes / 60 << "h "
              << totalMinutes % 60 << "m\n";

    std::cout << "Total Stops: " << getStops() << '\n';
}

