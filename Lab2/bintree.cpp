#include "bintree.h"

	//Builds an empty tree
	BinTree::BinTree(){
		root = NULL; 
	}// constructor
	BinTree::BinTree(const BinTree &){




	}		// copy constructor
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
		if (isEmpty()){
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
	


