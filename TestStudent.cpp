#include <iostream>   // Include the iostream library for input and output
#include "Student.h"  // Include the Student header file

using namespace std;  // Use the standard namespace

int main() {
    cout << "\nThis program creates an object of class Student, and calls all the methods implemented for Class Student and all the methods that it inherited from Class Person.\n" << endl;  // Output program description
    cout << "Programmed by: Jodell Mae P. Adlaon\n" << endl;    // Output programmer's name

    string fname, lname, gender, studentNum, course, department, college, email, cpNumber;  // Declare variables of type string

    cout << "Student's First Name: ";  // Prompt for first name
    cin >> fname;                      // Read first name

    cout << "Student's Last Name: ";  // Prompt for last name
    cin >> lname;                     // Read last name

    cout << "Student's Gender: ";  // Prompt for gender
    cin >> gender;                 // Read gender

    cout << "Student Number: ";  // Prompt for student number
    cin >> studentNum;           // Read student number

    cout << "Course: ";     // Prompt for course
    cin.ignore();           // Ignore newline character left in buffer
    getline(cin, course);   // Read course

    cout << "Department: ";     // Prompt for department
    getline(cin, department);   // Read department

    cout << "College: ";    // Prompt for college
    getline(cin, college);  // Read college

    cout << "Email Address: ";  // Prompt for email address
    cin >> email;               // Read email address

    cout << "Phone Number: ";  // Prompt for phone number
    cin >> cpNumber;           // Read phone number

    // Create Student object with input values
    Student student(fname, lname, gender, email, cpNumber, studentNum, course, department, college);

    cout << "\n----------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

    // Output the student's details
    cout << "Hi, " << student.getFname() << " " << student.getLname() << "! Welcome to UP Mindanao and congratulations! "
         << "We are pleased to inform you that you are admitted in the " << student.getCourse() << " program under the Department of "
         << student.getDepartment() << ", College of " << student.getCollege() << ". Your Student number is " << student.getStudentNum() << "."
         << " Your email address is " << student.getEmailAdd() << " and your phone number is " << student.getCpNumber() << "." << endl;

    return 0;  // Return 0 to indicate successful execution
}