#ifndef STACKA_H
#define STACKA_H
#include "DeQueueA.h"
template<typename Type>
class StackA
{
private:
	DeQueueA<Type> stack;
public:
	bool empty()
	{
		return stack.empty();
	}
	int size()
	{
		return stack.size();
	}
	Type top()
	{
		return stack.front();
	}
	void push(const Type& num)
	{
		stack.pushFront(num);
	}
	Type pop()
	{
		return stack.popFront();
	}
};


#endif STACKA_H