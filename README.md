# FlightPath — Flight Itinerary Planning & Optimization System

About the Project -

FlightPath is a C++ based Flight Itinerary Planning and Optimization System that helps passengers find suitable flight routes between two airports based on their preferences.

Users can select a source airport, destination airport, and optimization preference such as cheapest route, fastest route, fewest stops, or a balanced option. The system recommends a suitable itinerary using object-oriented programming concepts and graph-based route searching.

The project also simulates flight cancellations and searches for alternative itineraries when the original route becomes unavailable.
 
## Objectives

- Find suitable flight itineraries between airports.
- Compare routes based on cost, duration, and number of stops.
- Demonstrate core Object-Oriented Programming concepts in C++.
- Apply design patterns to make route optimization flexible.
- Handle flight cancellations and find alternative routes.
- Practice collaborative development using Git and GitHub.

## Key Features

- Route Search: Find possible itineraries between source and destination airports.
- Cheapest Route: Recommend an itinerary based on ticket cost.
- Fastest Route: Recommend an itinerary based on travel duration.
- Fewest Stops: Prefer itineraries with fewer intermediate stops.
- Balanced Optimization: Consider cost, duration, and stops together.
- Flight Disruption Simulation: Simulate a flight cancellation and search for an alternative itinerary.
- Itinerary Details: Display the route, total cost, duration, and number of stops.

## OOP Concepts Used

- Encapsulation: Keep class data private and provide controlled access through public methods.
- Abstraction: Define a common interface for route optimization strategies.
- Inheritance: Implement different optimization strategies using a common base class.
- Polymorphism: Select and execute different optimization strategies through a base-class interface.
- Composition: An itinerary contains multiple flights.
- Association: Flights connect source and destination airports.
- Domain classes: `Airport`, `Flight`, `Passenger`, `Itinerary`, and
  `FlightNetwork` represent the core project entities.

## Design Patterns

- Strategy Pattern: Supports different route optimization preferences, such as cheapest, fastest, and fewest stops.
- Factory Pattern : Creates the appropriate optimization strategy based on the user's selection.

## Technology Stack

- Language: C++17
- Concepts: OOP, STL, graph representation, exception handling
- Algorithm: Dijkstra's algorithm for route searching
- Development Environment: Visual Studio Code
- Version Control: Git and GitHub

## Build and Run

The VS Code **Build FlightPath** task compiles the complete application with
MinGW g++ and C++17. From a terminal, run:

```text
g++ -std=c++17 main.cpp Airport.cpp Flight.cpp Itinerary.cpp RouteOptimizer.cpp RouteStrategy.cpp Passenger.cpp -o FlightPath.exe
FlightPath.exe
```

The demo network includes two Delhi-to-Chennai routes. For example, choose
`DEL`, `MAA`, and `1` (Cheapest) to get `DEL -> HYD -> MAA` for Rs. 6,800.
Answer `y` to simulate a cancellation and enter `F102` to cancel `HYD -> MAA`;
the planner will then find `DEL -> BOM -> MAA`.

## Route Preferences

- **Cheapest:** minimizes the total ticket price.
- **Fastest:** minimizes the total flight duration.
- **Fewest Stops:** minimizes the number of flight legs.
- **Balanced:** minimizes the sum of each leg's fare in thousands of rupees,
  duration in hours, and a 2-point per-leg connection penalty.

Each preference is a polymorphic `RouteStrategy` selected by a factory.
`FlightNetwork` owns available flights and handles route search and
cancellations. Route search uses
Dijkstra's algorithm with the selected strategy's non-negative edge weight,
and cancelled flights are excluded from subsequent searches.

## How the Demo Works

1. The user enters the source and destination airports.
2. The user selects a route optimization preference.
3. The system searches the available flight network.
4. The selected optimization strategy evaluates possible routes.
5. The system displays the recommended itinerary and its details.
6. If a flight is cancelled in the simulation, the system searches for an alternative route.


---
