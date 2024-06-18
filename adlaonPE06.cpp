#include <iostream>
#include <vector>    // Include this header for storing lists of genres, directors, and actors for a movie
#include <limits>    // Include this header for numeric_limits
#include "Movie.h"
#include "Person.h"

using namespace std;

// Definition of Person class methods
// Set the first name of the person
void Person::setFirstName(const string& fn) {
    fname = fn;
}

// Set the last name of the person
void Person::setLastName(const string& ln) {
    lname = ln;
}

// Set the gender of the person
void Person::setGender(const string& g) {
    gender = g;
}

// Get the first name of the person
string Person::getFirstName() const {
    return fname;
}

// Get the last name of the person
string Person::getLastName() const {
    return lname;
}

// Get the gender of the person
string Person::getGender() const {
    return gender;
}

// Definition of Movie class methods
// Set the title of the movie
void Movie::setTitle(const string& t) {
    title = t;
}

// Set the synopsis of the movie
void Movie::setSynopsis(const string& s) {
    synopsis = s;
}

// Set the MPAA rating of the movie
void Movie::setMPAARating(const string& rating) {
    mpaa_rating = rating;
}

// Add a genre to the movie's list of genres
void Movie::addGenre(const string& g) {
    genres.push_back(g);
}

// Add a director to the movie's list of directors
void Movie::addDirector(const Person& d) {
    directors.push_back(d);
}

// Add an actor to the movie's list of actors
void Movie::addActor(const Person& a) {
    actors.push_back(a);
}

// Get the title of the movie
string Movie::getTitle() const {
    return title;
}

// Get the synopsis of the movie
string Movie::getSynopsis() const {
    return synopsis;
}

// Get the MPAA rating of the movie
string Movie::getMPAARating() const {
    return mpaa_rating;
}

// Get the list of genres of the movie
vector<string> Movie::getGenres() const {
    return genres;
}

// Get the list of directors of the movie
vector<Person> Movie::getDirectors() const {
    return directors;
}

// Get the list of actors of the movie
vector<Person> Movie::getActors() const {
    return actors;
}

// Main function to collect and display movie details
int main() {
    string input;                   // Variable to hold user input
    string fname, lname, gender;    // Variables to hold director/actor details
    char addMore;                   // Variable to determine if more entries are to be added

    Movie movie; // Create a Movie object

    // Program description and programmer's name
    cout << "\nThis program will collect and display movie details.\n";
    cout << "Programmed by: Jodell Mae P. Adlaon\n\n\n";

    // Input movie title
    cout << "Enter Movie Title: ";
    getline(cin, input);
    movie.setTitle(input);

    // Input movie synopsis
    cout << "\nEnter Synopsis: ";
    getline(cin, input);
    movie.setSynopsis(input);

    // Input movie MPAA rating
    cout << "\nWhat is its MPAA Rating: ";
    getline(cin, input);
    movie.setMPAARating(input);

    // Input movie genres in a loop
    do {
        cout << "\nEnter a Genre: ";
        getline(cin, input);
        movie.addGenre(input);

        cout << "Add another genre? (y/n): ";
        cin >> addMore;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Ignore leftover newline
    } while (addMore == 'y' || addMore == 'Y');

    // Input movie directors in a loop
    do {
        Person director;    // Create a Person object for the director

        // Input director's first name
        cout << "\nEnter Director's First Name: ";
        getline(cin, fname);
        director.setFirstName(fname);

        // Input director's last name
        cout << "Enter Director's Last Name: ";
        getline(cin, lname);
        director.setLastName(lname);

        // Input director's gender
        cout << "Enter Director's Gender: ";
        getline(cin, gender);
        director.setGender(gender);

        // Add the director to the movie
        movie.addDirector(director);

        cout << "\nAdd another director? (y/n): ";
        cin >> addMore;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Ignore leftover newline
    } while (addMore == 'y' || addMore == 'Y');

    // Input movie actors in a loop
    do {
        Person actor;   // Create a Person object for the actor

        // Input actor's first name
        cout << "\nEnter Actor/Actress's First Name: ";
        getline(cin, fname);
        actor.setFirstName(fname);

        // Input actor's last name
        cout << "Enter Actor/Actress's Last Name: ";
        getline(cin, lname);
        actor.setLastName(lname);

        // Input actor's gender
        cout << "Enter Actor/Actress's Gender: ";
        getline(cin, gender);
        actor.setGender(gender);

        // Add the actor to the movie
        movie.addActor(actor);

        cout << "\nAdd another actor? (y/n): ";
        cin >> addMore;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Ignore leftover newline
    } while (addMore == 'y' || addMore == 'Y');

    // Display collected movie details
    cout << "\n-------------------------------------------------------------\n";
    cout << "MOVIE DETAILS\n\n";
    cout << "Movie Title: " << movie.getTitle() << "\n\n";
    cout << "Synopsis: " << movie.getSynopsis() << "\n\n";
    cout << "MPAA Rating: " << movie.getMPAARating() << "\n\n";

    cout << "Genre/s:\n";
    for (const auto& genre : movie.getGenres()) {
        cout << genre << "\n";  // Display each genre
    }
    cout << "\n";

    cout << "Director/s:\n";
    for (const auto& director : movie.getDirectors()) {
        cout << director.getFirstName() << " " << director.getLastName() << "\n";   // Display each director's name
    }
    cout << "\n";

    cout << "Actor/s:\n";
    for (const auto& actor : movie.getActors()) {
        cout << actor.getFirstName() << " " << actor.getLastName() << "\n";     // Display each actor's name
    }
    cout << "\n";

    return 0; // End of the program
}
