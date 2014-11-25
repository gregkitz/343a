#ifndef _Customer_H
#define _Customer_H
using namespace std; 
#include <string> 

class Customer{
public:
	Customer(); 
	Customer(string,string,int);  //all-parameter constructor


private:
	string firstName; 
	string lastName; 
	int id; 


};




#endif