#ifndef FLIGHT_H
#define FLIGHT_H

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

    void display();

    double getTicketPrice();
    double getDuration();
    std::string getSourceCode();
    std::string getDestinationCode();
    std::string getFlightNumber();
};

#endif
