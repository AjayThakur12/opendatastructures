#include <iostream>

#include "ds/lists.h"

using namespace std;

void listCheck(IList<int> &list){
	list.add(0, 1);
	list.add(0, 2);
	list.add(0, 3);

	cout << "list value at 0 is " << list.get(0) << endl;
	cout << "list value at 1 is " << list.get(1) << endl;
	cout << "list value at 2 is " << list.get(2) << endl;

	list.set(0,0);

	cout << "list value at 0 is " << list.get(0) << endl;

	list.remove(0);

	cout << "list value at 0 is " << list.get(0) << endl;
}

int main() {
	cout << endl << "Testing ArrayStack" << endl;
	ArrayStack<int> as;
	listCheck(as);

	cout << endl << "Testing FastArrayStack" << endl;
	FastArrayStack<int> fas;
	listCheck(fas);

	cout << endl << "Testing ArrayDeque" << endl;
	ArrayDeque<int> ad;
	listCheck(ad);

	cout << endl << "Testing DualArrayDeque" << endl;
	DualArrayDeque<int> dad;
	listCheck(dad);

	return 0;
}
