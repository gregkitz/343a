#include "nodedata.h"

class BinTree {				// you add class/method comments and assumptions
	//class methods and assumptions

private:
	struct Node {
		NodeData* data;						// pointer to data object
		Node* left;							// left subtree pointer
		Node* right;						// right subtree pointer
	};
	Node* root;								// root of the tree
	
	// utility functions
	void inorderHelper(...) const;
	void sideways(Node*, int) const;			// provided below, helper for displaySideways()
	void makeEmpty(Node *);						// make the tree empty so isEmpty returns true
public:
	BinTree();								// constructor
	BinTree(const BinTree &);				// copy constructor
	~BinTree();								// destructor, calls makeEmpty	
	bool isEmpty() const;					// true if tree is empty, otherwise false
	
	void makeEmptyHelper(); 
	BinTree& operator=(const BinTree &);
	void recursiveAssign(Node *&, Node*) const; //recursively assigns
	void recursiveAssignHelper(const BinTree &); 
	bool operator==(const BinTree &) const;
	bool operator!=(const BinTree &) const;
	bool insert(NodeData*);
	bool retrieve(...) const;
	void displaySideways() const;			// provided below, displays the tree sideways
	void deleteRoot(); 
	void printTreePreOrder(); 
	void printTreePreeHelper(Node *); 
	

	
};
