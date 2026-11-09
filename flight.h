#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>

class Flight {
private:
    std::string flightNumber;
    std::string sourceCode;
    std::string destinationCode;
    double ticketPrice;
    double duration;

public:
    Flight(std::string number,
           std::string source,
           std::string destination,
           double price,
           double time);

    void display(std::ostream& output = std::cout) const;

    double getTicketPrice() const;
    double getDuration() const;
    const std::string& getSourceCode() const;
    const std::string& getDestinationCode() const;
    const std::string& getFlightNumber() const;
};

#endif
