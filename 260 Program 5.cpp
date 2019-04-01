#include <iostream>
using namespace std;

#include "BST.h"
#include "BST.cpp" //a necessary evil (for the compiler to instantly notice the template)

int main(){
	//constructor call and empty check demonstration
	BST<int> sampleBST; //datatype is determined in this declaration
	cout << "Empty BST generated. Confirming empty status...\n";
	cout << "The BST " << (sampleBST.empty() ? "is" : "is not") << " empty.\n\n\n";


	//insertion demonstration
	cout << "Begin inserting numerical values. [Enter -9999 to stop]\n";
	int num; //to be reused in subsequent functions as well
	for(;;){ //no naturally occurring exit condition to this loop
		cout << "Enter input:\n";
		cin >> num;
		if (num == -9999) break; //the sole exit condition
		sampleBST.insert(num);
	}
	cout << "Input cycle terminated. Printing visual representation...\n\n";
	sampleBST.graph(cout);
	cout << endl;
	cout << "Insertion phase concluded.\n\n\n";


	//search demonstration
	cout << "Attempt to search for data values within the BST. [Enter -9999 to stop]\n";
	for(;;){
		cout << "Enter search terms:\n";
		cin >> num;
		if (num == -9999) break;
		cout << (sampleBST.search(num) ? "Item located.\n" : "Item does not exist.\n");
	}
	cout << "Search phase concluded.\n\n\n";


	//removal demonstration
	cout << "Attempt to remove values from within the BST. [Enter -9999 to stop]\n";
	for(;;){
			cout << "Enter removal targets:\n";
			cin >> num;
			if (num == -9999) break;
			sampleBST.remove(num);
			cout << "Updating visual representation...\n\n";
			sampleBST.graph(cout);
			cout << endl;
	}
	cout << "Removal phase concluded.\n\n\n";


	//retry the empty checker
	cout << "Re-testing for empty status...\n";
	cout << "The BST " << (sampleBST.empty() ? "is" : "is not") << " empty.\n\n\n";


	//inorder demonstration
	cout << "Outputting contents in LVR order (inorder):\n";
	sampleBST.LVRinorder(cout);
	cout << endl;

	//preorder demonstration
	cout << "Outputting contents in VLR order (preorder):\n";
	sampleBST.VLRpreorder(cout);
	cout << endl;

	//postorder demonstration
	cout << "Outputting contents in LRV order (postorder):\n";
	sampleBST.LRVpostorder(cout);
	cout << endl << endl << endl;

	cout << "End of simulation.";
	return 0;
}
