#include "nodedata.h"

class BinTree {				// you add class/method comments and assumptions
	//class methods and assumptions
	friend ostream& operator<< (ostream &, const BinTree &);

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
	
public:
	BinTree();								// constructor
	BinTree(const BinTree &);				// copy constructor
	~BinTree();								// destructor, calls makeEmpty	
	bool isEmpty() const;					// true if tree is empty, otherwise false
	void makeEmpty();						// make the tree empty so isEmpty returns true
	void makeEmptyHelper(Node *&);
	BinTree& operator=(const BinTree &);
	void recursiveAssign(Node *&, Node*) const; //recursively assigns
	void recursiveAssignHelper(const BinTree &); 
	bool operator==(const BinTree &) ;
	void recursiveEqualHelper(bool&, Node*, Node*); //recursive isEqual
	bool operator!=(const BinTree &) ;
	bool insert(NodeData*);
	bool retrieve(const NodeData&,NodeData*&) ; //look for the input, store in the righthand
	void retrieveHelper(Node*,const NodeData&, NodeData*&, bool&); //recursive retrieve
	void displaySideways() const;			// provided below, displays the tree sideways
	void deleteRoot(); 
	void printTreePreOrder(); 
	void printTreePreeHelper(Node *); 
	int getHeight(const NodeData &);
	int getHeightHelper(Node*&, const NodeData &, int &);
	void inOrderTransversal(Node *curPtr) const;
	int bstreeToArrayHelper(Node* curPtr, NodeData *tempArray[]);
	void bstreeToArray(NodeData* tempArray[]);  
	void arrayToBSTree(NodeData* tempArray[]);
	void arrayToBSTreeHelper(NodeData* tempArray[], const Node* curPtr, int low, int high);

	

	
};
