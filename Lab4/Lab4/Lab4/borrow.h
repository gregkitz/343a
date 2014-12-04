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


private:





};




#endif