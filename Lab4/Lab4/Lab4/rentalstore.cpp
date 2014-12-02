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
	//return 1;    //1 is failure condition 
	}
	else {
		while (!infile.eof()){
			string type; 

			getline(infile, type, ',');
					
			//cout << type << "hi" << endl; 

			if (strcmp(type.c_str(), "F") == 0) {
			
					string count; 
					string director; 
					string title; 
					string year; 
					
					
					
					getline(infile, count, ',');
					getline(infile, director, ',');
					getline(infile, title, ',');
					getline(infile, year);


					cout << type << count << director << title << year << endl; 

					//Comedy* tempComedy = createComedy(count, director, title, year); //create it 
					//comedyTree.insert(tempComedy); //insert it into the comedy BST
				}
			else if (strcmp(type.c_str(), "D") == 0){
				string count;
				string director;
				string title;
				string year;



				getline(infile, count, ',');
				getline(infile, director, ',');
				getline(infile, title, ',');
				getline(infile, year);


				cout << type << count << director << title << year << endl;
			
				//Comedy* tempDrama = createComedy(count, director, title, year); //create it 
				//dramaTree.insert(tempDrama); //insert it into the comedy BST
			}
			else if (strcmp(type.c_str(), "C") == 0){
				string count;
				string director;
				string title;
				string year;



				getline(infile, count, ',');
				getline(infile, director, ',');
				getline(infile, title, ',');
				getline(infile, year);


				cout << type << count << director << title << year << endl;
			
				//Classic* tempComedy = createClassic(count, director, title, year); //create it 
				//classicTree.insert(tempClassic); //insert it into the comedy BST
			}
				
				else {
					cout << "Invalid data: ";
						string error; 
						getline(infile,error); //should move read the next line of the file 
						cout << type << error << endl; 
				}
		}
	}
}

/*Comedy* RentalStore::createComedy(string, string, string, string){

}
Drama* RentalStore::createDrama(string, string, string, string){

}
Classic* RentalStore::createClassic(string, string, string, string){

}*/
