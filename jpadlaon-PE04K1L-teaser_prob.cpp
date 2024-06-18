#include <iostream>

using namespace std;

// A function named progdescription which simply displays a description of what the program is all about with the programmer's name, date done, and subject number.
void progdescription() {
    cout << "This is a program using C++ that asks the user to input three numbers (x, y, z), and find the highest and lowest number, and output their difference." << endl << endl;
    cout << "Programmer: JODELL MAE P. ADLAON" << endl;
    cout << "Date: APRIL 26, 2024" << endl;
    cout << "Subject Number: CMSC 28" << endl << endl;
}

// A function named readdata that asks the user to input the value of the three variables (x, y, z).
void readdata(int& x, int& y, int& z) {
    cout << "\nPlease input three numbers (either separate them by hitting SPACEBAR or clicking ENTER): ";
    cin >> x >> y >> z;
}

// A functon named getlarge having three parameters (x, y, z) and returns the highest of these three variables to the main program.
int getlarge(int x, int y, int z) {
    int largest = x;
    if (y > largest) {
        largest = y;
    }
    if (z > largest) {
        largest = z;
    }
    return largest;
}

// A functon named getsmall having three parameters (x, y, z) and returns the smallest of these three variables to the main program.
int getsmall(int x, int y, int z) {
    int smallest = x;
    if (y < smallest) {
        smallest = y;
    }
    if (z < smallest) {
        smallest = z;
    }
    return smallest;
}

// A function named showdata with parameters for the variables (x, y, z, the highest and smallest values) and displays all these values with proper labels. 
void showdata(int x, int y, int z, int largest, int smallest) {
    cout << "\nThe three inputted numbers are: " << x << ", " << y << ", " << z << endl;
    cout << "The highest number is: " << largest << endl;
    cout << "The smallest number is: " << smallest << endl;
    cout << "The difference between the highest and smallest number is: " << largest - smallest << endl;
}

// driver code 
int main() {
    int x, y, z;
    int largeval, smallval, diff;

    progdescription();
    readdata(x, y, z);
    smallval = getsmall(x, y, z);
    largeval = getlarge(x, y, z);
    diff = largeval - smallval;     // assignment statement within main function to get the difference between the highest and the lowest value
    showdata(x, y, z, largeval, smallval);

    return 0;
}