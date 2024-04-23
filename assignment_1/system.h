#ifndef SYSTEM_H
#define SYSTEM_H


#include <iostream>
#include <string>
#include <iomanip>
#include "utilities.h"
using namespace std;


// for debugging
const bool debug = false;

// default variables
const string default_name = "Mystery Movie";
const int default_seats = 100;
const double default_price = 14.99;

class Movie {

    public:
        // 3 CTORs
        // Movie():movie_name(default_name), seats_available(default_seats), ticket_price(default_price){};
        // Movie(const string& name, const int& seats, const double& price):movie_name(name), seats_available(seats), ticket_price(price){};
        // ~Movie(){};
        Movie();
        Movie(const string& name, const int& seats, const double& price);
        ~Movie();

        // operator
        bool operator== (const string& object){                 // movie class compare string class overload operator
            if (object == this->movie_name){return true;}
            return false;
        }

        Movie operator= (const Movie& rhs){
            if (this == &rhs)
                return *this;
            movie_name = rhs.movie_name;
            seats_available = rhs.seats_available;
            ticket_price = rhs.ticket_price;
            return *this;
        }

        // functions
        void set_name(const string& newName);                   //mutators&accessors
        void set_seats(const int& newSeats);
        void set_price(const double& newPrice);
        const string get_name() const;                          
        const int get_seats() const;
        const double get_price() const;

        double PurchaseTicket(int NumberOfTicket);              // take an integer (number of tickets requested) and return the total cost.
        void Display();                                         // display all information about the movie.

    private:
        string movie_name;
        int seats_available;
        double ticket_price;

};




//defult variables 
const int array_size = 32;
const int default_movie_count = 0;
const string default_theater_name = "AMC";
const string default_theater_location = "My City";


class MovieTicketMaster{

    public:
        //CTORs
        MovieTicketMaster();
        MovieTicketMaster(string name, string location, int count);
        ~MovieTicketMaster();


        MovieTicketMaster operator= (const MovieTicketMaster& rhs){
            if (this == &rhs)
                return *this;
            theater_name = rhs.theater_name;
            theater_location = rhs.theater_location;
            movie_count = rhs.movie_count;
            deallocated(movie_list);
            this->movie_list = allocated(rhs.movie_list,rhs.movie_count);
            return *this;
        }
        

        // accessor&mutators
        void set_name(const string& newName);
        void set_location(const string& newLocation);
        void set_count(const int& newCount);
        const string get_name()const;
        const string get_location()const;
        const int get_count()const;
      
        // debug function 
        void Init();
        void Run();

    private:
        string theater_name;
        string theater_location;
        int movie_count;                                        // relative to seats available ......
        Movie *movie_list;

        // functions
        void Menu();
        void ViewShowingMovies();
        void SearchMovie(const string & name);
        Movie* FindMovie(const string & name);
        void PurchaseTicket(const string & name);
       
};


#endif