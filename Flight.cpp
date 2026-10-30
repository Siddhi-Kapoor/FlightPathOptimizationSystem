#include "Flight.h"

#include <cmath>
#include <iostream>
#include <stdexcept>

Flight::Flight(std::string number,
               std::string source,
               std::string destination,
               double price,
               double time)
    : flightNumber(number),
      sourceCode(source),
      destinationCode(destination),
      ticketPrice(price),
      duration(time),
      cancelled(false)
{
    if (!std::isfinite(ticketPrice) || !std::isfinite(duration) ||
        ticketPrice < 0 || duration < 0) {
        throw std::invalid_argument(
            "Ticket price and duration must be finite and non-negative.");
    }
}

void Flight::display() const {
    std::cout << "Flight Number: " << flightNumber << '\n'
              << "Source: " << sourceCode << '\n'
              << "Destination: " << destinationCode << '\n'
              << "Ticket Price: Rs. " << ticketPrice << '\n'
              << "Duration: " << duration << " hours\n"
              << "Status: " << (cancelled ? "Cancelled" : "Available")
              << '\n';
}

double Flight::getTicketPrice() const {
    return ticketPrice;
}

double Flight::getDuration() const {
    return duration;
}

std::string Flight::getSourceCode() const {
    return sourceCode;
}

std::string Flight::getDestinationCode() const {
    return destinationCode;
}

std::string Flight::getFlightNumber() const {
    return flightNumber;
}

bool Flight::isCancelled() const {
    return cancelled;
}

void Flight::cancel() {
    cancelled = true;
}
