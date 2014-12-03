//Manager class
//Contains three BST's for movies, a hash table for customers, and a queue of commands 

#ifndef _RENTALSTORE_H
#define _RENTALSTORE_H
#include "customers.h"
#include "comedy.h"
#include "drama.h"
#include "classics.h"
#include "bintree.h"
#include <iostream> 
#include <fstream> 
#include <cstring> 
#include <string> 
#include <cstdlib>

using namespace std; 

class RentalStore{
public: 
	RentalStore(); 
	~RentalStore(); 
	bool initializeCustomers();
    void processMovies(ifstream&); // builds movies from a file and puts them in the hash table 
    Comedy* createComedy(string, string, string, string); 
    Drama* createDrama(string, string, string, string); 
    Classic* createClassic(string, string, string, string); 
    
	BinTree* dramaTree;
	BinTree* comedyTree;
	BinTree* classicTree;


private: 
	//Customers theCustomers; 
    


};




#endif