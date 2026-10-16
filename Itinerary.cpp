#include <iostream>
#include "Itinerary.h"

void Itinerary::addFlight(Flight flight) {
flights.push_back(flight);
}

double Itinerary::getTotalPrice() {
double total = 0.0;

for (const Flight& flight : flights) {
    total += flight.getTicketPrice();
}

return total;

}

double Itinerary::getTotalDuration() {
double total = 0.0;

for (const Flight& flight : flights) {
    total += flight.getDuration();
}

return total;

}

void Itinerary::display() {
std::cout << "\nFlight Itinerary:\n";

if (flights.empty()) {
    std::cout << "No flights in the itinerary.\n";
} else {
    for (const Flight& flight : flights) {
        std::cout << flight.getSourceCode()
                  << " -> "
                  << flight.getDestinationCode()
                  << '\n';
    }
}

std::cout << "\nTotal Duration: "
          << getTotalDuration() << " hours\n";

std::cout << "Total Fare: Rs. "
          << getTotalPrice() << '\n';

}
