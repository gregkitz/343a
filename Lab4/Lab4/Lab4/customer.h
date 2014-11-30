#ifndef _Customer_H
#define _Customer_H
using namespace std; 
#include <string> 

class Customer{

	friend ostream& operator<<(ostream& output, const Customer& cust);
	
public:
	Customer(); 
	~Customer(); 
	Customer(string,string,int);  //all-parameter constructor
	void PrintCustomer(); 

private:
	string firstName; 
	string lastName; 
	int id; 
};




#endif