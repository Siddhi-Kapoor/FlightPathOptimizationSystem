#ifndef ITINERARY_H
#define ITINERARY_H

#include <vector>
#include "Flight.h"
using namespace std;

class Itinerary {
private:
    vector<Flight> flights;

public:
    void addFlight(Flight flight);
    double getTotalPrice();
    double getTotalDuration();
    void display();
};

#endif
