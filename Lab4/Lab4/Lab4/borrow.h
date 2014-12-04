#include <string> 
#include "command.h"
#include <iostream>
using namespace std;
#ifndef _BORROW_H_
#define _BORROW_H_

class Borrow : public Command {

	
public:
	void display(){
		cout << "Borrowed: " << title << endl; 
	}
	Borrow(char type, int a, int b, string c, string d) : Command(type, a, b, c, d){
		commandType = 'B'; 
	}
	Borrow(char type, string a, int b) : Command(type, a, b){
		commandType = 'B';
	}
	Borrow(char type, string a, string b) : Command(type, a, b){
		commandType = 'B';
	}

private:





};




#endif