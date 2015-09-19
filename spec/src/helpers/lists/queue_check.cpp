void queueCheck(IQueue<int> &queue){
	cout << "Testing queue interface:" << endl;

	for (int i = 0; i < 3; i++){
		cout << " enqueueing value: " << i << endl;
		queue.enqueue(i);
	}

	while(queue.size()){
		cout << " dequeueing value: " << queue.dequeue() << endl;
	}
}
