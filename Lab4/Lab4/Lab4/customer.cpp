using namespace std; 
#include <string> 
#include "customer.h"
#include <iostream>

ostream& operator<<(ostream & output, const Customer & customer){
	output << customer.firstName << customer.lastName << customer.id << endl;
	return output; 
}


Customer::Customer(){
	firstName = "";
	lastName = "";
	id = 0000;
}
	Customer::~Customer(){
		
         

	}
	Customer::Customer(string firstNameP,string lastNameP,int idP){
        firstName = firstNameP; 
        lastName = lastNameP; 
        id = idP; 

	}  //all-parameter constructor


	void Customer::PrintCustomer(){   ///testing function 
       cout << firstName << endl; 

	}
