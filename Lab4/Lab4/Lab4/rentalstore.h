//Manager class
//Contains three BST's for movies, a hash table for customers, and a queue of commands 

#ifndef _RENTALSTORE_H
#define _RENTALSTORE_H
//#include "customers.h"
//#include "comedy.h"
//#include "drama.h"
//#include "classics.h"
//#include "bintree.h"
#include <iostream> 
#include <fstream> 
#include <cstring> 
#include <string> 
#include <cstdlib>

using namespace std; 

class RentalStore{
public: 
	bool initializeCustomers();
    void processMovies(ifstream&); // builds movies from a file and puts them in the hash table 
    //Comedy* createComedy(int, string, string, int); 
    //Drama* createDrama(int, string, string, int); 
    //Classic* createClassic(int, string, string, string, string, string, int, int); 
    bool handleInvalidData(); // for unrecognized characters from the first thing read in 
private: 
	//Customers theCustomers; 
    // BinTree dramaTree; 
    // BinTree comedyTree; 
    //BinTree classicTree; 



};




#endif