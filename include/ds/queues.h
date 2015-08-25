#ifndef QUEUES_H
#define QUEUES_H

#include "./array.h"

template <class T>
class IFIFOQueue {

public:
	virtual ~IFIFOQueue() {}

	virtual bool add(T x) = 0;
	virtual T remove() = 0;
};


template <class T>
class ArrayQueue : public IFIFOQueue<T> {
	Array<T> a;
	int j;
	int n;

	void resize();

public:
	bool add(T x);
	T remove();
};

#include "../src/queues/ArrayQueue.cpp"

#endif
