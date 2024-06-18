#include <iostream>

using namespace std;

// Function to display program description
void progdescription() {
    cout << "A program using C++ that asks the user to input an integer and convert this number to its binary equivalent." << endl << endl;
    cout << "Programmer: JODELL MAE P. ADLAON" << endl;
    cout << "Date: APRIL 26, 2024" << endl;
    cout << "Subject Number: CMSC 28" << endl << endl;
}

// A function named readData which gets user input and stores it in variable num
void readdata(int& num) {
    cout << "Please enter an integer: ";
    cin >> num;
}

// A function named decimalToBinary which converts the entered decimal number to its binary equivalent
void decimalToBinary(int num) 
{
    // array to store binary number
	int binaryNum[32];

	// counter for binary array
	int i = 0;
	while (num > 0) {
	    
	   // storing remainder in binary array
	    binaryNum[i] = num % 2;
	    num = num / 2;
	    i++;
	}
	
    cout << "The binary equivalent is: ";
    
    // printing binary array in reverse order
	for (int j = i - 1; j >= 0; j--) {
		cout << binaryNum[j];
	}
    
}

// driver code
int main() {
    int num;

    progdescription();

    readdata(num);

    decimalToBinary(num);

    return 0;
}