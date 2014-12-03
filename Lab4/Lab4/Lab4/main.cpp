using namespace std; 
//#include "customer.h"
//#include "customers.h"
#include "rentalstore.h"
#include "bintree.h"
#include "dvdmedia.h"

#include <iostream> 

int main() { 
		ifstream customerFile ("data4customers.txt"); //customers infile 
		ifstream moviesFile ("data4movies.txt"); //movies infile 
		/*Customer bob(); 
		Customers sally; 
		sally.initializeCustomers(customerFile); */
		
		RentalStore bob; 
		bob.processMovies(moviesFile);  
		bob.classicTree->printTreePreOrder(); 
		bob.comedyTree->printTreePreOrder(); 
		bob.dramaTree->printTreePreOrder(); 



	return 0; 
}
