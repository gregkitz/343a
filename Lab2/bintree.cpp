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
	
		makeEmptyHelper(); 
		//delete root; 
		//root = NULL; 

	} // destructor, calls makeEmpty	
	bool BinTree::isEmpty() const{
		return (root == NULL) ? true : false; 

	}// true if tree is empty, otherwise false
	//void makeEmpty();						// make the tree empty so isEmpty returns true
	//BinTree& operator=(const BinTree &);
	//bool operator==(const BinTree &) const;
	//bool operator!=(const BinTree &) const;
//-----------------------------------------------------------------------------
//Insert Function 
//Precondition: 
//Postcondition: 
	
	bool BinTree::insert(NodeData* dataPtr){
		//Declare new node to insert 
		Node* ptr = new Node; 
		if (ptr == NULL) return false; //out of memory
		ptr->data = dataPtr; 
		ptr->left = ptr->right = NULL; 
		if (isEmpty()){ //if the tree is empty insert to the root
			root = ptr; 
		}
		else{

			Node* current = root; //walking pointer that starts at the root
			bool inserted = false; 

			//if item is less than the current insert into the left subtree, 
			//otherwise, insert into the right subtree

			while (!inserted){
				if (*ptr->data < *current->data){
					if (current->left == NULL){
						current->left = ptr; 
						inserted = true; 
					}
					else {
						current = current->left; 
					}
				}
				else{
					if (current->right == NULL) {
						current->right = ptr; 
						inserted = true; 
					}
					else{
						current = current->right; 
					}

				}


			}

			return true; 
		}
		
		//If the head is null, return false
		//If the head



	}

//Make empty helper. Checks root and if not null calls make empty
//either way clears the root node at the end 

	void BinTree::makeEmptyHelper(){
		if (!isEmpty()){
			//call make empty on the root 
			makeEmpty(root);
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

	void BinTree::makeEmpty(Node * currentNode){
		//clears the tree recursively 
		
		//if the left child isn't null call make empty on it 
		// if the right child isn't null call make empty on it 
		// otherwise, delete the current node and it's child pointers
		if (currentNode->left != NULL){
			makeEmpty(currentNode->left); 
		}
		if (currentNode->right != NULL){
			makeEmpty(currentNode->right); 
		}
		delete currentNode->data; 
		delete currentNode; 
		currentNode = NULL; 

	}


	//Assignment Operator 

	BinTree& BinTree::operator=(const BinTree & RHS){
		//remember to test for self-assignment
		if (this !=  &RHS){
			makeEmpty(root); //clear current
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
	//Retrieve helper
	//returns the return of a recursive function call all the way up

	//checks the current node


	//if found returns true

	//otherwise checks left and right
	//if still not found returns false 
