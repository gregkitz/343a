using namespace std; 
#include "customer.h" 
#include "hashtable.h"
#include <iostream> 
const int HASHSIZE = 200; 
HashTable::HashTable(){
	//hashTable = new Customer* [HASHSIZE]; //declare the array for the hash 
    inserted = 0; 
    initializeHash(); 
    
}
HashTable::~HashTable(){
	/*for (int i = 0; i < HASHSIZE; i++){
    	delete hashTable[i]; // call delete on each pointer 'cause [] didn't work
    }*/
}
void HashTable::printHash(){          //doesn't work - might not need 
for (int i = 0; i < HASHSIZE; i++){
    	if(hashTable[i] != NULL)
    	cout << *hashTable[i] << endl; 
    }

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

void HashTable::insertCommand(int customerNumber, Command* theCommand){
	//find the customer 
	for (int i = 0; i < 200; i++){
		if (hashTable[i]->returnID() == customerNumber){
			hashTable[i]->insertCommand(theCommand);
		}
	}

}

void HashTable::printHistory(int customerNumber) {
	std::list<Command*>::const_iterator iterator;
	for (int i = 0; i < 200; i++){
		if (hashTable[i] != NULL )
		if (hashTable[i]->id == customerNumber){
			for (iterator = hashTable[i]->history.begin(); iterator != hashTable[i]->history.end(); ++iterator) {
				cout << *iterator;
				
			}
		}
	}

}


bool HashTable::insert(Customer* customer){ 
    hashTable[inserted] = customer; 
    inserted++; 
    return true; 

}