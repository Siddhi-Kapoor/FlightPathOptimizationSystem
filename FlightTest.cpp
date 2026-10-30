
#include <iostream>
#include "flight.h"
using namespace std;

int main() {
    Flight f1("AI101", "HYD", "MAA", 4500, 1.5);

    f1.display();

    cout << "Price returned: " << f1.getTicketPrice() << endl;
    cout << "Duration returned: " << f1.getDuration() << endl;
    cout << "Source returned: " << f1.getSourceCode() << endl;
    cout << "Destination returned: " << f1.getDestinationCode() << endl;
    cout << "Flight number returned: " << f1.getFlightNumber() << endl;

    return 0;
}