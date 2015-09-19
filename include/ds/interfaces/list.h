#ifndef I_LIST_H
#define I_LIST_H

template <class T>
class IList {
public:
	virtual ~IList() {}

	// Pure virtual methods.
	// Must be defined in implementing classes
	virtual int size() = 0;
	virtual T get(int i) = 0;
    virtual T set(int i, T x) = 0;
	virtual void add(int i, T x) = 0;
	virtual T remove(int i) = 0;
};

#endif
