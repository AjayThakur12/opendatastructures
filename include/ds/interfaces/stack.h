#ifndef I_STACK_H
#define I_STACK_H

template <class T>
class IStack {
public:
	virtual ~IStack() {}

	// Pure virtual methods.
	// Must be defined in implementing classes
	virtual int size() = 0;
	virtual void push(T x) = 0;
	virtual T pop() = 0;
};

#endif
