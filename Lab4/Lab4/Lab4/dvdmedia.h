#ifndef _DVDMEDIA_H_
#define _DVDMEDIA_H_

#include <iostream>
 
using namespace std;

// Base class
class DvdMedia 
{
   public:
      // getters and setters

   	  // getters
   		int getStock();
   		string getDirectorFirst();
   		string getDirectorLast(); 
   		string getTitle(); 
   		int getYear(); 
   		virtual void printMovie(); //prints all movie info  

   	  // setters
   		setStock(const int&); 
   		decrementStock(); 
   		incrementStock(); 
   		setDirectorFirst(const string&);
   		setDirectorLast(const string&);
   		setYear(const int&); 
   		setTitle(const string&); 

   protected:
      int stock;
      string directorFirst;
      string directorLast; 
      string title; 
      int year; 
};

#endif