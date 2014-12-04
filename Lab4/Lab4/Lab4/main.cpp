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
		ifstream commandsFile("data4commands.txt");
		//Customer bob(); 
	
		
		
		RentalStore bob; 
		bob.theCustomers.initializeCustomers(customerFile);
		bob.processMovies(moviesFile);  
		bob.classicTree->printTreePreOrder(); 
		bob.comedyTree->printTreePreOrder(); 
		bob.dramaTree->printTreePreOrder(); 
		//sally.printCustomers(); 
		bob.loadCommands(commandsFile); 
		//bob.runCommands(); 


	return 0; 
}
