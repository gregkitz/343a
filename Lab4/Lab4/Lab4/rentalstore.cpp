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
	else {
		while (!infile.eof()){
				//if it can, read the first character to see what type to be processed
				string type; 
				getline (infile,type, ',');   
				if (type == 'F'){
					string tempInt; 
					getline (infile,tempInt, ',');
 
					int a = stoi (tempInt,nullptr,10); //string conversion function 
					string b;
					getline (infile,b,' ');
					string c; 
					getline (infile,c,',');
					string d;
					getline (infile,d,',');
					int e;
					e << infile; 


					Comedy* tempComedy = createComedy(a, b, c, d, e); //create it 
					comedyTree.insert(tempComedy); //insert it into the comedy BST
				}

				else if (type == 'D'){
					string tempInt; 
					getline (infile,tempInt, ',');
 
					int a = stoi (tempInt,nullptr,10); //string conversion function 
					string b;
					getline (infile,b,' ');
					string c; 
					getline (infile,c,',');
					string d;
					getline (infile,d,',');
					int e;
					e << infile; 

					Drama* tempDrama = createDrama(a, b, c, d, e); 
					dramaTree.insert(tempDrama); 
				}

				else if (type == 'C'){
					int a; 
					string b;
					string c; 
					string d;
					string e; 
					string f; 
					int g;
					int h; 

					Classic* tempClassic = createClassic(a, b, c, d, e, f, g, h);
					classicTree.insert(tempClassic); 
				}

					//else condition handles invalid data 
				else {
						cout << "Invalid data!" << endl; 
						string error; 
						getline(ifstream,error); //should move read the next line of the file 
						cout << error << endl; 
				}
		}
	}
}

Comedy* RentalStore::createComedy(int, string, string, string, int){

}
Drama* RentalStore::createDrama(int, string, string, string, int){

}
Classic* RentalStore::createClassic(int, string, string, string, string, string, int, int){

}