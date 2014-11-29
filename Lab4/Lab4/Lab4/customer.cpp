using namespace std; 
#include <string> 
#include "customer.h"
#include <iostream>

	Customer::Customer(){


	}
	Customer::~Customer(){
		cout << "meow" << endl; 
         delete this; 

	}
	Customer::Customer(string firstNameP,string lastNameP,int idP){
        firstName = firstNameP; 
        lastName = lastNameP; 
        id = idP; 

	}  //all-parameter constructor


	void Customer::PrintCustomer(){   ///testing function 
       cout << firstName << endl; 

	}
