# FlightPath – Flight Itinerary Planning & Optimization System

## About the Project

FlightPath is a C++17-based Flight Itinerary Planning and Optimization System. It helps users find suitable flight routes between two airports based on their preferences.

Users can enter their source and destination airport codes and choose how they want their journey to be planned. The system compares available routes and recommends an itinerary based on cost, travel time, number of stops, or a balanced combination of these factors.

It also includes a flight cancellation simulation that allows the system to search for an alternative route when a selected flight becomes unavailable.

## Objectives

- To find suitable flight routes between two airports.
- To compare itineraries based on ticket price, travel time, and number of stops.
- To apply Object-Oriented Programming concepts in a practical project.
- To understand graph-based algorithms and route optimization.
- To implement design patterns for flexible route selection.
- To handle flight cancellations and find alternative itineraries.

## Key Features

- **Flight Route Search:** Find available routes between source and destination airports.
- **Cheapest Route:** Find an itinerary with the lowest total ticket cost.
- **Fastest Route:** Find an itinerary with the shortest total travel time.
- **Fewest Stops:** Select a route with fewer flight connections.
- **Balanced Route:** Compare routes using cost, duration, and connection factors.
- **Flight Cancellation:** Simulate the cancellation of a flight.
- **Alternative Route Search:** Find another available itinerary after a cancellation.
- **Itinerary Details:** Display flight information, total cost, duration, and stops.
- **Input Validation:** Handle invalid flight details and user selections.

## Object-Oriented Programming Concepts

The project uses the following OOP concepts:

- **Encapsulation:** Keeps data private and provides access through public member functions.
- **Abstraction:** Provides common interfaces for route optimization.
- **Inheritance:** Allows different route strategies to share a common base class.
- **Polymorphism:** Selects different route optimization methods through a common interface.
- **Composition:** An itinerary contains multiple flights.
- **Association:** Flights connect source and destination airports.

## Design Patterns

**1. Strategy Pattern**

The Strategy Pattern is used to implement different route optimization methods. Each strategy follows a common interface but uses a different approach to evaluate routes.

**2. Factory Pattern**

The Factory Pattern creates the appropriate route strategy based on the user's selection.

These patterns make the route optimization system easier to extend and maintain.

## Technologies Used

- Programming Language: C++17
- Compiler: GCC / MinGW g++
- IDE: Visual Studio Code
- Standard Library: C++ STL
- Algorithm: Dijkstra's Algorithm
- Version Control: Git and GitHub

## Project Structure

| File | Description |
|---|---|
| `Airport.h / Airport.cpp` | Airport details and related operations |
| `AirportManager.h / AirportManager.cpp` | Manages airport records |
| `Flight.h / Flight.cpp` | Flight information and validation |
| `Passenger.h / Passenger.cpp` | Passenger details |
| `Itinerary.h / Itinerary.cpp` | Stores and displays itinerary information |
| `RouteStrategy.h / RouteStrategy.cpp` | Defines route optimization strategies |
| `RouteOptimizer.h / RouteOptimizer.cpp` | Handles flight network and route searching |
| `main.cpp` | Main application and user interaction |

## How to Build and Run

Make sure GCC or MinGW is installed and available in your terminal.

Open the project folder in VS Code and run:

**Compile:**

```bash
g++ -std=c++17 main.cpp Airport.cpp AirportManager.cpp Flight.cpp Itinerary.cpp Passenger.cpp RouteOptimizer.cpp RouteStrategy.cpp -o FlightPath.exe
```

**Run on Windows PowerShell:**

```powershell
.\FlightPath.exe
```

## How the System Works

1. The user enters the source and destination airport codes.
2. The user selects a route preference.
3. The system checks the available flight network.
4. The selected optimization strategy evaluates possible routes.
5. The recommended itinerary is displayed with its details.
6. The user can simulate a flight cancellation.
7. If a flight is cancelled, the system searches for an alternative route.

## Sample Flight Network

The demonstration includes the following routes:

| Flight Number | Route | Ticket Price |
|---|---|---:|
| F101 | DEL → HYD | Rs. 4,000 |
| F102 | HYD → MAA | Rs. 2,800 |
| F201 | DEL → BOM | Rs. 3,000 |
| F202 | BOM → MAA | Rs. 4,200 |

For example, a journey from Delhi (DEL) to Chennai (MAA) can be planned through Hyderabad (HYD) or Mumbai (BOM).

## Future Improvements

- Load flight information from external files.
- Add more airports and flight connections.
- Include more advanced itinerary options.
- Improve the user interface.
- Add more comprehensive automated tests.

## Conclusion

FlightPath demonstrates how C++ and Object-Oriented Programming can be used to develop a practical flight itinerary planning system. It combines graph algorithms, design patterns, and route optimization to help users find suitable flight connections and handle changes caused by flight cancellations.

The project also provides practical experience in software development, modular programming, testing, and collaborative work using Git and GitHub.
