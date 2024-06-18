// CMSC 28 (K-1L)
// Submitted by: Jodell Mae P. Adlaon

#include <string>  // Include the string library for using string data type

using namespace std;  // Use the standard namespace

// Definition of the Person class
class Person {
private:
    string fname;   // First name (private attribute)
    string lname;   // Last name (private attribute)
    string gender;  // Gender (private attribute)

public:
    string emailAdd;   // Email address (public attribute)
    string cpNumber;   // Cell phone number (public attribute)

    // Constructor to initialize all attributes, with default values
    Person(const string &fname = "", const string &lname = "", const string &gender = "", const string &emailAdd = "", const string &cpNumber = "")
        : fname(fname), lname(lname), gender(gender), emailAdd(emailAdd), cpNumber(cpNumber) {}

    // Setter for first name
    void setFname(const string &fname) {
        this->fname = fname;  // Assign parameter value to member variable
    }

    // Getter for first name
    string getFname() const {
        return fname;  // Return the value of first name
    }

    // Setter for last name
    void setLname(const string &lname) {
        this->lname = lname;  // Assign parameter value to member variable
    }

    // Getter for last name
    string getLname() const {
        return lname;  // Return the value of last name
    }

    // Setter for gender
    void setGender(const string &gender) {
        this->gender = gender;  // Assign parameter value to member variable
    }

    // Getter for gender
    string getGender() const {
        return gender;  // Return the value of gender
    }

    // Setter for email address
    void setEmailAdd(const string &emailAdd) {
        this->emailAdd = emailAdd;  // Assign parameter value to member variable
    }

    // Getter for email address
    string getEmailAdd() const {
        return emailAdd;  // Return the value of email address
    }

    // Setter for cell phone number
    void setCpNumber(const string &cpNumber) {
        this->cpNumber = cpNumber;  // Assign parameter value to member variable
    }

    // Getter for cell phone number
    string getCpNumber() const {
        return cpNumber;  // Return the value of cell phone number
    }
};
