// CMSC 28 (K-1L)
// Submitted by: Jodell Mae P. Adlaon

#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>
#include "Person.h"

using namespace std;

// The Movie class represents a movie with a title, synopsis, MPAA rating, genres, directors, and actors.
class Movie {
private:
    string title;               // Title of the movie
    string synopsis;            // Synopsis of the movie
    string mpaa_rating;         // MPAA rating of the movie
    vector<string> genres;      // List of genres of the movie
    vector<Person> directors;   // List of directors of the movie
    vector<Person> actors;      // List of actors of the movie

public:
    // Setter for the title
    void setTitle(const string& t);

    // Setter for the synopsis
    void setSynopsis(const string& s);

    // Setter for the MPAA rating
    void setMPAARating(const string& rating);

    // Add a genre to the list of genres
    void addGenre(const string& g);

    // Add a director to the list of directors
    void addDirector(const Person& d);

    // Add an actor to the list of actors
    void addActor(const Person& a);

    // Getter for the title
    string getTitle() const;

    // Getter for the synopsis
    string getSynopsis() const;

    // Getter for the MPAA rating
    string getMPAARating() const;

    // Getter for the list of genres
    vector<string> getGenres() const;

    // Getter for the list of directors
    vector<Person> getDirectors() const;

    // Getter for the list of actors
    vector<Person> getActors() const;
};

#endif
