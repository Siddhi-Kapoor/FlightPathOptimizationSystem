#include "Airport.h"
#include "Itinerary.h"
#include "RouteOptimizer.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace {

void printColor(const std::string& color) {
    std::cout << color;
}

void resetColor() {
    std::cout << "\033[0m";
}

void printHeader(const std::string& title) {
    std::cout << "\n";
    printColor("\033[1;36m");
    std::cout << "========================================\n";
    std::cout << "         " << title << "\n";
    std::cout << "========================================\n";
    resetColor();
}

void printDivider() {
    printColor("\033[2;37m");
    std::cout << "------------------------------------------------------\n";
    resetColor();
}

void printMenu() {
    std::cout << "\n";
    printColor("\033[1;33m");
    std::cout << "  [1] Find an itinerary\n";
    std::cout << "  [2] View available flights\n";
    std::cout << "  [3] View airports\n";
    std::cout << "  [0] Exit\n";
    resetColor();
}

void printSuccess(const std::string& message) {
    printColor("\033[1;32m");
    std::cout << "  " << message << "\n";
    resetColor();
}

void printError(const std::string& message) {
    printColor("\033[1;31m");
    std::cout << "  " << message << "\n";
    resetColor();
}

void printInfo(const std::string& message) {
    printColor("\033[1;34m");
    std::cout << "  " << message << "\n";
    resetColor();
}

std::string trim(const std::string& value) {
    const std::string whitespace = " \t\r\n";
    const std::size_t first = value.find_first_not_of(whitespace);
    if (first == std::string::npos) {
        return "";
    }
    const std::size_t last = value.find_last_not_of(whitespace);
    return value.substr(first, last - first + 1);
}

std::string uppercase(std::string value) {
    std::transform(value.begin(), value.end(), value.begin(),
        [](unsigned char character) {
            return static_cast<char>(std::toupper(character));
        });
    return value;
}

std::vector<std::string> splitCsvRow(const std::string& row) {
    std::vector<std::string> fields;
    std::stringstream input(row);
    std::string field;
    while (std::getline(input, field, ',')) {
        fields.push_back(trim(field));
    }
    if (!row.empty() && row.back() == ',') {
        fields.emplace_back();
    }
    return fields;
}

double parseNumber(const std::string& value, const std::string& fieldName,
                   std::size_t lineNumber) {
    std::size_t parsedLength = 0;
    try {
        const double number = std::stod(value, &parsedLength);
        if (parsedLength != value.size()) {
            throw std::invalid_argument("trailing characters");
        }
        return number;
    } catch (const std::exception& error) {
        throw std::runtime_error("Invalid " + fieldName + " on data line " +
                                 std::to_string(lineNumber) + ": " + error.what());
    }
}

RouteOptimizer loadFlights(const std::string& filename) {
    std::ifstream input(filename);
    if (!input) {
        throw std::runtime_error("Could not open flight data file: " + filename);
    }

    RouteOptimizer optimizer;
    std::string row;
    std::size_t lineNumber = 0;
    bool firstRecord = true;
    while (std::getline(input, row)) {
        ++lineNumber;
        if (trim(row).empty() || trim(row).front() == '#') {
            continue;
        }
        const std::vector<std::string> fields = splitCsvRow(row);
        if (firstRecord && !fields.empty() && fields[0] == "flightNumber") {
            firstRecord = false;
            continue;
        }
        firstRecord = false;
        if (fields.size() != 5) {
            throw std::runtime_error("Expected 5 comma-separated fields on flight data line " +
                                     std::to_string(lineNumber) + ".");
        }
        try {
            optimizer.addFlight(Flight(
                uppercase(fields[0]), uppercase(fields[1]), uppercase(fields[2]),
                parseNumber(fields[3], "ticket price", lineNumber),
                parseNumber(fields[4], "duration", lineNumber)));
        } catch (const std::exception& error) {
            throw std::runtime_error("Flight data line " + std::to_string(lineNumber) + ": " +
                                     error.what());
        }
    }
    if (optimizer.getFlights().empty()) {
        throw std::runtime_error("The flight data file contains no flights.");
    }
    return optimizer;
}

