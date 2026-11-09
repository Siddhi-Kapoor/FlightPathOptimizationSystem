
#ifndef ITINERARY_H
#define ITINERARY_H

#include <iostream>
#include <vector>
#include "flight.h"

class Itinerary {
private:
    std::vector<Flight> flights;

public:
    void addFlight(const Flight& flight);
    void clear();
    double getTotalPrice() const;
    double getTotalDuration() const;
    std::size_t getNumberOfStops() const;
    const std::vector<Flight>& getFlights() const;
    void display(std::ostream& output = std::cout) const;
};

#endif
