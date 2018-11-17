#ifndef QUEUEA_H
#define QUEUEA_H
#include "DeQueueA.h"

template<typename Type>
class QueueA
{
private:
	DeQueueA<Type> queue;
public:
	bool empty() const
	{
		return queue.empty();
	}
	int size() const
	{
		return queue.size();
	}
	Type top()
	{
		return queue.back();
	}
	void push(const Type& num)
	{
		queue.pushFront(num);
	}
	Type pop()
	{
		return queue.popBack();
	}

};

#endif // !STACK_H
