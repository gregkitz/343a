#ifndef _Customer_H
#define _Customer_H
using namespace std; 
#include <string> 
#include "command.h"
#include <list> 

class Customer{

	friend ostream& operator<<(ostream& output, const Customer& cust);
	
public:
	Customer();
	list<Command*> history;
	~Customer(); 
	Customer(string,string,int);  //all-parameter constructor
	void PrintCustomer(); 
	int returnID(){
		return id; 
	}
	void insertCommand(Command* theCommand){
		history.push_back(theCommand); 
	}
	int id;
private:
	string firstName; 
	string lastName; 
	
	
};




#endif