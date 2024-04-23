#include "system.h"


/*************************************************************************
                            Movie class
**************************************************************************/

Movie::Movie(){
    movie_name = default_name;
    seats_available = default_seats;
    ticket_price = default_price;
};


Movie::Movie(const string& name, const int& seats, const double& price){
    this->movie_name = name;
    this->seats_available = seats;
    this->ticket_price = price;
};


Movie::~Movie(){
    if (debug == true){
        cout << "Movie "<< movie_name << " is no longer showing ..." <<endl;
    }
    // there is no class or dynamically allocated objects and other required.
    // so do nothing
};

void Movie::set_name(const string& newName){
    movie_name = newName;
};
void Movie::set_seats(const int& newSeats){
    seats_available = newSeats;
};
void Movie::set_price(const double& newPrice){
    ticket_price = newPrice;
};
const string Movie::get_name() const{
    return movie_name;
};
const int Movie::get_seats() const{
    return seats_available;
};
const double Movie::get_price() const{
    return ticket_price;
};


double Movie::PurchaseTicket(int NumberOfTicket){
    if (NumberOfTicket > seats_available){                                      
        return -1;
    }
    seats_available -= NumberOfTicket;
    return NumberOfTicket * ticket_price;
}; 



void Movie::Display(){
    cout<<  "********************************************************\n"
            "*"<< setw (25) << "Movie Name: " << movie_name << "*\n"
            "*"<< setw (25) << "Seats Available" << seats_available <<"*\n"
            "*"<< setw (25) << "Ticket Price" << ticket_price <<"*\n"<< endl;

};                                       





/*************************************************************************
                    MovieTicketMaster  class
**************************************************************************/



//CTORs
MovieTicketMaster::MovieTicketMaster(){
    theater_name = default_theater_name;
    theater_location = default_theater_location;
    movie_count = default_movie_count;
    movie_list = nullptr;
};

MovieTicketMaster::MovieTicketMaster(string name, string location, int count){
    this->theater_name = name;
    this->theater_location = location;
    this->movie_count = count;
    this->movie_list = nullptr;
};


MovieTicketMaster::~MovieTicketMaster(){
    deallocated(movie_list);
};
// accessor&mutators
void MovieTicketMaster::set_name(const string& newName){
    theater_name = newName;
};
void MovieTicketMaster::set_location(const string& newLocation){
    theater_location = newLocation;
};
void MovieTicketMaster::set_count(const int& newCount){
    movie_count = newCount;
};
const string MovieTicketMaster::get_name()const{
    return theater_name;
};
const string MovieTicketMaster::get_location()const{
    return theater_location;
};
const int MovieTicketMaster::get_count()const{
    return movie_count;
};

// debug function 
void MovieTicketMaster::Init(){
    const int kSize = 8;
    string  movie_name_list [kSize ]  =  {  
        "Black Mass", 
        "The Visit", 
        "Mission: Impossible - Rogue Nation", 
        "Straight Outta Compton",
        "No Escape",
        "Maze Runner: Scorch Trials",
        "Everest",
        "Wars"
    };
    int seat_list[kSize] = {
        6, 
        3, 
        4, 
        7,
        9,
        5,
        2,
        8
    };
    
    double price_list[kSize] = {
        14.25, 
        17.50, 
        11.75, 
        15.50,
        16.75,
        13.25,
        17.25,
        14.25        
    };
    movie_list = allocated<Movie>(kSize-1);
    string* p_movie_name_list = movie_name_list;
    int* p_seat_list = seat_list;
    double* p_price_list = price_list;
    Movie* p_movie = movie_list;
    for (int i = 0; i < kSize;i++){
        p_movie->set_name(*p_movie_name_list);
        p_movie->set_seats(*p_seat_list);
        p_movie->set_price(*price_list);
        p_movie++;
        p_movie_name_list++;
        p_seat_list++;
        p_price_list++;
    }
}


void MovieTicketMaster::Run(){
    char option;
    string name;
    Menu();
    cin >> option;
    switch(option){
        case '1':
            ViewShowingMovies();
        break;
        case '2':
            getline(cin, name);
            SearchMovie(name);
        break;
        case '3':
            getline(cin, name);
            SearchMovie(name);
            PurchaseTicket(name);
        break;
        case '4':
            // do nothing
        break;
        default:
            cout << "????" << endl;
        break;
    }
};


// functions
void MovieTicketMaster::Menu(){
    cout << "MOVIE TICKET MASTER" << endl;
    cout << "Theater:" << theater_name <<" at "<< theater_location <<"\n",
              // some theater advertising banner of your own: This is required!!!
    cout << "  [1]  View all showing movies" << endl;
    cout << "  [2] Search a movie" << endl;
    cout << "  [3]  Purchase a ticket" << endl;
    cout << "  [4]  Quit" << endl;
};

void MovieTicketMaster::ViewShowingMovies(){
    Movie* p_movie = movie_list;
    int c = 0;
    while (p_movie != nullptr){
        p_movie->Display();
        p_movie++;
    }
};

void MovieTicketMaster::SearchMovie(const string & name){
    Movie* p_movie = FindMovie(name);
    if (p_movie == nullptr){
        cout <<"error message"<<endl;
    }
    p_movie->Display();
};

Movie* MovieTicketMaster::FindMovie(const string & name){
    Movie* p_movie = movie_list;
    while (p_movie != nullptr){
        if(*p_movie == name){return p_movie;}
        p_movie++;
    }    
    return nullptr;
};

void MovieTicketMaster::PurchaseTicket(const string & name){
    Movie* p_movie = FindMovie(name);
    int number;
    if (p_movie == nullptr){
        cout <<"error message"<<endl;
    }
    p_movie->Display();
    cout << "Number of tickets" <<endl;
    cin >> number;
    p_movie->PurchaseTicket(number);
    if (p_movie->get_seats() == 0){
        movie_count--;
    }
};

