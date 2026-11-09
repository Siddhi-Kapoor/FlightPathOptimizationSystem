#ifndef AIRPORT_MANAGER_H
#define AIRPORT_MANAGER_H

#include "Airport.h"
#include <vector>
#include <string>

class AirportManager {
private:
    std::vector<Airport> airports;

public:
    bool addAirport(const Airport& airport);
    const Airport* findAirport(const std::string& code) const;
    void displayAllAirports() const;
};

#endif
