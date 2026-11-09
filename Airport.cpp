#include <iostream>
#include <stdexcept>
#include <utility>
#include "Airport.h"

Airport::Airport(std::string code, std::string name, std::string city)
    : code(std::move(code)), name(std::move(name)), city(std::move(city)) {
    if (this->code.empty() || this->name.empty() || this->city.empty()) {
        throw std::invalid_argument("Airport code, name, and city are required.");
    }
}

void Airport::display(std::ostream& output) const {
    output << code << " - " << name << " (" << city << ")\n";
}

const std::string& Airport::getCode() const {
    return code;
}

const std::string& Airport::getName() const {
    return name;
}

const std::string& Airport::getCity() const {
    return city;
}
