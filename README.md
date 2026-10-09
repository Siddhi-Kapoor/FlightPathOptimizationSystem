FlightPath — Flight Itinerary Planning & Optimization System

About the Project

FlightPath is a C++17-based Flight Itinerary Planning and Optimization System that helps passengers find suitable flight routes between two airports based on their preferences.

Users can select a source airport, destination airport, and optimization preference such as cheapest route, fastest route, fewest stops, or a balanced option. The system recommends a suitable itinerary using object-oriented programming concepts and graph-based route searching.

The project also simulates flight cancellations and searches for alternative itineraries when the original route becomes unavailable.

Objectives

- Find suitable flight itineraries between airports.
- Compare routes based on cost, duration, and number of stops.
- Demonstrate core Object-Oriented Programming concepts in C++.
- Apply design patterns to make route optimization flexible.
- Handle flight cancellations and find alternative routes.
- Practice collaborative development using Git and GitHub.

Key Features

- Route Search: Find possible itineraries between source and destination airports.
- Cheapest Route: Recommend an itinerary based on ticket cost.
- Fastest Route: Recommend an itinerary based on travel duration.
- Fewest Stops: Prefer itineraries with fewer intermediate stops.
- Balanced Optimization: Consider cost, duration, and stops together.
- Flight Disruption Simulation: Simulate a flight cancellation and search for an alternative itinerary.
- Itinerary Details: Display the route, total cost, duration, and number of stops.
- File Handling: Load flight information from a local data file.

OOP Concepts Used

- Encapsulation: Keep class data private and provide controlled access through public methods.
- Abstraction: Define a common interface for route optimization strategies.
- Inheritance: Implement different optimization strategies using a common base class.
- Polymorphism: Select and execute different optimization strategies through a base-class interface.
- Composition: An itinerary contains multiple flights.
- Association: Flights connect source and destination airports.

Design Patterns

- Strategy Pattern: Supports different route optimization preferences, such as cheapest, fastest, and fewest stops.
- Factory Pattern (optional): Creates the appropriate optimization strategy based on the user's selection.

Technology Stack

- Language: C++17
- Concepts: OOP, STL, graph representation, file handling, exception handling
- Algorithm: Dijkstra's algorithm for route searching
- Development Environment: Visual Studio Code
- Version Control: Git and GitHub

How It Works

1. The user enters the source and destination airports.
2. The user selects a route optimization preference.
3. The system searches the available flight network.
4. The selected optimization strategy evaluates possible routes.
5. The system displays the recommended itinerary and its details.
6. If a flight is cancelled in the simulation, the system searches for an alternative route.


---

FlightPath — Find a route that fits your journey.
