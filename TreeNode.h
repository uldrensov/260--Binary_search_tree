#ifndef TREENODE
#define TREENODE

template <typename datatype> class BST; //forward declaration of class BST to preface its declaration as a friend

template <typename datatype> //BST is a template, so TreeNode must follow suit
class TreeNode{
	friend class BST<datatype>; //BST requires direct access to the private data members
	public:
		//constructors with descriptions
		TreeNode() : data(0), left(0), right(0){} //default
		TreeNode(datatype i) : data(i), left(0), right(0){} //explicit value

		//accessor function
		int getItem() const;


	private:
		//data members
		datatype data;
		TreeNode* left;
		TreeNode* right;
};


//function descriptions...


//accessor function
template <typename datatype>
int TreeNode<datatype>::getItem() const{
	return data;
}

#endif
