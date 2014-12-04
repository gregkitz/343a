#include <string> 
#include "command.h"
#include <iostream>
using namespace std;
#ifndef _INVENTORY_H_
#define _INVENTORY_H_

class Inventory : public Command {


public:
	void display(){
		cout << "Borrowed: " << title << endl;
	}
	Inventory(char type) : Command(){
		commandType = type;
	}

private:





};




#endif