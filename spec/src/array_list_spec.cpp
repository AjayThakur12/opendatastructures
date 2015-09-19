#include <iostream>

#include "ds/array_lists.h"

using namespace std;

#include "./helpers/lists/deque_check.cpp"
#include "./helpers/lists/list_check.cpp"
#include "./helpers/lists/queue_check.cpp"
#include "./helpers/lists/stack_check.cpp"

int main() {
	cout << endl << "Testing ArrayStack" << endl;
	ArrayStack<int> as;
	listCheck(as);
	stackCheck(as);

	cout << endl << "Testing FastArrayStack" << endl;
	FastArrayStack<int> fas;
	listCheck(fas);
	stackCheck(fas);

	cout << endl << "Testing ArrayQueue" << endl;
	ArrayQueue<int> aq;
	queueCheck(aq);

	cout << endl << "Testing ArrayDeque" << endl;
	ArrayDeque<int> ad;
	listCheck(ad);
	queueCheck(ad);
	stackCheck(ad);
	dequeCheck(ad);

	cout << endl << "Testing DualArrayDeque" << endl;
	DualArrayDeque<int> dad;
	listCheck(dad);

	return 0;
}
