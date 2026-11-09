#include "Passenger.h"

#include <stdexcept>

Passenger::Passenger(const std::string& passengerName)
    : name(passengerName) {
    if (name.empty()) {
        throw std::invalid_argument("Passenger name cannot be empty.");
    }
}

const std::string& Passenger::getName() const {
    return name;
}
