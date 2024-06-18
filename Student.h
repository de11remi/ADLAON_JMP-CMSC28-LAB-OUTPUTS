// CMSC 28 (K-1L)
// Submitted by: Jodell Mae P. Adlaon

#include "PE08_Person.h"  // Include the Person header file

// Definition of the Student class which inherits from Person
class Student : public Person {
private:
    string studentNum;  // Student number (private attribute)

public:
    string Course;      // Course (public attribute)
    string Department;  // Department (public attribute)
    string College;     // College (public attribute)

    // Constructor to initialize all attributes, including those from the base class
    Student(const string &fname = "", const string &lname = "", const string &gender = "", const string &emailAdd = "", const string &cpNumber = "",
            const string &studentNum = "", const string &Course = "", const string &Department = "", const string &College = "")
        : Person(fname, lname, gender, emailAdd, cpNumber), studentNum(studentNum), Course(Course), Department(Department), College(College) {}

    // Setter for student number
    void setStudentNum(const string &studentNum) {
        this->studentNum = studentNum;  // Assign parameter value to member variable
    }

    // Getter for student number
    string getStudentNum() const {
        return studentNum;  // Return the value of student number
    }

    // Setter for course
    void setCourse(const string &Course) {
        this->Course = Course;  // Assign parameter value to member variable
    }

    // Getter for course
    string getCourse() const {
        return Course;  // Return the value of course
    }

    // Setter for department
    void setDepartment(const string &Department) {
        this->Department = Department;  // Assign parameter value to member variable
    }

    // Getter for department
    string getDepartment() const {
        return Department;  // Return the value of department
    }

    // Setter for college
    void setCollege(const string &College) {
        this->College = College;  // Assign parameter value to member variable
    }

    // Getter for college
    string getCollege() const {
        return College;  // Return the value of college
    }
};