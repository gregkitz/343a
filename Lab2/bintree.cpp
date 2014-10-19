#include "bintree.h"

	//Builds an empty tree
	BinTree::BinTree(){
		root = NULL; 
	}// constructor

	// copy constructor
	BinTree::BinTree(const BinTree & RHS){
		recursiveAssign(root, RHS.root);

	}		
	BinTree::~BinTree(){
	
		makeEmpty(); 
		//delete root; 
		//root = NULL; 

	} // destructor, calls makeEmpty	
	bool BinTree::isEmpty() const{
		return (root == NULL); 

	}// true if tree is empty, otherwise false
	//void makeEmpty();						// make the tree empty so isEmpty returns true
	//BinTree& operator=(const BinTree &);
	//bool operator==(const BinTree &) const;
	//bool operator!=(const BinTree &) const;
//-----------------------------------------------------------------------------
//Insert Function 
//Precondition: 
//Postcondition: 

	bool BinTree::insert(NodeData* dataptr)
	{
		Node* ptr = new Node; // exception is thrown if memory is not allocated
		ptr->data = dataptr; //Link to current NodeData
		dataptr = NULL; //Disconnect
		ptr->left = ptr->right = NULL;
		if (isEmpty())
		{
			root = ptr; //Empty, set as root
		}
		else
		{
			Node* current = root;
			bool inserted = false;
			// if data is less than current data, insert in left subtree,
			// otherwise insert in right subtree
			while (!inserted)
			{
				cout << "loop" << endl; 
				if (*ptr->data == *current->data) //Duplicate found, dont allow insert
				{
					cout << "loop?" << endl; 
					delete ptr; //Handle duplicate properly
					ptr = NULL;
					return false;
				}
				else if (*ptr->data < *current->data)
				{
					if (current->left == NULL) // at leaf, insert left
					{
						current->left = ptr;
						inserted = true;
					}
					else
						current = current->left; // one step left
				}
				else {
					if (current->right == NULL)
					{ // at leaf, insert right
						current->right = ptr;
						inserted = true;
					}
					else
						current = current->right; // one step right
				}
			}
		}
		return true;
	}

		




//Make empty helper. Checks root and if not null calls make empty
//either way clears the root node at the end 

	void BinTree::makeEmpty(){
		if (!isEmpty()){
			//call make empty on the root 
			makeEmptyHelper(root);
			//deleteRoot(); 
		}

	}

	//Delete root utility function 
	//manages the memory of the root deletion 
	void BinTree::deleteRoot(){
		root->left = NULL; 
		root->right = NULL; 
		delete root; 

	}
//Make empty function. Manages the deletion and memory management of the Tree
//Pre:
//Post:

	void BinTree::makeEmptyHelper(Node *& currentNode){
		//clears the tree recursively 
		
		//if the left child isn't null call make empty on it 
		// if the right child isn't null call make empty on it 
		// otherwise, delete the current node and it's child pointers
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


	//Assignment Operator 

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
	
//RecursiveAssign
//Assigns all of the data in one tree to another
//Pre: the "toCopy" tree is NULL
//Post: A deep copy of the RHS tree to the toCopy tree

	void BinTree::recursiveAssign(Node *& copied, Node* RHS) const {
		//check if the current pointer is NULL (
		if (RHS != NULL){
			//create new node object for insert
			Node * temp = new Node;
			//copy the data to a new nodeData object 
			NodeData * tempNode = new NodeData(*RHS->data);
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
	bool BinTree::retrieve(const NodeData& search, NodeData*& found) {
		bool isFound = false;
		retrieveHelper(root, search, found,isFound);
		return isFound; 
	}

	void BinTree::retrieveHelper(Node* current, const NodeData& search, NodeData*& found, bool& isFound){
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
		if (current == NULL ^ RHS == NULL){
			isEqual = false;
		}
	}

	int BinTree::getHeight(const NodeData & toFind) {
		int height = 0; 
		height = getHeightHelper(root, toFind, height); 
		return height; 

	}

	int BinTree::getHeightHelper(Node * current, const NodeData & theNode,  int & theHeight){
		if (!current) return 0;
		int left_height = getHeightHelper(current->left, theNode, theHeight);
		int right_height = getHeightHelper(current->right, theNode,  theHeight);
		if (*current->data == theNode){
			theHeight = left_height > right_height ? left_height : right_height;
		}
		return (left_height > right_height) ? left_height + 1 : right_height + 1;
	}
	void BinTree::bstreeToArray(NodeData* tempArray[])
	{
		bstreeToArrayHelper(root, tempArray);
		makeEmpty(); //Make BST empty
	}
	int BinTree::bstreeToArrayHelper(Node* curPtr, NodeData *tempArray[])
	{
		if (curPtr == NULL) //No data
			return 0;
		//Set location of left
		int left = bstreeToArrayHelper(curPtr->left, tempArray);
		NodeData *temp;
		temp = curPtr->data; // save the pointer to NodeData object to temp
		curPtr->data = NULL; // disconnect NodeData from Node
		*(tempArray + left) = temp; //tempArray points to temp
		temp = NULL; //Disconnect
		//set location of right
		int right = bstreeToArrayHelper(curPtr->right, tempArray + left + 1);
		return left + right + 1; //Return position
	}

	void BinTree::arrayToBSTree(NodeData* tempArray[])
	{
		int high = 0;
		for (int i = 0; i < 100; i++) //Count how many indexs of array are used
		{
			if (tempArray[i] != NULL)
				high++;
			else
				tempArray[i] = NULL;
		}
		//Recursively call helper function to perform calculations
		
		arrayToBSTreeHelper(tempArray, root, 0, high - 1);
	}
	void BinTree::arrayToBSTreeHelper(NodeData* tempArray[], const Node* curPtr, int low, int high)
	{
		
		if (low > high) //end
			curPtr = NULL;
		else
		{
			int root = (low + high) / 2; //Location of data to insert recursively at root
			NodeData *temp;
			temp = tempArray[root]; //set temp to point to NodeData* in array
			tempArray[root] = NULL; //disconnect tempArray from the Nodedata
			
			insert(temp); //insert NodeData to BST
			//check left array
			arrayToBSTreeHelper(tempArray, curPtr, low, root - 1);
			//check right array
			arrayToBSTreeHelper(tempArray, curPtr, root + 1, high);
		}
	}

	

	ostream& operator<<(ostream& output, const BinTree& bst)
	{
		bst.inOrderDisplay(bst.root); //call inOrderDisplay
		output << endl;
		return output;
	}
	void BinTree::inOrderDisplay(Node *curPtr) const
	{
		if (curPtr != NULL) //Traverse inorder and print data
		{
			inOrderDisplay(curPtr->left);
			cout << *curPtr->data << " ";
			inOrderDisplay(curPtr->right);
		}
	}

	void BinTree::displaySideways() const
	{
		sideways(root, 0);
	}
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
