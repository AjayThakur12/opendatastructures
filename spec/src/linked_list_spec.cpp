#include <iostream>

#include "ds/linked_lists.h"

using namespace std;

#include "./helpers/lists/deque_check.cpp"
#include "./helpers/lists/list_check.cpp"
#include "./helpers/lists/queue_check.cpp"
#include "./helpers/lists/stack_check.cpp"

int main(){
	cout << endl << "Testing SLList" << endl;
	SLList<int> sll;
	stackCheck(sll);
	queueCheck(sll);

	cout << endl << "Testing DLList" << endl;
	DLList<int> dll;
	listCheck(dll);
	dequeCheck(dll);
	stackCheck(dll);
	queueCheck(dll);

	return 0;
}
