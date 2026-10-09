#include <iostream>
#include "Flight.h"
using namespace std;

Flight::Flight(string number, string source, string destination,
               double price, double time) {
    flightNumber = number;
    sourceCode = source;
    destinationCode = destination;
    ticketPrice = price;
    duration = time;
}

void Flight::display() {
    cout << "Flight Number: " << flightNumber << endl;
    cout << "Source: " << sourceCode << endl;
    cout << "Destination: " << destinationCode << endl;
    cout << "Ticket Price: Rs. " << ticketPrice << endl;
    cout << "Duration: " << duration << " hours" << endl;
}

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
