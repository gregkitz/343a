#ifndef _CUSTOMERS_H
#define _CUSTOMERS_H
#include "customer.h"
#include <fstream>
class Customers{
public:
	bool initializeCustomers(const ifstream&  );   //takes the infile and creates new customers w/ it 


private:
	Customers(); 
    Customer*  createCustomer(string,string,int); // customer generator 
    ifstream* stream; 


};




#endif