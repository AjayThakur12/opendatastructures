#ifndef I_SORTED_SET_H
#define I_SORTED_SET_H

template <class T>
class ISortedSet {
public:
	virtual ~ISortedSet() {}

	// Pure virtual methods.
	// Must be defined in implementing classes
	virtual int size() = 0;
	virtual bool add(T x) = 0;
	virtual T remove(T x) = 0;
	virtual T find(T x) = 0;
};

#endif
