#include "customers.h"
#include <fstream>
#include <iostream>

using namespace std; 
Customers::Customers(){
	
}


bool Customers::initializeCustomers(ifstream& infile){
//ifstream infile ("data4customers.txt");  //declaring this here for testing purposes 

	while (!infile.eof()){
		int id = 0; 
		infile >> id; 
		string lastName; 
		infile >> lastName; 
		string firstName;
		infile >> firstName; 

		Customer * tempCust = createCustomer(firstName,lastName,id);

		tempCust->PrintCustomer(); 

		//cout << id << lastName << firstName << endl; 
		
	}

	

	return true;
}
 Customer*  Customers::createCustomer(string first,string last ,int id){
 	
 	return new Customer(first,last,id); 
 }

	