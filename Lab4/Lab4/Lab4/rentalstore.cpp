#include "rentalstore.h"
#include <iostream> 
#include <fstream> 
using namespace std; 

bool RentalStore::processMovies(ifstream& infile){
	//try and open the file 
	if (!infile) {
	cout << "File could not be opened." << endl;
	return 1;    //1 is failure condition 
	}
	//if it can, read the first character to see what type to be processed
	char type; 
	infile >> type;    // might read into strings and do strcmp instead..
	if (type == 'F'){
		Comedy * tempComedy = createComedy(int, string, string, string, int); //create it 
				//insert it into the comedy BST
	}

	else if (type == 'D'){
		Drama* tempDrama = createDrama(int, string, string, string, int); 
	}

	else if (type == 'C'){
		Classic* tempClassic = createClassic(int, string, string, string, string, string, int, int);

	}

		//else condition handles invalid data 
	else {

	}

}

Comedy* RentalStore::createComedy(int, string, string, string, int){

}
Drama* RentalStore::createDrama(int, string, string, string, int){

}
Classic* RentalStore::createClassic(int, string, string, string, string, string, int, int){

}