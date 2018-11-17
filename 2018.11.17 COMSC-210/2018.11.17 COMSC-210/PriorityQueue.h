#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "QueueA.h"
#include <vector>
#include "Exception.h"

template <typename Type>
class PriorityQueue
{
private:
	int size;
	std::vector<QueueA<Type>> queueVector;
public:
	PriorityQueue(int p) : size = 0
	{
		queueVector.resize(p);
	}
	void push(int priorityLevel, const Type& value)
	{
		if (priorityLevel >= queueVector.size())
		{
			throw Exception();
		}
		queueVector.at(priorityLevel).push(value);
	}
	Type pop()
	{
		if (empty())
		{
			throw Exception();
		}
		int i = 0;
		for (; scheduleArray.at(i).empty(); ++i)
		{
		}
		--size;
		return queueVector.at(i).pop();
	}
	bool empty()
	{
		bool emptySchedule = true;
		for (int i = 0; i < queueVector.size() && emptySchedule = scheduleArray.at(i).empty(); ++i)
		{
		}
		return emptySchedule;
	}
};



#endif // !SCHEDULER_H
