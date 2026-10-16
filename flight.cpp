#include "flight.h"
#include <stdexcept>
#include <cctype>

Flight::Flight(string number, string src, string dest,
               double dur, double price)
    : flightNumber(number),
      source(src),
      destination(dest),
      duration(dur),
      fare(price) {

    if (!isValid()) {
        throw invalid_argument("Invalid flight details");
    }
}

string Flight::getFlightNumber() const {
    return flightNumber;
}

string Flight::getSource() const {
    return source;
}

string Flight::getDestination() const {
    return destination;
}

double Flight::getDuration() const {
    return duration;
}

double Flight::getFare() const {
    return fare;
}

bool Flight::isValid() const {
    return !flightNumber.empty()
        && !source.empty()
        && !destination.empty()
        && source != destination
        && duration >= 0
        && fare >= 0;
}