std::vector<Airport> loadAirports(const std::string& filename) {
    std::ifstream input(filename);
    if (!input) {
        throw std::runtime_error("Could not open airport data file: " + filename);
    }

    std::vector<Airport> airports;
    std::string row;
    std::size_t lineNumber = 0;
    bool firstRecord = true;
    while (std::getline(input, row)) {
        ++lineNumber;
        if (trim(row).empty() || trim(row).front() == '#') {
            continue;
        }
        const std::vector<std::string> fields = splitCsvRow(row);
        if (firstRecord && !fields.empty() && fields[0] == "code") {
            firstRecord = false;
            continue;
        }
        firstRecord = false;
        if (fields.size() != 3) {
            throw std::runtime_error("Expected 3 comma-separated fields on airport data line " +
                                     std::to_string(lineNumber) + ".");
        }
        airports.emplace_back(uppercase(fields[0]), fields[1], fields[2]);
    }
    return airports;
}

void printAirports(const std::vector<Airport>& airports) {
    std::cout << "\n";
    printColor("\033[1;32m");
    std::cout << "  Available airports\n";
    resetColor();

    for (const Airport& airport : airports) {
        std::cout << "    ";
        airport.display();
    }
    std::cout << '\n';
}

void printFlights(const RouteOptimizer& optimizer) {
    std::cout << "\n";
    printColor("\033[1;32m");
    std::cout << "  AVAILABLE FLIGHTS\n";
    resetColor();

    std::cout << "  " << std::left << std::setw(10) << "Flight"
              << std::setw(18) << "Route"
              << std::setw(13) << "Fare"
              << std::setw(11) << "Duration"
              << "Status\n";
    printDivider();

    for (const Flight& flight : optimizer.getFlights()) {
        std::ostringstream duration;
        duration << std::fixed << std::setprecision(1)
                 << flight.getDuration() << 'h';

        std::cout << "  " << std::left << std::setw(10)
                  << flight.getFlightNumber()
                  << std::setw(18) << (flight.getSourceCode() + " -> " + flight.getDestinationCode())
                  << "Rs. " << std::setw(9) << std::fixed << std::setprecision(2) << flight.getTicketPrice()
                  << std::setw(11) << duration.str()
                  << (optimizer.isCancelled(flight.getFlightNumber()) ? "CANCELLED" : "Available")
                  << '\n';
    }
    std::cout << '\n';
}

bool readLine(const std::string& prompt, std::string& value) {
    std::cout << prompt;
    return static_cast<bool>(std::getline(std::cin, value));
}

RoutePreference choosePreference() {
    while (true) {
        std::cout << "\n";
        printColor("\033[1;33m");
        std::cout << "  Optimize by\n";
        std::cout << "    1. Cheapest\n";
        std::cout << "    2. Fastest\n";
        std::cout << "    3. Fewest stops\n";
        std::cout << "    4. Balanced\n";
        resetColor();

        std::string choice;
        if (!readLine("  Select preference [1-4]: ", choice)) {
            throw std::runtime_error("Input ended.");
        }
        choice = trim(choice);
        if (choice == "1") return RoutePreference::Cheapest;
        if (choice == "2") return RoutePreference::Fastest;
        if (choice == "3") return RoutePreference::FewestStops;
        if (choice == "4") return RoutePreference::Balanced;
        printError("Please enter a number from 1 to 4.");
    }
}

bool isKnownAirport(const std::vector<Airport>& airports, const std::string& code) {
    return std::any_of(airports.begin(), airports.end(),
        [&code](const Airport& airport) {
            return airport.getCode() == code;
        });
}

