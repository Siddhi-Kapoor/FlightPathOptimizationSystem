#include <iostream>
#include "Airport.h"
using namespace std;

Airport::Airport(string c, string n, string ct) {
    code = c;
    name = n;
    city = ct;
}
void Airport::display() {
    cout << "Airport Code: " << code << endl;
    cout << "Airport Name: " << name << endl;
    cout << "City: " << city << endl;
}

string Airport::getCode() {
    return code;
}
