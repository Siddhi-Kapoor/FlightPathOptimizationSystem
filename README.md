# FlightPath

FlightPath is a C++17 terminal application for comparing and finding routes
through a sample flight network. It is an academic prototype; fares, schedules,
and connections are illustrative and are not live booking information.

## Features

- Find a route by cheapest fare, shortest duration, fewest stops, or a balanced
  score.
- Display the route, individual flights, total fare, total duration, and stops.
- Simulate a cancellation on the selected route and search for an alternative.
- View airport and flight data, loaded from CSV files in `data/`.
- Validate input data and report malformed files or unavailable routes.

## Optimization

All route preferences use Dijkstra's algorithm over the flight graph. Each
preference supplies its own non-negative edge weight using the Strategy pattern:

- **Cheapest:** ticket price.
- **Fastest:** flight duration.
- **Fewest stops:** one unit per flight leg.
- **Balanced:** one unit per leg plus each leg's fare and duration normalized
  against the largest active flight in the sample network.

The strategy factory selects the implementation based on the user's menu
choice. Cancelled flights are excluded from later searches in the same run.

## Build and run

From the project directory, with `g++` installed:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Airport.cpp flight.cpp Itinerary.cpp RouteOptimizer.cpp -o FlightPath.exe
.\FlightPath.exe
```

Run the executable from the project directory so that `data/airports.csv` and
`data/flights.csv` can be found.

## Data format

`data/flights.csv` contains a header followed by:

```text
flightNumber,source,destination,price,duration
```

Price is in rupees and duration is in hours. `data/airports.csv` contains:

```text
code,name,city
```

## Project layout

```text
FlightPathOptimizationSystem/
├── Airport.h/.cpp          # Airport model
├── flight.h/.cpp           # Flight model
├── Itinerary.h/.cpp        # Route details and totals
├── RouteOptimizer.h/.cpp   # Dijkstra and optimization strategies
├── data/                   # Sample airport and flight CSV files
├── AirportTest.cpp         # Airport model smoke test
├── FlightTest.cpp          # Flight model smoke test
├── RouteOptimizerTest.cpp  # Routing, strategy, and cancellation tests
└── main.cpp                # Interactive terminal application
```

Build and run the route optimizer checks with:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic RouteOptimizerTest.cpp flight.cpp Itinerary.cpp RouteOptimizer.cpp -o RouteOptimizerTest.exe
.\RouteOptimizerTest.exe
```
