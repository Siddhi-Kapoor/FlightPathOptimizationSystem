#include "flight.h"
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <utility>

Flight::Flight(std::string number, std::string source, std::string destination,
               double price, double time)
    : flightNumber(std::move(number)),
      sourceCode(std::move(source)),
      destinationCode(std::move(destination)),
      ticketPrice(price),
      duration(time) {
    if (flightNumber.empty() || sourceCode.empty() || destinationCode.empty()) {
        throw std::invalid_argument(
            "Flight number, source, and destination are required.");
    }
    if (sourceCode == destinationCode) {
        throw std::invalid_argument("A flight must connect different airports.");
    }
    if (!std::isfinite(ticketPrice) || !std::isfinite(duration) ||
        ticketPrice < 0.0 || duration <= 0.0) {
        throw std::invalid_argument(
            "Ticket price must be non-negative and duration must be positive.");
    }
}

void Flight::display(std::ostream& output) const {
    output << "Flight: " << flightNumber
           << "\nRoute: " << sourceCode << " -> " << destinationCode
           << "\nTicket price: Rs. " << ticketPrice
           << "\nDuration: " << duration << " hours\n";
}

double Flight::getTicketPrice() const {
    return ticketPrice;
}

double Flight::getDuration() const {
    return duration;
}

const std::string& Flight::getSourceCode() const {
    return sourceCode;
}

const std::string& Flight::getDestinationCode() const {
    return destinationCode;
}

const std::string& Flight::getFlightNumber() const {
    return flightNumber;
}
