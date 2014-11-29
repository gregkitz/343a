#ifndef _CUSTOMERS_H
#define _CUSTOMERS_H
#include "customer.h"
#include <fstream>
#include <string> 

class Customers{
 

public:
    Customers(); 


	bool initializeCustomers( ifstream&  );   //takes the infile and creates new customers w/ it 


private:
	
    Customer*  createCustomer(string,string,int); // customer generator 
    
    Customer** hashTable; 

};




#endif