#ifndef _BINTREE_H_
#define _BINTREE_H_
#include "DvdMedia.h"
//Gregory Kitzmiller
//CSS 342 Min Chen
//This Binary Search tree class contains basic functionality to 
// declare, delete, erase, copy, and destruct a bstree. 
// additional functionality: retrieve, get depth (pass a data 
// object and it'll return the depth judged from the highest 
// path from the leaves. It can also convert trees to arrays
// and arrays to trees. 


class BinTree {				
	//Ostream operator<<
	//Pre:A bintree is filled with something to print
	//Post:The contents of the tree are outputted to the console
	friend ostream& operator<< (ostream &, const BinTree &);

private:
	struct Node {
		DvdMedia* data;						// pointer to data object
		Node* left;							// left subtree pointer
		Node* right;						// right subtree pointer
	};
	Node* root;								// root of the tree
	
	// utility functions
	//Sideways
	//Pre: A tree is available to print
	//Post:A tree is outputted to the console
	void sideways(Node*, int) const;			// provided below, helper for displaySideways()
	
public:
	//Default Constructor
	//Pre: NONE
	//Post:An empty BSTree is declared in memory
	BinTree();								// constructor
	//Copy constructor
	//Pre: A valid bintree is passed as an argument
	//Post: "This" contains a deep copy of the passed argument
	BinTree(const BinTree &);				// copy constructor
	//Destructor
	//Pre:Has a declared tree in memory
	//Post:Manages the deletion of the tree, empty tree w/ nulled root
	~BinTree();								// destructor, calls makeEmpty
	//isEmpty
	//Pre:An existing bs tree
	//Post:No change
	bool isEmpty() const;					// true if tree is empty, otherwise false
	//make empty
	//Pre:A Bintree
	//Post:an empty bintree w/ nulled pointers
	void makeEmpty();						// make the tree empty so isEmpty returns true
	//makeEmptyHelper
	//Pre:A valid node pointer address is supplied
	//Post: the tree the pointer connects to is nulled/empty
	void makeEmptyHelper(Node *&);
	//Operator=
	//Pre: A valid bintree on the RHS
	//Post: deep copy and "this" = RHS
	BinTree& operator=(const BinTree &);
	//recursiveAssign
	//Pre: Valid RHS tree and node to assign to 
	//Post: A deep copy from the second argument to the first
	void recursiveAssign(Node *&, Node*) const; //recursively assigns
	//recursiveAssignHelper
	//Pre:valid tree passed
	//Post:copied tree
	void recursiveAssignHelper(const BinTree &); 
	//operator==
	//Pre: Valid bstree on RHS
	//Post:NONE
	bool operator==(const BinTree &) ;
	//recursiveEqualHelper
	//Pre: valid nodes to check equality and nodedada has this operator defined
	//Post: a boolean value for an entire tree
	void recursiveEqualHelper(bool&, Node*, Node*); //recursive isEqual
	//operator!=
	//Pre: == defined in BinTree.cpp
	//Post: NONE, negates ==
	bool operator!=(const BinTree &) ;
	//insert
	//Pre: valid DvdMedia to insert and an uncurrupted bstree
	//Post: node is inserted at a previous leaf
	bool insert(DvdMedia*);
	bool retrieve(const DvdMedia&,DvdMedia*&) ; //look for the input, store in the righthand
	//retrieveHelper
	//Pre: valid arguments
	//Post: NONE
	void retrieveHelper(Node*,const DvdMedia&, DvdMedia*&, bool&); //recursive retrieve
	//displaySideways
	//Pre: valid tree
	//Post: sideways-displayed tree
	void displaySideways() const;			// provided below, displays the tree sideways
	//deleteRoot
	//Pre: has a root declared in mem
	//Post: memory managed
	void deleteRoot(); 
	//printTreePreOrder
	//Pre: tree to print
	//Post: outputted to console in preorder
	void printTreePreOrder(); 
	//printTreePreeHelper
	//Pre: helper function
	//Post: NONE
	void printTreePreeHelper(Node *); 
	//getHeight
	//Pre: valid tree with node passed
	//Post: returns height of the node
	int getHeight(const DvdMedia &);
	//getHeightHelper
	//Pre: Recursive helper
	//Post: NONE
	int getHeightHelper(Node*&, const DvdMedia &, int &);
	//inOrderTransversal
	//Pre: valid tree
	//Post: the value of the previous height +1
	void inOrderTransversal(Node *) const;
	//bstreeToArrayHelper
	//Pre: valid tree
	//Post: printed inorder
	int bstreeToArrayHelper(Node* current, DvdMedia *tempArray[]);
	//bstreeToArray
	//Pre: an array and a bstree
	//Post: bstree is now in array
	void bstreeToArray(DvdMedia* tempArray[]);
	//arrayToBSTree
	//Pre: valid array and bstree
	//Post:tree is now in array
	void arrayToBSTree(DvdMedia* tempArray[]);
	//arrayToBSTreeHelper
	//Pre: valid array and bbstree
	//Post:array is now bstree
	void arrayToBSTreeHelper(DvdMedia* tempArray[], const Node* current, int low, int high);

	

	
};
#endif