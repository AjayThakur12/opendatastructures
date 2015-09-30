/**
* A simple singly-linked list.
*
* The singly-linked list is able to efficiently implement
* the queue and stack interfaces. However, it adds some
* memory overhead compared to its array based equivalents.
* In some cases, it is still the best choice as it does not
* have the restriction that all elements re arranged sequentially
* in memory. This makes it a good choice for large objects.
*
* To enabled efficient addition at the beginning and end of the list,
* the list stores a reference to both its head and tail nodes. This
* enables the queue and stack interfaces to be efficiently implemented.
* Other list methods are slow however, as to find element i, the list
* must be traveresed in order, there is no random access.
* Addition of a new node (or removal of the current node) at i is fast
* once i has been found, as changes only need to be made to the nodes either
* side of that node.
*
* To implement the deque interface, we would need a way of removing the tail
* and setting the new value of tail to the node previous. However, it is not
* possible to identify the previous node from tail, it would have to be tracked
* seperately which would make other operations more complex. The DLList is a
* better choice in this case.
*
* Performance:
*     push(x): O(1)
*       pop(): O(1)
*  enqueue(x): O(1)
*  dequeue(x): O(1)
*/

#include <stdexcept>

#include "ds/linked_lists.h"

template <class T>
int SLList<T>::size(){
	return n;
}

template <class T>
void SLList<T>::push(T x){
	Node<T>* u = new Node<T>(x);
	u->next = head;
	head = u;
	if (n == 0){
		tail = u;
	}
	n++;
}

template <class T>
T SLList<T>::pop(){
	if (n == 0){
		throw std::out_of_range("list is empty");
	}

	T x = head->x;
	Node<T>* u = head;
	head = head->next;
	delete u;
	n--;
	if (n==0){
		tail = nullptr;
	}
	return x;
}

/**
* Unlike push, here we add to the tail of
* the list
*/
template <class T>
void SLList<T>::enqueue(T x){
	Node<T>* u = new Node<T>(x);
	if (n == 0){
		head = u;
	} else {
		tail->next = u;
	}
	tail = u;

	n++;
}

template <class T>
T SLList<T>::dequeue(){
	return pop();
}
