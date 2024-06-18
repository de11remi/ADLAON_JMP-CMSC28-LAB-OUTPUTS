// CMSC 28 (K-1L)
// Submitted by: Jodell Mae P. Adlaon

#include "PE08_Person.h"  // Include the Person header file

// Definition of the Employees class which inherits from Person
class Employees : public Person {
private:
    string empNum;  // Employee number (private attribute)

public:
    string Position;  // Position (public attribute)
    string Office;    // Office (public attribute)
    double Salary;    // Salary (public attribute)

    // Constructor to initialize all attributes, including those from the base class
    Employees(const string &fname = "", const string &lname = "", const string &gender = "", const string &emailAdd = "", const string &cpNumber = "",
              const string &empNum = "", const string &Position = "", const string &Office = "", double Salary = 0.0)
        : Person(fname, lname, gender, emailAdd, cpNumber), empNum(empNum), Position(Position), Office(Office), Salary(Salary) {}

    // Setter for employee number
    void setEmpNum(const string &empNum) {
        this->empNum = empNum;  // Assign parameter value to member variable
    }

    // Getter for employee number
    string getEmpNum() const {
        return empNum;  // Return the value of employee number
    }

    // Setter for position
    void setPosition(const string &Position) {
        this->Position = Position;  // Assign parameter value to member variable
    }

    // Getter for position
    string getPosition() const {
        return Position;  // Return the value of position
    }

    // Setter for office
    void setOffice(const string &Office) {
        this->Office = Office;  // Assign parameter value to member variable
    }

    // Getter for office
    string getOffice() const {
        return Office;  // Return the value of office
    }

    // Setter for salary
    void setSalary(double Salary) {
        this->Salary = Salary;  // Assign parameter value to member variable
    }

    // Getter for salary
    double getSalary() const {
        return Salary;  // Return the value of salary
    }
};
