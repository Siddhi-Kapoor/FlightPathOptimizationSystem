# FlightPath – Flight Itinerary Planning & Optimization System

## 1. About the Project

FlightPath is a C++17-based Flight Itinerary Planning and Optimization System developed to help users find suitable flight routes between two airports.

Users can enter their source and destination airport codes and select their preferred route based on ticket price, travel duration, number of stops, or a balanced combination of these factors.

The system uses graph-based route optimization to find suitable itineraries. It also includes a flight cancellation simulation that allows users to search for an alternative route when a selected flight becomes unavailable.

## 2. Objectives

- To find suitable flight routes between two airports.
- To compare itineraries based on ticket price, travel time, and number of stops.
- To implement Object-Oriented Programming concepts in a practical application.
- To understand graph representation and route optimization.
- To implement flexible route-selection strategies.
- To handle flight cancellations and find alternative itineraries.
- To organize project data using CSV files.

## 3. Key Features

- **Flight Route Search:** Find available routes between source and destination airports.
- **Cheapest Route:** Find an itinerary with the lowest total ticket price.
- **Fastest Route:** Find an itinerary with the shortest total travel duration.
- **Fewest Stops:** Select an itinerary with the minimum number of flight connections.
- **Balanced Route:** Consider ticket price and travel duration together.
- **Flight Cancellation:** Simulate the cancellation of a selected flight.
- **Alternative Route Search:** Find another available itinerary after cancellation.
- **Airport Directory:** Display available airport information.
- **Flight Directory:** Display available flights, fares, durations, and cancellation status.
- **Input Validation:** Handle invalid airport codes, route preferences, and flight data.

## 4. Object-Oriented Programming Concepts

The project demonstrates the following OOP concepts:

- **Encapsulation:** Keeps data members private and provides access through public member functions.
- **Abstraction:** Provides common interfaces for route optimization.
- **Inheritance:** Allows different route strategies to inherit from a common base class.
- **Polymorphism:** Uses overridden functions to apply different route optimization methods.
- **Composition:** An itinerary contains multiple flight objects.
- **Association:** Flights represent connections between source and destination airports.

## 5. Design Patterns

### Strategy Pattern

The Strategy Pattern allows different route optimization methods to be implemented through a common interface. The system can select a strategy based on the user's route preference.

### Factory Pattern

The Factory Pattern creates the appropriate route strategy based on the user's selection. This avoids creating each strategy separately in the main application.

## 6. Technologies Used

- Programming Language: C++17
- Compiler: GCC / MinGW g++
- IDE: Visual Studio Code
- Standard Library: C++ STL
- Algorithm: Dijkstra's Algorithm
- Data Storage: CSV files
- Version Control: Git and GitHub

## 7. Project Structure

| File / Folder | Description |
|---|---|
| `Airport.h / Airport.cpp` | Stores airport details and related functions |
| `AirportManager.h / AirportManager.cpp` | Manages airport records |
| `Flight.h / Flight.cpp` | Stores flight information and validates flight details |
| `Passenger.h / Passenger.cpp` | Defines passenger information |
| `Itinerary.h / Itinerary.cpp` | Stores and displays itinerary details and calculations |
| `RouteStrategy.h / RouteStrategy.cpp` | Contains route strategy implementations |
| `RouteOptimizer.h / RouteOptimizer.cpp` | Handles flight management, route searching, and optimization |
| `main.cpp` | Main application, CSV loading, menu, and user interaction |
| `AirportTest.cpp` | Airport-related testing |
| `FlightTest.cpp` | Flight-related testing |
| `RouteOptimizerTest.cpp` | Route optimization testing |
| `data/airports.csv` | Stores airport records |
| `data/flights.csv` | Stores flight records |
| `.vscode/` | Visual Studio Code configuration |
| `.gitignore` | Specifies files excluded from Git tracking |

## 8. Data Files

FlightPath uses CSV files to store airport and flight information.

### airports.csv

Contains the following fields:

- `code`
- `name`
- `city`

### flights.csv

Contains the following fields:

- `flightNumber`
- `source`
- `destination`
- `price`
- `duration`

The application loads these files when it starts. It validates the records and uses the loaded information for airport display, flight display, and route optimization.

Both CSV files must remain inside the `data` folder.

## 9. How to Build and Run

### Requirements

- GCC / MinGW g++ compiler
- Visual Studio Code
- C++17 support

Open the project folder in VS Code and open the integrated PowerShell terminal.

Run the following two commands:

**Step 1: Compile the project**

```powershell
g++ -std=c++17 main.cpp Airport.cpp AirportManager.cpp Flight.cpp Itinerary.cpp Passenger.cpp RouteOptimizer.cpp RouteStrategy.cpp -o FlightPath.exe
```

**Step 2: Run the application**

```powershell
.\FlightPath.exe
```

Make sure the terminal is opened in the main project folder so the application can locate the CSV files inside the `data` folder.

## 10. How the System Works

1. The application starts and loads airport and flight information from the CSV files.
2. The system validates the loaded information.
3. The main menu is displayed.
4. The user can choose to find an itinerary, view available flights, view airports, or exit.
5. When searching for an itinerary, the user enters the source and destination airport codes.
6. The user selects a route preference: Cheapest, Fastest, Fewest Stops, or Balanced.
7. The selected strategy evaluates available flights using the route optimization algorithm.
8. The recommended itinerary is displayed with its flight details, total price, and duration.
9. The user can optionally simulate a flight cancellation.
10. If a flight is cancelled, the system searches for an alternative available route.

## 11. Sample Flight Network

The project includes sample airport and flight records for demonstration.

Some example connections are:

| Flight Number | Route | Ticket Price |
|---|---|---:|
| AI101 | DEL → HYD | Rs. 3,200 |
| 6E201 | HYD → MAA | Rs. 2,800 |
| UK101 | DEL → MAA | Rs. 7,500 |
| 6E301 | DEL → BLR | Rs. 4,000 |
| 6E302 | BLR → MAA | Rs. 2,200 |

For example, a journey from Delhi (DEL) to Chennai (MAA) can be planned through Hyderabad, Bengaluru, or other available connections.

## 12. Future Improvements

- Add more airports and flight connections.
- Improve CSV parsing and data validation.
- Include additional itinerary preferences.
- Improve the user interface.
- Expand automated testing.
- Add more advanced flight management features.

## 13. Conclusion

FlightPath demonstrates how C++ and Object-Oriented Programming can be used to develop a practical flight itinerary planning and optimization system.

It combines object-oriented design, graph algorithms, route-selection strategies, and CSV-based data loading to help users find suitable flight connections and handle changes caused by flight cancellations.

The project also provides practical experience in modular programming, testing, and collaborative software development using Git and GitHub.
