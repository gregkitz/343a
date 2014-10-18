#include "bintree.h"
#include <fstream>
#include <iostream>
using namespace std;


int main() {
	BinTree T; 
	NodeData * M; 
	M = new NodeData("meow"); 
	T.insert(M); 
	NodeData *J; 
	J = new NodeData("ruff"); 
	T.insert(J); 
	T.printTreePreOrder(); 
	BinTree U; 
	U.recursiveAssignHelper(T); 
	U.printTreePreOrder(); 

	int a; 
	cin >> a; 
}