#ifndef ROUTE_STRATEGY_H
#define ROUTE_STRATEGY_H

#include <memory>
#include <string>

class Flight;

class RouteStrategy {
public:
    virtual ~RouteStrategy() = default;
    virtual double edgeWeight(const Flight& flight) const = 0;
    virtual std::string getName() const = 0;
};

class CheapestStrategy : public RouteStrategy {
public:
    double edgeWeight(const Flight& flight) const override;
    std::string getName() const override;
};

class FastestStrategy : public RouteStrategy {
public:
    double edgeWeight(const Flight& flight) const override;
    std::string getName() const override;
};

class FewestStopsStrategy : public RouteStrategy {
public:
    double edgeWeight(const Flight& flight) const override;
    std::string getName() const override;
};

class BalancedStrategy : public RouteStrategy {
public:
    double edgeWeight(const Flight& flight) const override;
    std::string getName() const override;
};

std::unique_ptr<RouteStrategy> createRouteStrategy(int choice);

#endif
