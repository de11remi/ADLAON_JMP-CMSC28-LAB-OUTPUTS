#include <iostream>
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

int main() {
    Laptop lappy1("Asus", "Windows", 2022);
    lappy1.dataDisplay();
    return 0;
}