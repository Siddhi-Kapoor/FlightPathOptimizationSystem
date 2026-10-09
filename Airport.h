#include <iostream>
#include <string>
using namespace std;

class Airport {
private:
    string code;
    string name;
    string city;

public:
    Airport(string c, string n, string ct) {
        code = c;
        name = n;
        city = ct;
    }

    void display() {
        cout << "Airport: " << name << endl;
        cout << "Code: " << code << endl;
        cout << "City: " << city << endl;
    }
};

int main() {
    Airport a1("HYD", "Rajiv Gandhi Airport", "Hyderabad");
    Airport a2("MAA", "Chennai International Airport", "Chennai");

    a1.display();
    cout << endl;
    a2.display();

    return 0;
}
