
#ifndef ITINERARY_H
#define ITINERARY_H

#include <vector>
#include "Flight.h"

class Itinerary {
private:
    std::vector<Flight> flights;

public:
    void addFlight(Flight flight);
    double getTotalPrice();
    double getTotalDuration();
    void display();
};

#endif

