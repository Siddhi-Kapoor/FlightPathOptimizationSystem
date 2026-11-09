#ifndef AIRPORT_H
#define AIRPORT_H

#include <iostream>
#include <string>

class Airport {
private:
    std::string code;
    std::string name;
    std::string city;

public:
    Airport(std::string code, std::string name, std::string city);
    void display(std::ostream& output = std::cout) const;
    const std::string& getCode() const;
    const std::string& getName() const;
    const std::string& getCity() const;
};

#endif
