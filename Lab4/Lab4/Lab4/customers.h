#ifndef _CUSTOMERS_H
#define _CUSTOMERS_H
#include "customer.h"
#include "hashtable.h" 
#include <fstream>
#include <string> 

using namespace std; 

class Customers{
 

public:
    Customers(); 
    void printCustomers(); //calls the hash table print function 
	~Customers(); 
	bool initializeCustomers( ifstream&  );   //takes the infile and creates new customers w/ it 


private:
	
    Customer*  createCustomer(string,string,int); // customer generator 
    HashTable hashTable; 

};




#endif