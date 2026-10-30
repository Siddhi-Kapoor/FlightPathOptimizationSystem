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
    bool cancelled;

public:
    Flight(std::string number,
           std::string source,
           std::string destination,
           double price,
           double time);

    void display() const;

    double getTicketPrice() const;
    double getDuration() const;
    std::string getSourceCode() const;
    std::string getDestinationCode() const;
    std::string getFlightNumber() const;
    bool isCancelled() const;
    void cancel();
};

#endif
