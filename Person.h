// CMSC 28 (K-1L)
// Submitted by: Jodell Mae P. Adlaon

#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

// The Person class represents an individual with a first name, last name, and gender.
class Person {
private:
    string fname;  // First name of the person
    string lname;  // Last name of the person
    string gender; // Gender of the person

public:
    // Setter for the first name
    void setFirstName(const string& fn);

    // Setter for the last name
    void setLastName(const string& ln);

    // Setter for the gender
    void setGender(const string& g);

    // Getter for the first name
    string getFirstName() const;

    // Getter for the last name
    string getLastName() const;

    // Getter for the gender
    string getGender() const;
};

#endif
