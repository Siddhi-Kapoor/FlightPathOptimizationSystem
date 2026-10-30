#include "Passenger.h"
#include "RouteOptimizer.h"

#include <algorithm>
#include <cctype>
#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace {

std::string toUpper(std::string value) {
    std::transform(value.begin(), value.end(), value.begin(),
        [](unsigned char character) {
            return static_cast<char>(std::toupper(character));
        });
    return value;
}

bool itineraryContainsFlight(const Itinerary& itinerary,
                             const std::string& flightNumber) {
    const std::vector<Flight>& flights = itinerary.getFlights();
    return std::find_if(flights.begin(), flights.end(),
        [&flightNumber](const Flight& flight) {
            return flight.getFlightNumber() == flightNumber;
        }) != flights.end();
}

void addDemoFlights(FlightNetwork& network) {
    network.addFlight(Flight("F101", "DEL", "HYD", 4000, 2.0));
    network.addFlight(Flight("F102", "HYD", "MAA", 2800, 2.3333333333));
    network.addFlight(Flight("F201", "DEL", "BOM", 3000, 2.1666666667));
    network.addFlight(Flight("F202", "BOM", "MAA", 4200, 2.0));
}

} // namespace

int main() {
    try {
        std::string passengerName;
        std::cout << "Passenger name: ";
        std::getline(std::cin, passengerName);
        if (passengerName.empty()) {
            passengerName = "Guest";
        }
        const Passenger passenger(passengerName);

        std::string source;
        std::string destination;
        std::cout << "Source airport code: ";
        std::cin >> source;
        std::cout << "Destination airport code: ";
        std::cin >> destination;
        source = toUpper(source);
        destination = toUpper(destination);

        std::cout << "\nPreference:\n"
                  << "1. Cheapest\n"
                  << "2. Fastest\n"
                  << "3. Fewest Stops\n"
                  << "4. Balanced\n"
                  << "Choose 1-4: ";
        int choice = 0;
        if (!(std::cin >> choice)) {
            std::cerr << "Invalid preference selection.\n";
            return 1;
        }
        const std::unique_ptr<RouteStrategy> strategy =
            createRouteStrategy(choice);

        FlightNetwork network;
        addDemoFlights(network);

        Itinerary itinerary;
        if (!network.findRoute(source, destination, *strategy, itinerary)) {
            std::cout << "No available route from " << source
                      << " to " << destination << ".\n";
            return 0;
        }

        std::cout << "\nPassenger: " << passenger.getName()
                  << "\nPreference: " << strategy->getName() << '\n';
        itinerary.display();

        std::cout << "\nSimulate a flight cancellation? (y/n): ";
        char simulateCancellation = 'n';
        std::cin >> simulateCancellation;
        if (simulateCancellation == 'y' || simulateCancellation == 'Y') {
            std::string flightNumber;
            std::cout << "Enter a flight number from this itinerary: ";
            std::cin >> flightNumber;

            if (!itineraryContainsFlight(itinerary, flightNumber)) {
                std::cout << "That flight is not part of this itinerary.\n";
                return 1;
            }
            if (!network.cancelFlight(flightNumber)) {
                std::cout << "The flight is already unavailable.\n";
                return 1;
            }

            std::cout << "\nFlight " << flightNumber
                      << " cancelled. Searching for an alternative...\n";
            Itinerary alternative;
            if (!network.findRoute(source, destination, *strategy, alternative)) {
                std::cout << "No alternative route is available.\n";
                return 0;
            }
            alternative.display();
        }
    } catch (const std::exception& error) {
        std::cerr << "Error: " << error.what() << '\n';
        return 1;
    }
    return 0;
}
