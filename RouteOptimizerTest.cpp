#include "RouteOptimizer.h"

#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>

int main() {
    RouteOptimizer optimizer;
    optimizer.addFlight(Flight("AI101", "DEL", "HYD", 3200, 2.2));
    optimizer.addFlight(Flight("6E201", "HYD", "MAA", 2800, 2.1));
    optimizer.addFlight(Flight("UK101", "DEL", "MAA", 7500, 2.8));
    optimizer.addFlight(Flight("6E301", "DEL", "BLR", 4000, 2.8));
    optimizer.addFlight(Flight("6E302", "BLR", "MAA", 2200, 1.0));

    Itinerary itinerary;
    const auto cheapest = createRouteStrategy(RoutePreference::Cheapest);
    assert(optimizer.findRoute("DEL", "MAA", *cheapest, itinerary));
    assert(std::fabs(itinerary.getTotalPrice() - 6000.0) < 0.001);
    assert(itinerary.getNumberOfStops() == 1);
    assert(itinerary.getFlights().front().getFlightNumber() == "AI101");
    std::ostringstream display;
    itinerary.display(display);
    assert(display.str().find("DEL -> HYD -> MAA") != std::string::npos);
    assert(display.str().find("Total duration : 4h 18m") != std::string::npos);

    const auto fastest = createRouteStrategy(RoutePreference::Fastest);
    assert(optimizer.findRoute("DEL", "MAA", *fastest, itinerary));
    assert(itinerary.getFlights().size() == 1);
    assert(itinerary.getFlights().front().getFlightNumber() == "UK101");

    const auto fewestStops = createRouteStrategy(RoutePreference::FewestStops);
    assert(optimizer.findRoute("DEL", "MAA", *fewestStops, itinerary));
    assert(itinerary.getFlights().size() == 1);

    const auto balanced = createRouteStrategy(RoutePreference::Balanced);
    assert(optimizer.findRoute("DEL", "MAA", *balanced, itinerary));
    assert(itinerary.getFlights().size() == 1);
    assert(itinerary.getFlights().front().getFlightNumber() == "UK101");

    assert(optimizer.cancelFlight("AI101"));
    assert(!optimizer.cancelFlight("AI101"));
    assert(optimizer.findRoute("DEL", "MAA", *cheapest, itinerary));
    assert(itinerary.getFlights().front().getFlightNumber() == "6E301");

    assert(optimizer.cancelFlight("UK101"));
    assert(optimizer.cancelFlight("6E301"));
    assert(!optimizer.findRoute("DEL", "MAA", *cheapest, itinerary));
    assert(itinerary.getFlights().empty());
    assert(optimizer.findRoute("DEL", "DEL", *cheapest, itinerary));
    assert(itinerary.getFlights().empty());

    std::cout << "Route optimizer tests passed.\n";
}
