
#ifndef ITINERARY_H
#define ITINERARY_H

#include <cstddef>
#include <vector>
#include "Flight.h"

class Itinerary {
private:
    // Stores flights in their travel sequence
    std::vector<Flight> flights;

public:
    // Adds a flight to the itinerary
    void addFlight(const Flight& flight);

    // Removes all flights from the itinerary
    void clear();

    // Returns the total ticket price
    double getTotalPrice() const;

    // Returns the total flight duration
    double getTotalDuration() const;

    // Returns the number of intermediate stops
    std::size_t getStops() const;

    // Provides read-only access to stored flights
    const std::vector<Flight>& getFlights() const;

    // Displays the complete itinerary and its details
    void display() const;
};

#endif
