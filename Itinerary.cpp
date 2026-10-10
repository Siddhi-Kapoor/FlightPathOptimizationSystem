
#include <iostream>
#include "Itinerary.h"

void Itinerary::addFlight(Flight flight) {
    flights.push_back(flight);
}

double Itinerary::getTotalPrice() {
    double total = 0.0;

    for (Flight flight : flights) {
        total += flight.getTicketPrice();
    }

    return total;
}

double Itinerary::getTotalDuration() {
    double total = 0.0;

    for (Flight flight : flights) {
        total += flight.getDuration();
    }

    return total;
}

void Itinerary::display() {
    std::cout << "\n===== Flight Itinerary =====\n";

    if (flights.empty()) {
        std::cout << "No flights in the itinerary.\n";
    }

    for (std::size_t i = 0; i < flights.size(); i++) {
        std::cout << "\nFlight " << i + 1 << ":\n";
        flights[i].display();
    }

    std::cout << "\nTotal Ticket Price: Rs. "
              << getTotalPrice() << '\n';

    std::cout << "Total Flight Duration: "
              << getTotalDuration() << " hours\n";
}

