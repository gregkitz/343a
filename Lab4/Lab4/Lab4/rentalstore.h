//Manager class
//Contains three BST's for movies, a hash table for customers, and a queue of commands 

#ifndef _RENTALSTORE_H
#define _RENTALSTORE_H
#include "customers.h"
#include "comedy.h"
#include "drama.h"
#include "dvdmedia.h"
#include "classics.h"
#include "bintree.h"
#include "borrow.h"
#include "history.h"
#include "inentory.h"
#include "command.h"
#include <iostream> 
#include <fstream> 
#include <cstring> 
#include <string> 
#include <cstdlib>
#include <queue> 

using namespace std; 

class RentalStore{
public: 
	RentalStore(); 
	~RentalStore(); 
	bool initializeCustomers();
    void processMovies(ifstream&); // builds movies from a file and puts them in the hash table 
	void loadCommands(ifstream&); // builds commands from file and loads them into queue 
	void processCommands(); // pops command and processes it 
	void processBorrow(Command&); 
	void processReturn(Command&); 
	void runCommands(); 
	void processHistory(Command&); //helper functions for processing commands 

    Comedy* createComedy(string, string, string, string); 
    Drama* createDrama(string, string, string, string); 
    Classic* createClassic(string, string, string, string); 
    
	Borrow* createClassic(char, int, int, string, string);
	Borrow* createComedy(char, string, int);
	Borrow* createDrama(char, string, string);
	History* createHistory(char type, int customerID);
	Inventory* createInventory(char type);
	BinTree* dramaTree;
	BinTree* comedyTree;
	BinTree* classicTree;


private: 
	Customers theCustomers; 
	queue<Command*> theCommands; 
    


};




#endif
