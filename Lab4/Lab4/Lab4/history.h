#include <string> 
#include "command.h"
#include <iostream>
using namespace std;
#ifndef _HISTORY_H_
#define _HISTORY_H_

class History : public Command {


public:
	void display(){
		cout << "Borrowed: " << title << endl;
	}
	History(char type, int custID){ 
		commandType = type; 
		customerID = custID; 
	}

private:





};




#endif