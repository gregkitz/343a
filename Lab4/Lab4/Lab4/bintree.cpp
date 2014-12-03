//Gregory Kitzmiller
//343 Min Chen 
//Lab2
// Binary Search tree class. Contains all of the necessary functions to 
// create a binary search tree using the nodeData class and delete, assign,
// and copy. 
// It has the additional functionaliy of being able to find the depth of a 
// given node, retrieve a given node, and convert a binary
// search tree to array or array to binary search tree. 
//----------------------------------------------------------------------------
#include "bintree.h"
#include "dvdmedia.h"

//----------------------------------------------------------------------------
//Constructors/Destructors/Utility Functions
//----------------------------------------------------------------------------
//Default constructor

	//Builds an empty tree
	BinTree::BinTree(){
		root = NULL; 
	}// constructor
//----------------------------------------------------------------------------
// copy constructor
//Does a deep copy of an existing binary search tree. 
	BinTree::BinTree(const BinTree & RHS){
		recursiveAssign(root, RHS.root);

	}		
//----------------------------------------------------------------------------
//Destructor
//Empties out the remaining memory from a given binary search tree
	BinTree::~BinTree(){
	
		makeEmpty(); 
		//delete root; 
		//root = NULL; 

	} 

//----------------------------------------------------------------------------
//Is empty 
//Returns true or false whether a tree has a null root pointer
	bool BinTree::isEmpty() const{
		return (root == NULL); 

	}

//-----------------------------------------------------------------------------
//Printing function
//prints using inorder transversal
	ostream& operator<<(ostream& output, const BinTree& tree)
	{
		tree.inOrderTransversal(tree.root);
		output << endl;
		return output;
	}
//-----------------------------------------------------------------------------
//Insert Function 
//Inserts a nodedata into a new tree. Declares memory for this. 

	bool BinTree::insert(DvdMedia* dataptr)
	{
		Node* newPtr = new Node; // new node to store data in 
		newPtr->data = dataptr; //points it to the data
		dataptr = NULL; //nulls out the passed pointer
		newPtr->left = newPtr->right = NULL;
		if (isEmpty())
		{
			root = newPtr; 
		}
		else
		{
			Node* current = root;
			bool inserted = false;
	
			while (!inserted)
			{
				//if (*newPtr->data == *current->data) //duplicate delete
				//{
				//	delete newPtr; 
				//	newPtr = NULL;
				//	return false;
				//}
				/*else*/ if (*newPtr->data < *current->data)//go left first w/ bst
				{
					if (current->left == NULL) 
					{
						current->left = newPtr;
						inserted = true;
					}
					else
						current = current->left; //transverse
				}
				else {
					if (current->right == NULL)
					{ 
						current->right = newPtr;
						inserted = true;
					}
					else
						current = current->right; 
				}
			}
		}
		return true;
	}


		
//----------------------------------------------------------------------------
//Make Empty
//Expected function. Calls the recursive helper
	void BinTree::makeEmpty(){
		if (!isEmpty()){
			//call make empty on the root 
			makeEmptyHelper(root);
			//deleteRoot(); 
		}

	}
//----------------------------------------------------------------------------
	//Delete root utility function 
	//manages the memory of the root deletion 
	void BinTree::deleteRoot(){
		root->left = NULL; 
		root->right = NULL; 
		delete root; 

	}
//----------------------------------------------------------------------------
//Make Empty Helper
	//if the left child isn't null call make empty on it 
	// if the right child isn't null call make empty on it 
	// otherwise, delete the current node and it's child pointers
	void BinTree::makeEmptyHelper(Node *& currentNode){
		//clears the tree recursively 
		
		
		if (currentNode->left != NULL){
			makeEmptyHelper(currentNode->left); 
		}
		if (currentNode->right != NULL){
			makeEmptyHelper(currentNode->right); 
		}
		delete currentNode->data; 
		delete currentNode; 
		currentNode = NULL; 

	}

//----------------------------------------------------------------------------
//Assignment Operator 
// Clears "this" and assigns the righthand argument's values to it

	BinTree& BinTree::operator=(const BinTree & RHS){
		//remember to test for self-assignment
		if (this !=  &RHS){
			makeEmpty(); //clear current
			recursiveAssign(root, RHS.root); //assign 
			return *this; //return this' address

		}
		else{
			return  *this;

		}

		
	}
