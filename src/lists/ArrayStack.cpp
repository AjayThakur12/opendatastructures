/**
* Dynamically sized array offering constant time access to data.
*
* This data structure is very efficient if elements are only being
* added and removed from the end of the array, eg a LIFO queue could be
* implemented as:
*   push(x) -> add(n, x)
*   pop() -> remove(n-1)
*
* Changing the size of the backing array can be slow if the modification
* happens near the start of the array, as all subsequent elements
* must be shifted either to accomodate the new data or to overwrite
* the removed value.
*
* Performance:
*
*      get(i): O(1)
*    set(i,x): O(1)
*    add(i,x): O(n-i), ie worst performance adding to beginning of array
*      remove: O(n-i), ie worst performance removing from beginning of array
*
* std::vector provides similar benefits.
*/

#include "ds/lists.h"


/**
* Since the underlying array can't change size,
* a new array is created that has enough room to
* hold twice the current number of elements.
*
* Data stored in the old Array will be released
* by its destructor.
*
* Resizing is an expensive operation, but since it is unlikely to
* run on every call to add/remove it has little effect on the
* average operation, and the amortized cost for m operations is O(1).
*/
template <class T>
void ArrayStack<T>::resize(){
	Array<T> b(std::max(2*n, 1));
	for (int i=0; i < n; i++){
		b[i] = a[i];
	}
	a = b;
}

template <class T>
int ArrayStack<T>::size(){
	return n;
}

/**
* Bounds checking is handled by the backing array
*/
template <class T>
T ArrayStack<T>::get(int i){
	return a[i];
}

/**
* Bounds checking is handled by the backing array
*/
template <class T>
T ArrayStack<T>::set(int i, T x){
	T y = a[i];
    a[i] = x;
    return y;
}

/**
* If there is no room for the new element, the underlying array will be resized.
*/
template <class T>
void ArrayStack<T>::add(int i, T x){
	if (n+1 > a.length()) resize();
	for (int j = n; j > i; j--) {
		a[j] = a[j-1];
	}
	a[i] = x;
	n++;
}


/**
* If the removal operation leaves the array three times larger than necessary
* it will be resized to be twice as large as necessary, freeing up memory
* but leaving room for expansion.
*/
template <class T>
T ArrayStack<T>::remove(int i){
	T x = a[i];
	for (int j = i; j < n-1; j++){
		a[j] = a[j+1];
	}
	n--;
	if (a.length() >= 3*n) resize();

	return x;
}
