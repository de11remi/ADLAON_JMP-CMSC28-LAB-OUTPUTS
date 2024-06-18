// CMSC 28 (K-1L)
// Submitted by: Jodell Mae P. Adlaon

#include <string>    // Include necessary header for string data type
using namespace std; // Use the std namespace for string

class Book {
private:
    string Title;       // Private member variable to store the title of the book
    string Author;      // Private member variable to store the author of the book
    string ISBN;        // Private member variable to store the ISBN of the book
    string Publisher;   // Private member variable to store the publisher of the book

public:
    // Constructor with parameters to initialize the Book object
    Book(string title, string author, string isbn);
    
    // Getter methods to retrieve the values of private member variables
    string getTitle();
    string getAuthor();
    string getISBN();
    string getPublisher();
    
    // Setter methods to modify the values of private member variables
    void setTitle(string bktitle);
    void setAuthor(string bkauthor);
    void setISBN(string bkisbn);
    void setPublisher(string bkpublisher);
};

// Implementation of the Book class constructor
Book::Book(string title, string author, string isbn) {
    Title = title;    // Initialize the title attribute with the provided title
    Author = author;  // Initialize the author attribute with the provided author
    ISBN = isbn;      // Initialize the ISBN attribute with the provided ISBN
}

// Implementation of the getTitle() method
string Book::getTitle() {
    return Title;     // Return the title of the book
}

// Implementation of the getAuthor() method
string Book::getAuthor() {
    return Author;    // Return the author of the book
}

// Implementation of the getISBN() method
string Book::getISBN() {
    return ISBN;      // Return the ISBN of the book
}

// Implementation of the getPublisher() method
string Book::getPublisher() {
    return Publisher; // Return the publisher of the book
}

// Implementation of the setTitle() method
void Book::setTitle(string bktitle) {
    Title = bktitle;  // Set a new title for the book
}

// Implementation of the setAuthor() method
void Book::setAuthor(string bkauthor) {
    Author = bkauthor; // Set a new author for the book
}

// Implementation of the setISBN() method
void Book::setISBN(string bkisbn) {
    ISBN = bkisbn;     // Set a new ISBN for the book
}

// Implementation of the setPublisher() method
void Book::setPublisher(string bkpublisher) {
    Publisher = bkpublisher; // Set a new publisher for the book
}

