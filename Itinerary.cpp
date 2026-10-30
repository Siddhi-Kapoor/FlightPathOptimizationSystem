#include <iostream>
<<<<<<< HEAD
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
    if (flights.empty()) {
        std::cout << "No flights in the itinerary.\n";
        return;
    }

    std::cout << "\nRoute: " << flights.front().getSourceCode();
    for (const Flight& flight : flights) {
        std::cout << " -> " << flight.getDestinationCode();
    }

    const double duration = getTotalDuration();
    const int totalMinutes = static_cast<int>(duration * 60.0 + 0.5);
    std::cout << "\nCost: Rs. " << std::fixed << std::setprecision(0)
              << getTotalPrice()
              << " | Time: " << totalMinutes / 60 << "h "
              << totalMinutes % 60 << "m"
              << " | Stops: " << getStops() << '\n'
              << "Flights:";
    for (const Flight& flight : flights) {
        std::cout << ' ' << flight.getFlightNumber();
    }
    std::cout << '\n';
=======
#include "Itinerary.h"

void Itinerary::addFlight(Flight flight) {
flights.push_back(flight);
}

double Itinerary::getTotalPrice() {
double total = 0.0;

for (const Flight& flight : flights) {
    total += flight.getTicketPrice();
}

return total;

}

double Itinerary::getTotalDuration() {
double total = 0.0;

for (const Flight& flight : flights) {
    total += flight.getDuration();
}

return total;

}

void Itinerary::display() {
std::cout << "\nFlight Itinerary:\n";

if (flights.empty()) {
    std::cout << "No flights in the itinerary.\n";
} else {
    for (const Flight& flight : flights) {
        std::cout << flight.getSourceCode()
                  << " -> "
                  << flight.getDestinationCode()
                  << '\n';
    }
}

std::cout << "\nTotal Duration: "
          << getTotalDuration() << " hours\n";

std::cout << "Total Fare: Rs. "
          << getTotalPrice() << '\n';

>>>>>>> c9f580d44513af20c55948b9716a7c0b7764bc7e
}
