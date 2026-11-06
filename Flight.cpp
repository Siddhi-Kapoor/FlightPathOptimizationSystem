#include "Flight.h"

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cctype>

bool isBlank(const std::string& value) {
    return value.empty() ||
        std::all_of(value.begin(), value.end(),
            [](unsigned char ch) {
                return std::isspace(ch);
            });
}

std::string toUpper(std::string value) {
    std::transform(value.begin(), value.end(), value.begin(),
        [](unsigned char ch) {
            return std::toupper(ch);
        });

    return value;
}

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
    if (isBlank(flightNumber) ||
        isBlank(sourceCode) ||
        isBlank(destinationCode)) {
        throw std::invalid_argument(
            "Flight number and airport codes cannot be empty.");
    }

    if (toUpper(sourceCode) == toUpper(destinationCode)) {
        throw std::invalid_argument(
            "Source and destination cannot be the same.");
    }

    if (!std::isfinite(ticketPrice) ||
        !std::isfinite(duration) ||
        ticketPrice < 0 ||
        duration < 0) {
        throw std::invalid_argument(
            "Ticket price and duration must be finite and non-negative.");
    }
}

void Flight::display() const {
    std::cout << "\n========== FLIGHT DETAILS ==========\n"
              << "Flight Number : " << flightNumber << '\n'
              << "Source        : " << sourceCode << '\n'
              << "Destination   : " << destinationCode << '\n'
              << "Ticket Price  : Rs. " << ticketPrice << '\n'
              << "Duration      : " << duration << " hours\n"
              << "Status        : "
              << (cancelled ? "Cancelled" : "Available")
              << "\n====================================\n";
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
