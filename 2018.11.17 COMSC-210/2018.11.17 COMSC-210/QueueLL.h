#ifndef QUEUELL_H
#define QUEUELL_H
#include "List.h"
template<typename Type>
class QueueLL
{
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
	Type front()
	{
		return list.front();
	}
	void push(const Type& num)
	{
		list.pushBack(num);
	}
	Type pop()
	{
		return list.popFront();
	}
};


#endif // !QUEUE_H
