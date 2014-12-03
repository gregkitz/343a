#ifndef _DVDMEDIA_H_
#define _DVDMEDIA_H_

#include <iostream>
#include <string>
#include <cstring> 
#include <fstream>
 
using namespace std;

// Base class
class DvdMedia 
{

	friend ostream & operator<<(ostream &,  DvdMedia &);
   public:
      //constructor
	   DvdMedia(); 
	   DvdMedia(string, string, string, string); 
	   
	   // getters and setters

   	  // getters
   		int getStock();
   		string getDirector();
   		string getTitle(); 
   		int getYear(); 
   		virtual void printMovie(); //prints all movie info  

   	  // setters
   		void setStock(const int&); 
   		void decrementStock(); 
   		void incrementStock(); 
   		void setDirector(const string&);
   		void setYear(const int&); 
   		void setTitle(const string&); 
		virtual void display();

		virtual bool operator==(const DvdMedia& rhs) const {
			return (stock == rhs.stock && strcmp(director.c_str(), rhs.director.c_str()) && strcmp(title.c_str(), rhs.title.c_str()));
		}

		virtual bool operator!=(const DvdMedia& rhs) const {
			return !(stock == rhs.stock && director == director && title == title);
		}

		//------------------------ operator<,>,<=,>= ---------------------------------
		virtual bool operator<(const DvdMedia& rhs) const {
			return strcmp(title.c_str(), rhs.title.c_str());
		}

		


   protected:
      int stock;
	  string director;
      
      string title; 
      int  year; 
};

#endif