void simulateCancellation(RouteOptimizer& optimizer,
                          const std::string& source,
                          const std::string& destination,
                          const RouteOptimizationStrategy& strategy,
                          const Itinerary& originalItinerary) {
    std::string answer;
    if (!readLine("\n  Simulate a flight cancellation? [y/N]: ", answer) ||
        (uppercase(trim(answer)) != "Y" &&
         uppercase(trim(answer)) != "YES")) {
        return;
    }

    std::cout << "  Flights on this itinerary:";
    for (const Flight& flight : originalItinerary.getFlights()) {
        std::cout << ' ' << flight.getFlightNumber();
    }
    std::cout << '\n';

    std::string flightNumber;
    if (!readLine("  Flight number to cancel: ", flightNumber)) {
        return;
    }

    flightNumber = uppercase(trim(flightNumber));
    const bool belongsToItinerary = std::any_of(
        originalItinerary.getFlights().begin(),
        originalItinerary.getFlights().end(),
        [&flightNumber](const Flight& flight) {
            return flight.getFlightNumber() == flightNumber;
        });

    if (!belongsToItinerary || !optimizer.cancelFlight(flightNumber)) {
        printError("That flight could not be cancelled.");
        return;
    }

    printInfo("Cancellation applied successfully.");
    std::cout << "  " << flightNumber
              << " is now marked as cancelled. Searching for an alternative...\n";

    Itinerary alternative;
    if (optimizer.findRoute(source, destination, strategy, alternative)) {
        printSuccess("Alternative route found.");
        alternative.display(std::cout);
    } else {
        printError("No alternative itinerary is available.");
    }
    std::cout << "  Cancellation remains active for this session.\n";
}

void searchItinerary(RouteOptimizer& optimizer, const std::vector<Airport>& airports) {
    std::string source;
    std::string destination;

    if (!readLine("\n  Source airport code: ", source) ||
        !readLine("  Destination airport code: ", destination)) {
        return;
    }

    source = uppercase(trim(source));
    destination = uppercase(trim(destination));

    if (!isKnownAirport(airports, source) || !isKnownAirport(airports, destination)) {
        printError("Unknown airport code. Choose from the listed airports.");
        return;
    }

    const RoutePreference preference = choosePreference();
    const std::unique_ptr<RouteOptimizationStrategy> strategy =
        createRouteStrategy(preference);

    Itinerary itinerary;
    if (!optimizer.findRoute(source, destination, *strategy, itinerary)) {
        printError("No route is available from " + source + " to " + destination + ".");
        return;
    }

    printColor("\033[1;35m");
    std::cout << "\n  Preference: " << strategy->name() << '\n';
    resetColor();

    itinerary.display(std::cout);
    simulateCancellation(optimizer, source, destination, *strategy, itinerary);
}

}  // namespace

int main() {
    try {
        RouteOptimizer optimizer = loadFlights("data/flights.csv");
        const std::vector<Airport> airports = loadAirports("data/airports.csv");

        if (airports.empty()) {
            throw std::runtime_error("The airport data file contains no airports.");
        }

        for (const std::string& code : optimizer.getAirportCodes()) {
            if (!isKnownAirport(airports, code)) {
                throw std::runtime_error("No airport information is available for " + code + ".");
            }
        }

        printHeader("FLIGHTPATH PLANNER");

        while (true) {
            printMenu();
            std::string choice;
            if (!readLine("  Choose an option: ", choice)) {
                std::cout << "\n  Goodbye.\n";
                break;
            }

            choice = trim(choice);

            if (choice == "0") {
                printSuccess("Thanks for using FlightPath. Safe travels!");
                break;
            }

            if (choice == "1") {
                searchItinerary(optimizer, airports);
            } else if (choice == "2") {
                printFlights(optimizer);
            } else if (choice == "3") {
                printAirports(airports);
            } else {
                printError("Please choose 0, 1, 2, or 3.");
            }
        }
    } catch (const std::exception& error) {
        std::cerr << "\nFlightPath error: " << error.what() << '\n';
        return 1;
    }
    return 0;
}
