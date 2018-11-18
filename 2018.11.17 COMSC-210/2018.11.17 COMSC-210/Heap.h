#ifndef HEAP_H
#define HEAP_H
#include "Exception.h"

template<typename Type>
class Heap
{
private:
	template<typename Type>
	struct HeapNode
	{
		Type value;
		HeapNode<Type>* leftChildPtr;
		HeapNode<Type>* rightChildPtr;
		HeapNode<Type>* parentPtr;
		HeapNode<Type>* lastInserted;
		HeapNode(const Type& v, HeapNode<Type>* p = nullptr, HeapNode<Type>* l = nullptr, HeapNode<Type>* r = nullptr, HeapNode<Type>* last = nullptr)
		{
			value = v;
			parentPtr = p;
			leftChildPtr = l;
			rightChildPtr = r;
			lastInserted = last;
		}
	};
	int heapSize;
	
	HeapNode<Type>* lastInsertedPtr;
	HeapNode<Type>* root;
public:
	Heap()
	{
		root = nullptr;
		heapSize = 0;
	}
	int size()
	{
		return heapSize;
	}
	bool empty()
	{
		return !size();
	}
	void push(const Type&);
	void swapNodes(HeapNode<Type>*, HeapNode<Type>*);
};

template<typename Type>
void Heap<Type>::swapNodes(HeapNode<Type>* node1Ptr, HeapNode<Type>* node2Ptr)
{

	// easiest thing would be swapping values, but can't because we don't know how large each value is. O(n) rather than O(1)
	HeapNode<Type>* tempPtr;
	tempPtr = node1Ptr->leftChildPtr;
	node1Ptr->leftChildPtr = node2Ptr->leftChildPtr;
	node2Ptr->leftChildPtr = tempPtr;

	tempPtr = node1Ptr->rightChildPtr;
	node1Ptr->rightChildPtr = node2Ptr->rightChildPtr;
	node2Ptr->rightChildPtr = tempPtr;

	tempPtr = node1Ptr->parentPtr;
	node1Ptr->parentPtr = node2Ptr->parentPtr;
	node2Ptr->parentPtr = tempPtr;

	if (node1Ptr == head)
	{
		head = node2Ptr;
	}
	else if (node2ptr == head)
	{
		head = node1Ptr;
	}

}


template<typename Type>
void Heap<Type>::push(const Type& v)
{
	HeapNode<Type>* newNode = new HeapNode<Type>(v);
	HeapNode<Type>* nodePtr;
	newNode->leftChildPtr = root->leftChildPtr;
	newNode->rightChildPtr = root->rightChildPtr;

	if (empty())
	{
		root = new HeapNode<Type>(v);
	}
	else
	{

	}
	while (nodePtr->leftChildPtr || nodePtr->rightChildPtr)
	{
		if (nodePtr->leftChildPtr && nodePtr->leftChildPtr->value < nodePtr->value)
		{
			swapNodes(nodePtr->leftChildPtr, nodePtr);
		}
		else if (nodePtr->rightChildPtr && nodePtr->rightChildPtr->value < nodePtr->value)
		{
			swapNodes(nodePtr->rightChildPtr, nodePtr);
		}
	}
}

#endif // !HEAP_H
