#include <sstream>
#include <stdexcept>

#include "ds/array.h"

/**
* A simple structure that tracks the length of its C-style array.
*
* Attempts to access elements outside the range of the array
* result in std::invalid_argument exception being thrown.
*
* The destructor ensures that the memory for the data array is released
* when the container goes out of scope.
*
* This structure is used internally by several List and Queue implementations.
*
* std::array provides similar benefits.
*/

template <class T>
Array<T>::Array() {
	a = new T[1];
	l = 1;
}

template <class T>
Array<T>::Array(int len) {
	a = new T[len];
	l = len;
}

template <class T>
Array<T>::~Array() {
	delete[] a;
}

// Copy constructor
template <class T>
Array<T>& Array<T>::operator=(Array<T> &b){
	if (a != nullptr) delete[] a;
	a = b.a;
	b.a = nullptr;
	l = b.l;
	return *this;
}

/**
* Provides access to the data for both reading and writing.
* Data is returned by reference, and since data is stored consecutively
* in a C-style array, pointer artithmetic can also be used to move between elements.
* FastArrayStack::resize shows an example of this.
*/
template <class T>
T& Array<T>::operator[](int i) {
	if (i >= 0 && i < l){
		return a[i];
	} else {
		throw std::out_of_range("index is outside array bounds");
	}
}

/**
* Instantiating classes should be able to query the length value
* but not change it.
*/
template <class T>
int Array<T>::length(){
	return l;
}

template <class T>
std::string Array<T>::draw(){
	std::stringstream ss;
	for (int i = 0; i < l; i++){
		ss << a[i] << " ";
	}
	return ss.str();
}