//----------------------------------------------------------------------------	
//RecursiveAssign
//Recursively copies the righthand to the passed root called "copied"

	void BinTree::recursiveAssign(Node *& copied, Node* RHS) const {
		//check if the current pointer is NULL (
		if (RHS != NULL){
			//create new node object for insert
			Node * temp = new Node;
			//copy the data to a new nodeData object 
			DvdMedia * tempNode = new DvdMedia(*RHS->data);
			//Assign nodedata to new node
			temp->data = tempNode;
			//assign it to LHS
			copied = temp;
			//recursively do this left then right
			recursiveAssign(copied->left, RHS->left);
			recursiveAssign(copied->right, RHS->right);
			
		}
		else{
			copied = RHS; //assign empty tree (would produce memory leak if pre not met)
		}
	}

	void BinTree::recursiveAssignHelper(const BinTree & RHS){
		recursiveAssign(root, RHS.root); 

	}


	//Print Tree Functions

	//

	void BinTree::printTreePreOrder(){
		printTreePreeHelper(root); 
	}
	void BinTree::printTreePreeHelper(Node * toPrint){
		//if node is not null print it
		if (toPrint != NULL) {
			cout << *toPrint->data;
			//then recurse lefthand then right
			printTreePreeHelper(toPrint->left); 
			printTreePreeHelper(toPrint->right); 
		}
		else {
			//it's null, don't do anything
		}

	}
	

	//Retrieve
	//Takes a nodedata to find and a node data to store the found 
	//results in
	bool BinTree::retrieve(const DvdMedia& search, DvdMedia*& found) {
		bool isFound = false;
		retrieveHelper(root, search, found,isFound);
		return isFound; 
	}

	void BinTree::retrieveHelper(Node* current, const DvdMedia& search, DvdMedia*& found, bool& isFound){
		if (current != NULL){
			//compare current nodeData to search
			if (*current->data == search){
				isFound = true;
				found = current->data;
			}
			//if they're the same update isFound to true

			//otherwise continue to recurse through the LH and RH subtrees
			//
			else{
				if (search < *current->data){
					retrieveHelper(current->left, search, found, isFound);
				}
				else{
					retrieveHelper(current->right, search, found, isFound);
				}
			}
		}
		found = NULL; //wasn't found

	}
	
	bool BinTree::operator==(const BinTree & RHS) {
		bool areEqual = true; 
		recursiveEqualHelper(areEqual, root, RHS.root);
			return areEqual; 
	}

	//negates the == operator
	bool BinTree::operator!=(const BinTree & RHS) {
		return !(*this == RHS); 

	}

	void BinTree::recursiveEqualHelper(bool& isEqual, Node* current, Node* RHS){
		//only check and recurse if they're not NULL
		if (current != NULL && RHS != NULL){
			//if they don't equal make the update and stop recursing
			if (*current->data != *RHS->data){
				isEqual = false;
				
			}
			else{
					//continue on LH and RH
					recursiveEqualHelper(isEqual, current->left, RHS->left);
					recursiveEqualHelper(isEqual, current->right, RHS->right);
				
			}
			
		}
		if ((current == NULL) ^ (RHS == NULL)){
			isEqual = false;
		}
	}

	int BinTree::getHeight(const DvdMedia & toFind) {
		int height = 0; 
		getHeightHelper(root, toFind, height); 
		return height; 

	}
	//----------------------------------------------------------------------------
	//Recursive get height
	//Finds the deepest past based off a postorder transversal while
	//tallying the backtracking
	int BinTree::getHeightHelper(Node *& current, const DvdMedia & theNode,  int & theHeight){
		if (!current) return 0;
		int left_height = getHeightHelper(current->left, theNode, theHeight);
		int right_height = getHeightHelper(current->right, theNode,  theHeight);
		if (*current->data == theNode){
			theHeight = (left_height > right_height) ? left_height+1 : right_height+1;
		}
		return (left_height > right_height) ? left_height + 1 : right_height + 1;
	}


	//----------------------------------------------------------------------------
	//bstreeToArray
	//converts a binary search tree to an array 

	void BinTree::bstreeToArray(DvdMedia* tempArray[])
	{
		bstreeToArrayHelper(root, tempArray);
		makeEmpty(); 
	}
	//----------------------------------------------------------------------------
	// recursive method of filling binary search tree
	//inorder transversal to fill it up while updating the array index
	//using pointer arithmatic
	int BinTree::bstreeToArrayHelper(Node* current, DvdMedia *tempArray[])
	{
		if (current == NULL) {
			return 0;
		}
		
		int left = bstreeToArrayHelper(current->left, tempArray);
		DvdMedia *temp;
		temp = current->data; 
		current->data = NULL; 
		*(tempArray + left) = temp; //pointer arithmatic updates index
		temp = NULL; 
		
		int right = bstreeToArrayHelper(current->right, tempArray + left + 1);
		return left + right + 1; 
	}
	//----------------------------------------------------------------------------
	//starts at the middle of the array (typically where root would be)
	//counts the indexes for the array
	//recursively call helper function for calculations
	//leaves temparray with NULLs
	void BinTree::arrayToBSTree(DvdMedia* tempArray[])
	{
		int high = 0;
		for (int i = 0; i < 100; i++) 
		{
			if (tempArray[i] != NULL)
				high++;
			else
				tempArray[i] = NULL;
		}
		
		
		arrayToBSTreeHelper(tempArray, root, 0, high - 1);
	}
	void BinTree::arrayToBSTreeHelper(DvdMedia* tempArray[], const Node* current, int low, int high)
	{
		
		if (low > high) //end
			current = NULL;
		else
		{
			int root = (low + high) / 2; 
			DvdMedia *temp;
			temp = tempArray[root];
			tempArray[root] = NULL; 
			
			insert(temp); 
			
			arrayToBSTreeHelper(tempArray, current, low, root - 1);
			
			arrayToBSTreeHelper(tempArray, current, root + 1, high);
		}
	}
	

	void BinTree::inOrderTransversal(Node * current) const
	{
		if (current != NULL) //Traverse inorder and print data
		{
			inOrderTransversal(current->left);
			cout << *current->data << " ";
			inOrderTransversal(current->right);
		}
	}
	//------------------------- displaySideways ---------------------------------
	// Displays a binary tree as though you are viewing it from the side;
	// hard coded displaying to standard output.
	// Preconditions: NONE
	void BinTree::displaySideways() const
	{
		sideways(root, 0);
	}
	//---------------------------- Sideways -------------------------------------
	// Helper method for displaySideways
	// Preconditions: NONE
	// Postconditions: BinTree remains unchanged.
	void BinTree::sideways(Node* current, int level) const
	{
		if (current != NULL) {
			level++;
			sideways(current->right, level);
			// indent for readability, 4 spaces per depth level
			for (int i = level; i >= 0; i--) {
				cout << " ";
			}
			cout << *current->data << endl; // display data
			sideways(current->left, level);
		}
	}
