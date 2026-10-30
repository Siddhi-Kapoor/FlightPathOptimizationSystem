#include "flight.h"
#include <iostream>
#include <stdexcept>

 using namespace std;
//constructor
Flight::Flight(string number, string source, string destination,
               double price, double time)
    : flightNumber(number),
      sourceCode(source),
      destinationCode(destination),
      ticketPrice(price),
      duration(time) {

    if (ticketPrice < 0 || duration < 0) {
        throw invalid_argument(
            "Ticket price and duration cannot be negative."
        );
    }
}
// Display all flight details
void Flight::display() {
    cout << "Flight Number: " << flightNumber << endl;
    cout << "Source: " << sourceCode << endl;
    cout << "Destination: " << destinationCode << endl;
    cout << "Ticket Price: " << ticketPrice << endl;
    cout << "Duration: " << duration << " hours" << endl;
}

// Getters
double Flight::getTicketPrice() {
    return ticketPrice;
}

double Flight::getDuration() {
    return duration;
}

string Flight::getSourceCode() {
    return sourceCode;
}

string Flight::getDestinationCode() {
    return destinationCode;
}

string Flight::getFlightNumber() {
    return flightNumber;
}
