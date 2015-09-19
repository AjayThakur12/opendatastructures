/**
* First-in, first-out queue implemented with an array.
*
* Data is added at one end of the array and removed from
* the other end. If the array were infinitely long,
* a series of add() and remove() calls would cause
* a 'window' of data elements to gradually shift
* along the length of the array.
*
* Here an array of infinite size is simulated by using
* an array of fixed with modulo arithmetic applied to
* find the location of a particular element.
*
* The beginning of the data window is tracked in variable 'j',
* and the size of the window is tracked in 'n'.
*
* With a fixed size array of 3 elements, and initial values
* of j and n of 0:
*
*   _ _ _  (j=0, n=0)  add('a')
*   a _ _  (j=0, n=1)  add('b')
*   a b _  (j=0, n=2)  add('c')
*   a b c  (j=0, n=3)  remove()
*   _ b c  (j=1, n=2)  remove()
*   _ _ c  (j=2, n=1)  add('d')   'd' will be added at (2+1)%3 = 0
*   d _ c  (j=2, n=2)  add('e')   'e' will be added at (2+2)%3 = 1
*   d e c  (j=2, n=3)
*
* The window moves along and new data wraps around to the available
* positions at the start of the array. In practice this sequence
* would be different due to the dynamic resizing of the array, but
* the principle is the same.
*
* This approach avoids the expensive data moving operations that would
* be encountered if an ArrayStack were used for this implementation.
*
* The backing array will resize to accomodate extra data if all elements
* are full.
*
* ArrayQueue doesn't implement list methods.
* In order to allow random access to elements in the list,
* all of the ArrayDeque functionality needs to be implemented.
* This means the structure can only be used as a strict queue.
* If peeking or queue jumping behaviour is needed, ArrayDeque
* provides that interface.
*
* Performance:
*
*    enqueue(x): O(1)
*    dequeue(): O(1)
*/
#include "ds/array_lists.h"


/**
* During resizing, j is reset to 0 and the first data element will
* be moved to the beginning of the new backing array
*/
template <class T>
void ArrayQueue<T>::resize(){
	Array<T> b(std::max(1, 2*n));
	for (int k=0; k < n; k++){
		b[k] = a[(j+k) % a.length()];
	}
	a = b;
	j = 0;
}


template <class T>
int ArrayQueue<T>::size(){
	return n;
}


template <class T>
void ArrayQueue<T>::enqueue(T x){
	if (n+1 > a.length()) resize();
	a[(j+n) % a.length()] = x;
	n++;
}


template <class T>
T ArrayQueue<T>::dequeue(){
	// What if the queue is empty?
	T x = a[j];
	j = (j+1) % a.length();
	n--;
	if (a.length() >= 3*n) resize();
	return x;
}
