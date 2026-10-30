#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

class Passenger {
private:
    std::string name;

public:
    explicit Passenger(const std::string& passengerName);
    const std::string& getName() const;
};

#endif
