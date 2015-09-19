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
