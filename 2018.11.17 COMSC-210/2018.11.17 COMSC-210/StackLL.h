#ifndef STACKLL_H
#define STACKLL_H
#include "List.h"

template<typename Type>
class StackLL {
private:
	List<Type> list;
public:
	bool empty() const
	{
		return list.empty();
	}
	int size() const
	{
		return list.size();
	}
	Type top()
	{
		return list.front();
	}
	void push(const Type & num)
	{
		list.pushFront(num);
	}
	Type pop()
	{
		return list.popFront();
	}
};

#endif // !STACKLL_H
