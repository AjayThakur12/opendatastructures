#include <iostream>

#include "ds/queues.h"

using namespace std;

void queueCheck(IFIFOQueue<int> &queue){
	queue.add(1);
	queue.add(2);
	queue.add(3);

	cout << "next queue value is " << queue.remove() << endl;
	cout << "next queue value is " << queue.remove() << endl;
	cout << "next queue value is " << queue.remove() << endl;
}

int main() {
	cout << endl << "Testing ArrayQueue" << endl;
	ArrayQueue<int> aq;
	queueCheck(aq);

	return 0;
}
