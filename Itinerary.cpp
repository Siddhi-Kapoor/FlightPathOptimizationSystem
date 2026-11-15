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
    const std::string border = "  +----------------------------------------------------------+\n";
    output << '\n' << border
           << "  |                    ITINERARY SUMMARY                   |\n"
           << border;

    if (flights.empty()) {
        output << "  |  You are already at your destination.                   |\n"
               << border;
        return;
    }

    std::string route = "  Route: ";
    for (std::size_t index = 0; index < flights.size(); ++index) {
        if (index != 0) {
            route += " -> ";
        }
        route += flights[index].getSourceCode();
    }
    route += " -> " + flights.back().getDestinationCode();
    output << "  | " << std::left << std::setw(58) << route << "|\n"
           << border
           << "  | FLIGHT     FROM         TO           FARE          TIME   |\n"
           << "  |----------------------------------------------------------|\n";

    for (const Flight& flight : flights) {
        const auto flightMinutes = static_cast<long long>(
            std::llround(flight.getDuration() * 60.0));
        std::ostringstream row;
        row << "  | " << std::left << std::setw(11) << flight.getFlightNumber()
            << std::setw(13) << flight.getSourceCode()
            << std::setw(13) << flight.getDestinationCode()
            << "Rs." << std::right << std::setw(8) << std::fixed
            << std::setprecision(2) << flight.getTicketPrice()
            << "  " << std::setw(2) << flightMinutes / 60 << "h "
            << std::setw(2) << flightMinutes % 60 << "m |\n";
        output << row.str();
    }

    const auto totalMinutes = static_cast<long long>(
        std::llround(getTotalDuration() * 60.0));
    output << border
           << "  | TOTAL FARE: Rs. " << std::fixed << std::setprecision(2)
           << std::left << std::setw(12) << getTotalPrice()
           << " DURATION: " << std::setw(7) << (std::to_string(totalMinutes / 60) + "h " +
               std::to_string(totalMinutes % 60) + "m")
           << "|\n"
           << "  | NUMBER OF STOPS: " << std::left << std::setw(39)
           << getNumberOfStops() << "|\n"
           << border;
}
