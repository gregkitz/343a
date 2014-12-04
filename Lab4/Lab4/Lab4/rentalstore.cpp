#include "rentalstore.h"
#include "comedy.h"
#include "drama.h"
#include "classics.h"
#include "command.h"
#include "bintree.h"
#include "borrow.h"
#include <iostream> 
#include <fstream> 
#include <cstring> 
#include <string> 
#include <cstdlib>
#include <stdlib.h> 
using namespace std; 
RentalStore::RentalStore(){
	comedyTree = new BinTree();
	dramaTree = new BinTree();
	classicTree = new BinTree();
}

RentalStore::~RentalStore(){
	delete comedyTree; 
	delete dramaTree;
	delete classicTree; 
}


void RentalStore::loadCommands(ifstream& infile){
	if (!infile) {
		cout << "File could not be opened." << endl;
		
	}
	else {
		while (!infile.eof()){
			char type;
			int custID; 
			int releaseMonth; 
			int releaseYear; 
			string year; 
			string actFirst; 
			string actLast; 
			string directorName; 
			string title; 
			string mainActor; 
			char mediaType; 
			char movieType; 
			
			infile >> type;

			if (type == 'B' || type == 'R'){
				
				infile >> custID; 
				infile >> mediaType; 
				infile >> movieType; 


				if (movieType == 'C'){
					infile >> releaseMonth; 
					infile >> releaseYear; 
					infile >> actFirst; 
					infile >> actLast; 
					
					Borrow* tempBorrow = createClassic(type, releaseMonth, releaseYear, actFirst, actLast);
					theCommands.push(tempBorrow); 


				}

				else if (movieType == 'F'){
					getline(infile,directorName,','); 
					getline(infile, year);
					int yearInsert = atoi(year.c_str());
					
					Borrow* tempBorrow = createComedy(type, directorName, yearInsert);
					theCommands.push(tempBorrow);
				}
				else if (movieType == 'D'){
					getline(infile, mainActor, ',');
					getline(infile, title, ',');
					
					Borrow* tempBorrow = createDrama(type, mainActor, title);
					theCommands.push(tempBorrow);
				}
				else {
					cout << "We don't have that type of movie." << endl; 
				}
				//create borrow obj 
				//insert borrow into queue

			}
			
			else if (type == 'I'){
				string dope; 
				getline(infile, dope); 
				Inventory* tempInventory = createInventory(type);
				theCommands.push(tempInventory);
			}
			else if (type == 'H'){
				int customerNumberHistory; 
				infile >> customerNumberHistory; 
				History* tempHistory = createHistory(type, customerNumberHistory);
				theCommands.push(tempHistory);


			}
			else {
				string pushBuffer; 
				getline(infile, pushBuffer); 
				cout << "Command not recognized. " << endl;
			}



		}


	}

}

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

					Comedy* tempComedy = createComedy(count, director, title, year); //create it 
					comedyTree->insert(tempComedy); //insert it into the comedy BST
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
			
				Drama* tempDrama = createDrama(count, director, title, year); //create it 
				dramaTree->insert(tempDrama); //insert it into the comedy BST
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
			
				Classic* tempClassic = createClassic(count, director, title, year); //create it 
				classicTree->insert(tempClassic); //insert it into the comedy BST
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



Comedy* RentalStore::createComedy(string count, string director, string title, string year){
	
	return new Comedy(count, director, title, year);
	
}
Drama* RentalStore::createDrama(string count, string director, string title, string year){
	return new Drama(count, director, title, year);
		
}
Classic* RentalStore::createClassic(string count, string director, string title, string year){
	return new Classic(count, director, title, year);
	
}


Borrow* RentalStore::createClassic(char a, int b, int c, string d, string e){
	return new Borrow(a, b, c, d, e); 
}
Borrow* RentalStore::createComedy(char a, string b, int c){
	return new Borrow(a,b, c);
}
Borrow* RentalStore::createDrama(char a, string b, string c){
	return new Borrow(a, b, c);
}

History* RentalStore::createHistory(char type, int customerID){
	return new History(type, customerID); 
}

Inventory* RentalStore::createInventory(char type){
	return new Inventory(type);
}


