
#ifndef ITINERARY_H
#define ITINERARY_H

#include <cstddef>
#include <vector>
#include "Flight.h"

class Itinerary {
private:
    std::vector<Flight> flights;

public:
    void addFlight(const Flight& flight);
    void clear();
    double getTotalPrice() const;
    double getTotalDuration() const;
    std::size_t getStops() const;
    const std::vector<Flight>& getFlights() const;
    void display() const;
};

#endif
