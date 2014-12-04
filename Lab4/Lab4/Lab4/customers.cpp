#include "customers.h"

#include <fstream>
#include <iostream>

using namespace std; 
Customers::Customers(){
	
}
Customers::~Customers(){


}

bool Customers::initializeCustomers(ifstream& infile){
//ifstream infile ("data4customers.txt");  //declaring this here for testing purposes 
if (!infile) {
cout << "File could not be opened." << endl;
return 1;    //1 is failure condition 
}
	while (!infile.eof()){
		int id = 0; 
		infile >> id; 
		string lastName; 
		infile >> lastName; 
		string firstName;
		infile >> firstName; 

		Customer * tempCust = createCustomer(firstName,lastName,id);

		hashTable.insert(tempCust); 

		
		
	}

		//hashTable.clearHash(); 

	return true;
}
 Customer*  Customers::createCustomer(string first,string last ,int id){
 	
 	return new Customer(first,last,id); 
 }

 void Customers::printCustomers(){
 	hashTable.printHash(); 
 }

	