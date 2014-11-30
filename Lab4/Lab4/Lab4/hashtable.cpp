using namespace std; 
#include "customer.h" 
#include "hashtable.h"
#include <iostream> 
int HASHSIZE = 200; 
HashTable::HashTable(){
	hashTable = new Customer* [HASHSIZE]; //declare the array for the hash 
    inserted = 0; 
    initializeHash(); 
    
}
HashTable::~HashTable(){
	delete [] hashTable; 
}

void HashTable::initializeHash(){
    for (int i = 0; i < HASHSIZE; i++){
    	hashTable[i] = NULL; //nulls out pointers 
    }

}

void HashTable::clearHash(){
	for (int i = 0; i < 200; i++){
	    	delete hashTable[i];  //nulls out pointers 
	    }

}


bool HashTable::insert(Customer* customer){ 
    hashTable[inserted] = customer; 
    inserted++; 
    return true; 

}