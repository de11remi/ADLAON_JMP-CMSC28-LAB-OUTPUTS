// CMSC 28 (K-1L)

#include <iostream>     // Include necessary header for input/output operations
#include "Book.h"       // Include the header file for the Book class
using namespace std;    // Use the std namespace for standard library functions

int main() {
    cout << "This is a C++ program with an instance/ object of class Book within the main function, tests and uses all of the defined methods and constructors.\n";
    cout << "Submitted by: Jodell Mae P. Adlaon\n\n";

    // Create an instance of the Book class using the constructor
    Book myBook("1984", "George Orwell", "978-0451518002");
    
    // Testing getter methods
    cout << "Title: " << myBook.getTitle() << endl;    // Print the title of the book
    cout << "Author: " << myBook.getAuthor() << endl;  // Print the author of the book
    cout << "ISBN: " << myBook.getISBN() << endl;      // Print the ISBN of the book
    
    // Testing setter methods
    myBook.setTitle("The Picture of Dorian Gray");  // Set a new title for the book
    myBook.setAuthor("Oscar Wilde");                // Set a new author for the book
    myBook.setISBN("978-1515190998");               // Set a new ISBN for the book
    myBook.setPublisher("Ward, Lock and Company");  // Set a publisher for the book
    
    // Testing getter methods again to ensure changes were applied
    cout << "\nTitle: " << myBook.getTitle() << endl;       // Print the updated title
    cout << "Author: " << myBook.getAuthor() << endl;       // Print the updated author
    cout << "ISBN: " << myBook.getISBN() << endl;           // Print the updated ISBN
    cout << "Publisher: " << myBook.getPublisher() << endl; // Print the publisher

    return 0; // Indicate successful completion of the program
}

