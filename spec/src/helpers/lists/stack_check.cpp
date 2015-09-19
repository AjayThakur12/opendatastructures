void stackCheck(IStack<int> &stack){
	cout << "Testing stack interface:" << endl;

	for (int i = 0; i < 3; i++){
		cout << " pushing value: " << i << endl;
		stack.push(i);
	}

	while(stack.size()){
		cout << " popped value: " << stack.pop() << endl;
	}
}
