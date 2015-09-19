#ifndef I_QUEUE_H
#define I_QUEUE_H

/**
* FIFO queue.
*
* Implements one half of deque interface for
* structures that allow efficient removal from
* one end.
*/

template <class T>
class IQueue {
public:
	virtual ~IQueue() {}

	// Pure virtual methods.
	// Must be defined in implementing classes
	virtual int size() = 0;
	virtual void enqueue(T x) = 0;
	virtual T dequeue() = 0;
};

#endif
