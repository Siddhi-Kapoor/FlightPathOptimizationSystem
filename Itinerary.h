#ifndef ITINERARY_H
#define ITINERARY_H

<<<<<<< HEAD
#include <cstddef>
=======
>>>>>>> c9f580d44513af20c55948b9716a7c0b7764bc7e
#include <vector>
#include "Flight.h"

class Itinerary {
private:
    std::vector<Flight> flights;

public:
<<<<<<< HEAD
    void addFlight(const Flight& flight);
    void clear();
    double getTotalPrice() const;
    double getTotalDuration() const;
    std::size_t getStops() const;
    const std::vector<Flight>& getFlights() const;
    void display() const;
};

#endif
=======
    void addFlight(Flight flight);
    double getTotalPrice();
    double getTotalDuration();
    void display();
};

#endif

>>>>>>> c9f580d44513af20c55948b9716a7c0b7764bc7e
