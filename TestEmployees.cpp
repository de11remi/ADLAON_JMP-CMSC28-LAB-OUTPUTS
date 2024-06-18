#include <iostream>    // Include the iostream library for input and output
#include <limits>      // Include this header for numeric_limits
#include "Employees.h" // Include the Employees header file

using namespace std;   // Use the standard namespace


int main() {
    cout << "\nThis program creates an object of class Employees, and calls all the methods implemented for Class Employees and all the methods that it inherited from Class Person.\n" << endl;  // Output program description
    cout << "Programmed by: Jodell Mae P. Adlaon\n" << endl;  // Output programmer's name

    string fname, lname, gender, empNum, position, office, email, cpNumber;  // Declare variables of type string
    double salary;  // Declare variable for salary

    cout << "Employee's First Name: ";  // Prompt for first name
    cin >> fname;                       // Read first name

    cout << "Employee's Last Name: ";  // Prompt for last name
    cin >> lname;                      // Read last name

    cout << "Employee's Gender: ";  // Prompt for gender
    cin >> gender;                  // Read gender

    cout << "Employee Number: ";  // Prompt for employee number
    cin >> empNum;                // Read employee number

    cout << "Position: ";  // Prompt for position
    cin >> position;       // Read position

    cout << "Office/Unit: ";  // Prompt for office/unit
    cin.ignore();             // Ignore newline character left in buffer
    getline(cin, office);     // Read office/unit

    while (true) {  // Loop until a valid salary is entered
        cout << "Salary(in PHP currency, and please do not include comma ',' in your input): ";  // Prompt for salary
        cin >> salary;  // Read salary
        
        // Check if the input failed (if salary is not a valid double)
        if (cin.fail()) {
            cin.clear();  // Clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n');   // Ignore invalid input
            cout << "Invalid input. Please enter a numeric value for the salary." << endl;  // Display error message
        } else {
            break;  // Break the loop if valid input is received
        }
    }                                                                          

    cout << "Email Address: ";  // Prompt for email address
    cin >> email;               // Read email address

    cout << "Phone Number: ";  // Prompt for phone number
    cin >> cpNumber;           // Read phone number

    // Create Employees object with input values
    Employees employee(fname, lname, gender, email, cpNumber, empNum, position, office, salary);

    cout << "\n-------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

    // Output the employee's details
    cout << "Hi, " << employee.getFname() << " " << employee.getLname() << "! Welcome to the team at " << employee.getOffice() << ". "
         << "Your position is " << employee.getPosition() << " and your employee number is " << employee.getEmpNum() << ". Your salary is PHP " << employee.getSalary() << "."
         << " Your email address is " << employee.getEmailAdd() << " and your phone number is " << employee.getCpNumber() << "." << endl;

    return 0;  // Return 0 to indicate successful execution
}