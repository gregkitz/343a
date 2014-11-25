#include "customers.h"
#include <fstream>
#include <iostream>

using namespace std; 
Customers::Customers(){
	
}


bool Customers::initializeCustomers(const ifstream& inFile){

	return true;
}
 Customer*  createCustomer(string first,string last ,int age){
 	
 	return new Customer(first,last,age); 
 }

	