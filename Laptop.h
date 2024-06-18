#include <iostream>
#include <string>
using namespace std;

class Laptop {

private:
    string Brand;
    string OperatingSystem;
    int Year;

public:
    // Constructor
    Laptop(string a, string b, int c) {
        Brand = a;
        OperatingSystem = b;
        Year = c;
    }

    // Member fuynction to display laptop details
    void dataDisplay() {
        cout << "Brand: " << Brand << endl << "Operating Systrem: " << OperatingSystem << endl << "Year: " << Year << endl;
    }
};