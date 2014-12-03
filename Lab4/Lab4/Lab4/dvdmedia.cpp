#include "dvdmedia.h"
#include <iostream> 
#include <fstream> 
#include <cstring> 
#include <string> 
#include <cstdlib>
using namespace std; 
ostream& operator<<(ostream& output,  DvdMedia& nd) {
	nd.display(); 
	return output;
}

void DvdMedia::display(){
	cout << director << title << year << endl; 

}


DvdMedia::DvdMedia(string movies, string director_p, string title_p, string year_p){

	 stock = atoi(movies.c_str());
	 director = director_p; 
	 title = title_p; 
	 year = atoi(year_p.c_str()); 

}


int DvdMedia::getStock(){
	return stock;
}
string DvdMedia::getDirector(){
	return director; 
}
string DvdMedia::getTitle(){
	return title; 
}
int DvdMedia::getYear(){
	return year; 
}
void DvdMedia::printMovie(){
	cout << "Stock: " << stock << "Director: " << director << "Title: " 
		<< title << "year: " << year << endl; 

} //prints all movie info  

// setters
	void DvdMedia::setStock(const int& amount){
		stock = amount; 
	}
	void DvdMedia::decrementStock(){
		stock--;
	}
	void DvdMedia::incrementStock(){
		stock++; 
	}
	void DvdMedia::setDirector(const string&  directorName){
		director = directorName; 
	}
	void DvdMedia::setYear(const int&  year_p){
		year = year_p; 
	}
	void DvdMedia::setTitle(const string& title_p){
		title = title_p; 
	}