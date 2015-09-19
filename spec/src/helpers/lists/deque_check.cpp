void dequeCheck(IDeque<int> &deque){
	cout << "Testing deque interface:" << endl;

	for (int i = 0; i < 3; i++){
		cout << " adding value " << i << "to end" << endl;
		deque.addLast(i);
	}

	// 0
	// 0 1
	// 0 1 2


	for (int i = 3; i < 6; i++){
		cout << " adding value " << i << "to front" << endl;
		deque.addFirst(i);
	}

	// 3 0 1 2
	// 4 3 0 1 2
	// 5 4 3 0 1 2


	for (int i = 0; i < 2; i++){
		cout << " removed value " << deque.removeFirst() << "from front" << endl;
	}

	// Expect to get:
	// 5
	// 4

	// Leaving:
	// 3 0 1 2

	for (int i = 0; i < 4; i++){
		cout << " removed value " << deque.removeLast() << "from end" << endl;
	}

	// Expect to get:
	// 2
	// 1
	// 0
	// 3


}
