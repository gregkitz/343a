#ifndef _DVDMEDIA_H_
#define _DVDMEDIA_H_
#include "nodedata.h"
#include <iostream>
 
using namespace std;

// Base class
class DvdMedia : public NodeData 
{
   public:
      //constructor
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

   protected:
      int stock;
	  string director;
      
      string title; 
      int  year; 
};

#endif