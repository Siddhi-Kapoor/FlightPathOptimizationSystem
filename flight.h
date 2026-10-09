#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
using namespace std;

class Flight {
private:
    string flightNumber;
    string sourceCode;
    string destinationCode;
    double ticketPrice;
    double duration;

public:
    Flight(string number, string source, string destination,
           double price, double time);

    void display();
    double getTicketPrice();
    double getDuration();
    string getSourceCode();
    string getDestinationCode();
};

#endif
