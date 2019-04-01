#include "BST.h"

#include <iostream>
using namespace std;

//constructor
template <typename datatype> //every function description must be prefaced with this in the header
inline BST<datatype>::BST():root(0){}


//empty checker
template <typename datatype>
inline bool BST<datatype>::empty() const{
	return root==0;
}


//search function
template <typename datatype>
bool BST<datatype>::search(const datatype& item) const{
	BST<datatype>::nodeptr targetptr = root; //will seek the item in question
	bool found = false;

	while (!found && targetptr != 0){ //while the item is not yet found, but could still exist
		if (item < targetptr->data)
			targetptr = targetptr->left; //travel left if item is low
		else if (item > targetptr->data)
			targetptr = targetptr->right; //travel right if item is high
		else found = true; //item is found if there is no need to travel further
	}
	return found;
}


//insertion function
template <typename datatype>
inline void BST<datatype>::insert(const datatype &item){
	BST<datatype>::nodeptr
		targetptr = root,
		parentptr = 0;
	bool found = false;

	//determine the existence of a duplicate
	while(!found && targetptr != 0){
		parentptr = targetptr; //shift parentptr down first
		//then find the target item with the targetptr using the same method as the search function
		if (item < targetptr->data)
			targetptr = targetptr->left;
		else if (item > targetptr->data)
			targetptr = targetptr->right;
		else found = true;
	}

	if (!found){ //the actual insertion process; involves creating a new node
		targetptr = new TreeNode<datatype>(item); //reuse targetptr as the new nametag for this node
		if (parentptr == 0)
			root = targetptr; //if no nodes ever existed, this one will be the first
		else if (item < parentptr->data) //targetptr is assumed null from this point on
			parentptr->left = targetptr; //add as a left child
		else parentptr->right = targetptr; //add as a right child
	}
	else cout << "Item already exists.\n";
}


//removal function
template <typename datatype>
void BST<datatype>::remove(const datatype& item){
	//generate uninitialised variables to pass into superSearch
	bool found;
	BST<datatype>::nodeptr targetptr, parentptr;

	//call the superSearch function to "return" 3 different values at once
	superSearch(item, found, targetptr,parentptr);

	if (!found){
		cout << "Item does not exist.\n";
		return; //instantly break
	}

	if(targetptr->left != 0 && targetptr->right != 0){ //if the target node has two children
		BST<datatype>::nodeptr successorptr = targetptr->right; //right side arbitrarily chosen over left as a successor
		parentptr = targetptr; ///shift parentptr down to the successor's parent node

		while(successorptr->left != 0){ //runs until the leftmost node is reached
			parentptr = successorptr;
			successorptr = successorptr->left;
		}

		targetptr->data = successorptr->data; //succeed the target node's data
		targetptr = successorptr; //targetptr now points to the original location of the successor, preparing it for the process below
	}

	//if the target node has 0 children or 1 child (whether it was like this in the first place, or as a result of the process above)
	BST<datatype>::nodeptr subtree = targetptr->left; //try pointing to the target's left child
	if (subtree == 0)
		subtree = targetptr->right; //point to the right if the left didn't work
	//subtree stays null if neither of those worked, which is fine

	if (parentptr == 0) //if the target node was the root
		root = subtree; //the new root pointer shifts down to its child's subtree
	else if (parentptr->left == targetptr) //if the target node is a left child
		parentptr->left = subtree; //redirect the parent's child pointer away from the removal target, and into the subtree (even if it's null)
	else parentptr->right = subtree;

	delete targetptr; //safely deletes whatever this points to
}

//graphical display function
template <typename datatype>
inline void BST<datatype>::graph(ostream &out) const{
	graphAux(out, 0, root);
}


//LVR traversal function
template <typename datatype>
inline void BST<datatype>::LVRinorder(ostream &out) const{
	LVRinorderAux(out, root); //let the recursive function do all the work, starting with the root pointer
}


//VLR traversal function
template <typename datatype>
inline void BST<datatype>::VLRpreorder(ostream &out) const{
	VLRpreorderAux(out, root);
}


//LRV traversal function
template <typename datatype>
inline void BST<datatype>::LRVpostorder(ostream &out) const{
	LRVpostorderAux(out, root);
}


//parent + child search function
template <typename datatype>
void BST<datatype>::superSearch(const datatype& item, bool& found, nodeptr& targetptr, nodeptr& parentptr) const{
	//initialisation
	targetptr = root;
	parentptr = 0;
	found = false;

	//search algorithm (again), but also shifts the parentptr
	while(!found && targetptr != 0){
		if (item < targetptr->data){
			parentptr = targetptr;
			targetptr = targetptr->left;
		}
		else if (item > targetptr->data){
			parentptr = targetptr;
			targetptr = targetptr->right;
		}
		else found = true; //don't shift the parentptr during the cycle that locates the target item
	}
	//found, targetptr, and parentptr are changed by this function
}


//graphical display function (auxiliary)
#include <iomanip>

template <typename datatype>
void BST<datatype>::graphAux(ostream &out, int indent, BST<datatype>::nodeptr subroot) const{ //the BST is printed sideways with the root on the left, FYI
	if (subroot != 0){
		graphAux(out, indent+8, subroot->right); //function is called with the rightmost pointer once recursion ends
		out << setw(indent) << " " << subroot->data << endl; //prints that element on top, and shifts down ("left") a line for subsequent elements
		graphAux(out, indent+8, subroot->left); //searches for the leftmost element of that level, eventually prints them starting on the same horizontal ("tier") indent
		//recursion repeats the process from right to left of the original tree
	}
}


//LVR traversal function (auxiliary)
template <typename datatype>
void BST<datatype>::LVRinorderAux(ostream &out, BST<datatype>::nodeptr subroot) const{
	if (subroot != 0){ //recursion control
		LVRinorderAux(out, subroot->left); //L
		out << subroot->data << " "; //V
		LVRinorderAux(out, subroot->right); //R
	}
}


//VLR traversal function (auxiliary)
template <typename datatype>
void BST<datatype>::VLRpreorderAux(ostream &out, BST<datatype>::nodeptr subroot) const{
	if (subroot != 0){ //recursion control
		out << subroot->data << " "; //V
		VLRpreorderAux(out, subroot->left); //L
		VLRpreorderAux(out, subroot->right); //R
	}
}


//LRV traversal function (auxiliary)
template <typename datatype>
void BST<datatype>::LRVpostorderAux(ostream &out, BST<datatype>::nodeptr subroot) const{
	if (subroot != 0){ //recursion control
		LRVpostorderAux(out, subroot->left); //L
		LRVpostorderAux(out, subroot->right); //R
		out << subroot->data << " "; //V
	}
}
