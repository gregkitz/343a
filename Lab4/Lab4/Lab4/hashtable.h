#ifndef _HASHTABLE_H
#define _HASHTABLE_H
#include "customer.h"

//global variables!!
	
class HashTable{
	public:
		HashTable(); //default constructor 
		~HashTable(); //destructor 
		HashTable(int); //size the array based on int 
		void printHash(); //prints out all the customers in the hash table 
		void initializeHash(); //set all pointers to null
		void clearHash(); //deletes all pointers in table 
		bool insert(Customer*); //hashes a customer and inserts 
		bool poke(Customer*); //poking algorithm 


	private:
	   Customer* hashTable [200]; 	
       int inserted; 


};




#endif