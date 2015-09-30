#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <time.h>

#include "ds/binary_trees.h"

using namespace std;

int main(){
	cout << endl << "Testing BinarySearchTree" << endl;
	BinarySearchTree<int> bst;
	// This tree doesn't attempt to balance itself, so it's probably a good
	// idea to spread the data evenly around the first added element
	bst.add(8);
	bst.add(3);
	bst.add(4);
	bst.add(10);
	bst.add(9);
	bst.add(12);

	bst.draw();

	cout << " size is " << bst.size() << endl;

	cout << "Next largest number to 7: " << bst.find(7) << endl;
	cout << "Next largest number to 11: " << bst.find(11) << endl;
	cout << "Next largest number to 8: " << bst.find(8) << endl;
	cout << "Next largest number to 4: " << bst.find(4) << endl;

	cout << "Second largest number is: " << bst.secondLargest() << endl;

	cout << "Largest number is: " << bst.nthLargest(1) << endl;
	cout << "Second largest number is: " << bst.nthLargest(2) << endl;
	cout << "Third largest number is: " << bst.nthLargest(3) << endl;
	cout << "Fourth largest number is: " << bst.nthLargest(4) << endl;
	cout << "Fifth largest number is: " << bst.nthLargest(5) << endl;
	cout << "Sixth largest number is: " << bst.nthLargest(6) << endl;

	cout << "removing " << bst.remove(10) << ", tree size is now " << bst.size() << endl;
	cout << "removing root node " << bst.remove(8) << ", tree size is now " << bst.size() << endl;

	BinarySearchTree<int> bst1;
	bst1.add(8);
	cout << "Next largest number to 7: " << bst1.find(7) << endl;
	try {
		cout << "Next largest number to 11: " << bst1.find(11) << endl;
	} catch(std::out_of_range){
		cout << "There are no numbers larger than 11" << endl;
	}
	cout << "Next largest number to 8: " << bst1.find(8) << endl;


	cout << endl << "Testing Treap" << endl;
	/* initialize random seed: */
  	srand (time(NULL));

	Treap<int> treap;

	treap.add(8);
	treap.add(3);
	treap.add(4);
	treap.add(10);
	treap.add(9);
	treap.add(12);

	cout << " size is " << treap.size() << endl;

	treap.draw();

	treap.remove(12);
	cout << " size after removing 12 is " << treap.size() << endl;
	treap.draw();

	cout << "Next largest number to 5: " << treap.find(5) << endl;

	return 0;
}
