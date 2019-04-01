#include "TreeNode.h"

#include <iostream>
using namespace std;

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

template <typename datatype> //template class; leaves the variable type open to user specification
class BST{
	public:
		//constructor
		BST();

		//empty checker
		bool empty() const;

		//search function
		bool search(const datatype &item) const;

		//insertion function
		void insert(const datatype &item);

		//removal function
		void remove(const datatype &item);

		//graphical display function
		void graph(ostream &out) const;

		//LVR traversal function
		void LVRinorder(ostream &out) const;

		//VLR traversal function
		void VLRpreorder(ostream &out) const;

		//LRV traversal function
		void LRVpostorder(ostream &out) const;


	private:
		//node pointer definition
		typedef TreeNode<datatype>* nodeptr;

		//data members
		nodeptr root;

		//function members...


		//parent + child search function
		//void return, but changes 3 values
		void superSearch(const datatype& item, bool& found, nodeptr& targetptr, nodeptr& parentptr) const;

		//graphical display function (auxiliary)
		void graphAux(ostream &out, int indent, BST<datatype>::nodeptr subroot) const;

		//LVR traversal function (auxiliary)
		void LVRinorderAux(ostream &out, BST<datatype>::nodeptr subroot) const;

		//VLR traversal function (auxiliary)
		void VLRpreorderAux(ostream &out, BST<datatype>::nodeptr subroot) const;

		//LRV traversal function (auxiliary)
		void LRVpostorderAux(ostream &out, BST<datatype>::nodeptr subroot) const;
};

#endif
