#ifndef AIRPORT_H
#define AIRPORT_H

#include <iostream>
#include <string>
using namespace std;

class Airport {
private:
    string code;
    string name;
    string city;

public:
    Airport(string c, string n, string ct);
    void display();
    string getCode();
};

#endif
