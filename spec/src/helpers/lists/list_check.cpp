void listCheck(IList<int> &list){
	cout << "Testing list interface:" << endl;

	list.add(0, 1);
	list.add(0, 2);
	list.add(0, 3);

	cout << " list value at 0 is " << list.get(0) << endl;
	cout << " list value at 1 is " << list.get(1) << endl;
	cout << " list value at 2 is " << list.get(2) << endl;

	list.set(0,0);

	cout << " list value at 0 is " << list.get(0) << endl;

	list.remove(0);

	cout << " list value at 0 is " << list.get(0) << endl;

	// Remove remaining values from the list
	while (list.size()){
		list.remove(0);
	}
}
