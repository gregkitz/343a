using namespace std; 
#include "customer.h"
#include "customers.h"

#include <iostream> 

int main() { 
		ifstream customerFile ("data4customers.txt");

		Customer bob(); 
		Customers sally; 
		sally.initializeCustomers(customerFile); 

	return 0; 
}