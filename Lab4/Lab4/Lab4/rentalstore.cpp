#include "rentalstore.h"
#include <iostream> 
#include <fstream> 
#include <cstring> 
#include <string> 
#include <cstdlib>
using namespace std; 

 void RentalStore::processMovies(ifstream& infile){
	//try and open the file 
	if (!infile) {
	cout << "File could not be opened." << endl;
	return 1;    //1 is failure condition 
	}
	else {
		while (!infile.eof()){
				//if it can, read the first character to see what type to be processed
				string type; 
				getline (infile,type, ',');   
				if (strcmp(type.c_str(), "F") == 0){
					string tempInt; 
					getline (infile,tempInt, ',');
 					
					int count = atoi (tempInt.c_str()); 
					
					string director;
					getline (infile,director,' ');    
					string title; 
					getline (infile,title,',');
					int year;
					 infile >> year; 

					     //////TESTING BLOCK 

							cout << count << director << title << year << endl; 


					    ////END TESTING BLOCK 


					//Comedy* tempComedy = createComedy(count, director, title, year); //create it 
					//comedyTree.insert(tempComedy); //insert it into the comedy BST
				}

				else if (strcmp(type.c_str(), "D") == 0){
					string tempInt; 
					getline (infile,tempInt, ',');
 
					int count = atoi (tempInt.c_str()); 
					string director;
					getline (infile,director,' ');    
					string title; 
					getline (infile,title,',');
					int year;
					infile >> year; 

								cout << count << director << title << year << endl; 

					//Drama* tempDrama = createDrama(count, director, title, year);
					//dramaTree.insert(tempDrama); 
				}

				else if (strcmp(type.c_str(), "C") == 0){
					string tempInt; 
					getline (infile,tempInt, ',');
 
					int count = atoi (tempInt.c_str());  
					string director;
					getline (infile,director,' ');    
					string title; 
					getline (infile,title,',');
					string majorActorFirst; 
					string majorActorLast; 
					infile >> majorActorFirst; 
					infile >> majorActorLast; 
					int yearMonth; 
					int year;
					infile >> yearMonth; 
					infile >> year;

							cout << count << director << title << majorActorFirst << majorActorLast << yearMonth << year << endl; 

					//Classic* tempClassic = createClassic(count, director, title, majorActorFirst, majorActorLast, yearMonth, year);
					//classicTree.insert(tempClassic); 
				}

					//else condition handles invalid data 
				else {
						cout << "Invalid data!" << endl; 
						string error; 
						std::getline(infile,error); //should move read the next line of the file 
						cout << error << endl; 
				}
		}
	}
}

/*Comedy* RentalStore::createComedy(int, string, string, int){

}
Drama* RentalStore::createDrama(int, string, string, int){

}
Classic* RentalStore::createClassic(int, string, string, string, string, int, int){

}*/
