#ifndef DEQUEUELL_H
#define DEQUEUELL_H
#include "List.h"

template<typename Type>
class DeQueueLL
{
private:
	List<Type> list;
public:
	int size() const
	{
		return list.size();
	}
	bool empty() const
	{
		return list.empty();
	}
	Type top()
	{
		return list.front();
	}
	Type bottom()
	{
		return list.back();
	}
	void pushFront(const Type & num)
	{
		list.pushFront(num);
	}
	void pushBack(const Type & num)
	{
		list.pushBack(num);
	}
	Type popFront()
	{
		return list.popFront();
	}
	Type popBack()
	{
		return list.popBack();
	}

};
#endif // !DEQUEUELL_H
