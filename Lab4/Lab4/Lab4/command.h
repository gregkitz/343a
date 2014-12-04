#ifndef _COMMAND_H_
#define _COMMAND_H_


#include <string> 
#include "dvdmedia.h"

using namespace std;
class Command {
	friend ostream & operator<<(ostream &, Command &);
public:
	virtual void display(){

	}
	Command(){}
	Command(char type, int month,int year,string actorFirst,string actorLast){
		commandType = type; 
		mediaType = 'C'; 
		releaseMonth = month; 
		releaseYear = year; 
		actFirst = actorFirst; 
		actLast = actorLast; 
	}
	Command(char type, string directorName, int releaseYear_p){
		commandType = type;
		mediaType = 'F';
		director = directorName; 
		releaseYear = releaseYear_p; 
	}
	Command(char type, string mainActorr, string title_p){
		commandType = type;
		mediaType = 'D';
		mainActor = mainActorr; 
		title = title_p; 

	}
	
protected:
	int customerID; 
	int releaseMonth;
	int releaseYear; 
	string director; 
	string title; 
	string actFirst; 
	string actLast;
	string mainActor; 
	char commandType; 
	char mediaType; 
	char movieType; 
	

	DvdMedia* itemInQuestion;

private: 
};
#endif