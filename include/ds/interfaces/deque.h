#ifndef I_DEQUE_H
#define I_DEQUE_H

#include "./queue.h"
#include "./stack.h"

template <class T>
class IDeque{
public:
	virtual ~IDeque() {}

	// Pure virtual methods.
	// Must be defined in implementing classes
	virtual int size() = 0;
	virtual void addFirst(T x) = 0;
	virtual T removeFirst() = 0;
	virtual void addLast(T x) = 0;
	virtual T removeLast() = 0;
};

#endif
