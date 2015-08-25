#include <iostream>
#include <stdexcept>

using namespace std;


template <class T>
class Array {
	T *a;
	int l;

public:
	// Default constructor
	Array() {
		a = new T[1];
		l = 1;
	}

	Array(int len) {
		a = new T[len];
		l = len;
	}

	~Array() {
		delete[] a;
	}

	// Copy constructor
	Array<T>& operator=(Array<T> &b){
		if (a != nullptr) delete[] a;
		a = b.a;
		b.a = nullptr;
		l = b.l;
		return *this;
	}

	T& operator[](int i) {
		if (i >= 0 && i < l){
			return a[i];
		} else {
			throw std::invalid_argument("index outside range");
		}
	}

	int length(){
		return l;
	}
};


template <class T>
class ArrayStack {
	Array<T> a;
	int n = 0;

	void resize(){
		Array<T> b(max(2*n, 1));
		for (int i=0; i < n; i++){
			b[i] = a[i];
		}
		a = b;
	}

public:
	int size(){
		return n;
	}

	T get(int i){
		return a[i];
	}

    T set(int i, T x){
    	T y = a[i];
    	a[i] = x;
    	return y;
    }

	void add(int i, T x){
		if (n+1 > a.length()) resize();
		for (int j = n; j > i; j--) {
			a[j] = a[j-1];
		}
		a[i] = x;
		n++;
	}

	T remove(int i){
		T x = a[i];
		for (int j = i; j < n-1; j++){
			a[j] = a[j+1];
		}
		n--;
		if (a.length() >= 3*n) resize();

		return x;
	}
};





int main() {
	// your code goes here
	int i = 3;
	Array<int> a(i);

	a[0] = 1;
	a[1] = 2;
	a[2] = 5;

	cout << "hello. x is " << a[2] << endl;


	ArrayStack<int> as;
	as.add(0, 1);
	as.add(0, 2);
	as.add(0, 3);

	cout << "ArrayStack value at 0 is " << as.get(0) << endl;
	cout << "ArrayStack value at 1 is " << as.get(1) << endl;
	cout << "ArrayStack value at 2 is " << as.get(2) << endl;

	as.set(0,0);

	cout << "ArrayStack value at 0 is " << as.get(0) << endl;

	as.remove(0);

	cout << "ArrayStack value at 0 is " << as.get(0) << endl;

	return 0;
}
