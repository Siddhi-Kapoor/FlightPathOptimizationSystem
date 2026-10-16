#include <iostream>
#include "Airport.h"
using namespace std;

int main() {
    Airport a1("HYD", "Rajiv Gandhi Airport", "Hyderabad");
    Airport a2("MAA", "Chennai International Airport", "Chennai");

    a1.display();
    cout << "Code returned: " << a1.getCode() << endl;

    cout << endl;

    a2.display();
    cout << "Code returned: " << a2.getCode() << endl;

    return 0;
}