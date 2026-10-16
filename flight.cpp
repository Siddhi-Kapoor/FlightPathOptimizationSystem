#include "flight.h"
#include <stdexcept>
#include <stdexcept>

 using namespace std;
//constructor
Flight::Flight(string number, string source, string destination,
               double time, double price)
    : flightNumber(number),
      sourceCode(source),
      destinationCode(destination),
      duration(time),
      ticketPrice(price) {

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
