
#include "flight.h"
#include <iostream>
#include <stdexcept>

Flight::Flight(std::string number,
               std::string source,
               std::string destination,
               double price,
               double time)
    : flightNumber(number),
      sourceCode(source),
      destinationCode(destination),
      ticketPrice(price),
      duration(time)
{
    if (price < 0 || time < 0) {
        throw std::invalid_argument(
            "Ticket price and duration cannot be negative."
        );
    }
}

void Flight::display()
{
    std::cout << "Flight Number: " << flightNumber << '\n';
    std::cout << "Source: " << sourceCode << '\n';
    std::cout << "Destination: " << destinationCode << '\n';
    std::cout << "Ticket Price: " << ticketPrice << '\n';
    std::cout << "Duration: " << duration << " hours\n";
}

double Flight::getTicketPrice()
{
    return ticketPrice;
}

double Flight::getDuration()
{
    return duration;
}

std::string Flight::getSourceCode()
{
    return sourceCode;
}

std::string Flight::getDestinationCode()
{
    return destinationCode;
}

std::string Flight::getFlightNumber()
{
    return flightNumber;
}
