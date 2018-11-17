// Specification file for the NumberList class
#ifndef LIST_H
#define LIST_H
#include "Exception.h"
#include <iostream>

template<typename Type>
class List
{
private:
	template<typename Type>
	struct ListNode
	{
		Type value;           // The value in this node
		ListNode<Type> *next;  // To point to the next node
		ListNode(const Type& v, ListNode<Type>* lnPtr = nullptr)
		{
			value = v;
			next = lnPtr;
		}
		ListNode()
		{
			next = nullptr;
		}
	};

	ListNode<Type> *head;            // List head pointer
	ListNode<Type> *tail;
	int listSize;
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
		listSize = 0;
	}
	bool empty()
	{
		return !head;
	}
	int size() const
	{
		return listSize;
	}
	~List();

	Type front();
	Type back();
	void pushFront(const Type& num);
	void pushBack(const Type&);

	void displayList() const;
	void insertAt(int, const Type&);
	Type popFront();
	Type popBack();
	int count(const Type&) const;
	void iSort();
};
template<typename Type>
List<Type>::~List()
{
	while (!empty())
	{
		popFront();
	}
	head = nullptr;
	tail = nullptr;
}

template<typename Type>
Type List<Type>::front()
{
	if (empty())
	{
		throw Exception();
	}
	return head->value;
}

template<typename Type>
Type List<Type>::back()
{
	if (empty())
	{
		throw Exception();
	}
	return tail->value;
}


template<typename Type>
void List<Type>::pushFront(const Type& num)
{
	ListNode<Type>* newNode = new ListNode<Type>(num, head);
	head = newNode;
	if (!size())
	{
		tail = newNode;
	}
	++listSize;
}

template<typename Type>
void List<Type>::pushBack(const Type& num)
{
	ListNode<Type>* newNode = new ListNode<Type>(num, nullptr);
	if (!size())
	{
		head = newNode;
	}
	else
	{
		tail->next = newNode;
	}
	tail = newNode;
	++listSize;
}


template<typename Type>
void List<Type>::displayList() const
{
	ListNode<Type> *nodePtr = head;
	while (nodePtr)
	{
		std::cout << nodePtr->value << std::endl;
		nodePtr = nodePtr->next;
	}
}

template<typename Type>
void List<Type>::insertAt(int index, const Type& num)
{
	ListNode<Type> *newNode = new ListNode<Type>(num);
	ListNode<Type> *nodePtr = head;
	ListNode<Type> *previousNode = nullptr;

	if (!nodePtr || !index)
	{
		pushFront(num);
	}
	else if (index >= listSize)
	{
		pushBack(num);
	}
	else
	{
		for (int countPos = 0; countPos < index; ++countPos)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		previousNode->next = newNode;
		newNode->next = nodePtr;
		++listSize;
	}
}


template<typename Type>
Type List<Type>::popFront()
{
	Type frontValue = front();
	ListNode<Type> *nodePtr = head;
	head = head->next;
	delete nodePtr;
	nodePtr = nullptr;
	--listSize;
	return frontValue;
}

template<typename Type>
Type List<Type>::popBack()
{
	Type backValue = back();
	ListNode<Type> *nodePtr = head;
	ListNode<Type> *prevPtr = nullptr;
	while (nodePtr->next)
	{
		prevPtr = nodePtr;
		nodePtr = nodePtr->next;
	}
	if (size() == 1)
	{
		head = nullptr;
	}
	tail = prevPtr;
	delete nodePtr;
	nodePtr = nullptr;
	--listSize;
	return backValue;
}

template<typename Type>
void List<Type>::iSort()
{
	if (empty())
	{
		throw Exception();
	}
	ListNode<Type> *nodePtr = head->next;
	ListNode<Type> *sortTraverse = head;
	ListNode<Type> *sortTraversePrev = nullptr;
	ListNode<Type> *unsortedHead = head->next;
	while (nodePtr)
	{
		sortTraverse = head;
		sortTraversePrev = nullptr;
		while (nodePtr->value > sortTraverse->value)
		{
			sortTraversePrev = sortTraverse;
			sortTraverse = sortTraverse->next;
		}
		if (!sortTraversePrev)
		{
			unsortedHead = nodePtr->next;
			nodePtr->next = head;
			head = nodePtr;
			nodePtr = unsortedHead;
		}
		else
		{
			unsortedHead = nodePtr->next;
			nodePtr->next = sortTraverse;
			sortTraversePrev->next = nodePtr;
			nodePtr = unsortedHead;
		}
	}
}

template<typename Type>
int List<Type>::count(const Type& n) const
{
	int count = 0;
	for (ListNode<Type> *ptr = head; ptr; ptr = ptr->next)
	{
		count += (n == ptr->value);
	}
	return count;
}





#endif