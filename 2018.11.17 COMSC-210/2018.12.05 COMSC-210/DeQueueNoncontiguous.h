#ifndef DEQUEUE_NONCONTIGUOUS_H
#define DEQUEUE_NONCONTIGUOUS_H
#include "Exception.h"
#include <algorithm>

const size_t INITIAL_SIZE = 10;

template<typename Type>
class DeQueueA
{
private:
	template<typename Type>
	struct Node
	{
		size_t index;
		size_t blockSize;
		size_t numberOfElements;
		Type *block;
		Node(size_t size = INITIAL_SIZE, size_t i = 0)
		{
			blockSize = 0;
			index = i;
			block = new Type[size];
		}
	};
	int stackSize;
	int arrayCapacity;
	int ifront;
	int iback;
	Node *array;

public:
	DeQueueA(int i = INITIAL_SIZE)
	{
		ifront = 1;
		iback = 0;
		arrayCapacity = std::max(i, 1);
		stackSize = 0;
		array = new Type[arrayCapacity];
	}
	~DeQueueA()
	{
		delete[] array;
	}

	bool empty() const
	{
		return !stackSize;
	}

	int size() const
	{
		return stackSize;
	}

	Type front() const// return value of the first in
	{
		if (empty())
		{
			throw Exception();
		}
		return array[ifront];
	}

	Type back() const// return value of the last in
	{
		if (empty())
		{
			throw Exception();
		}
		return array[iback];
	}

	void pushBack(const Type& num)
	{
		if (stackSize == arrayCapacity)
		{
			doubleCapacity();
		}
		++iback;
		iback %= arrayCapacity;
		array[iback] = num;
		++stackSize;
	}

	void pushFront(const Type& num)
	{
		if (stackSize == arrayCapacity)
		{
			doubleCapacity();
		}

		if (!ifront)
		{
			ifront = arrayCapacity;
		}
		--ifront;
		++stackSize;
		array[ifront] = num;
	}

	Type popFront()
	{
		Type val = front();
		++ifront;
		ifront %= arrayCapacity;
		--stackSize;
		return val;
	}

	Type popBack()
	{
		Type val = back();
		if (!iback)
		{
			iback = arrayCapacity;
		}
		--iback;
		--stackSize;
		return val;
	}

	void doubleCapacity()
	{
		Type *tmpArray = new Type[2 * arrayCapacity];
		int j = 0;
		for (int i = ifront; i < iback; ++i %= arrayCapacity, ++j)
		{
			tmpArray[j] = array[i];
		}
		iback = j;
		ifront = 0;
		delete[] array;
		array = tmpArray;
		arrayCapacity *= 2;
	}
};
#endif // !DEQUEUE_NONCONTIGUOUS_H

