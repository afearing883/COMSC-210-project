#ifndef HEAP_H
#define HEAP_H
#include "Exception.h"
#include <cmath>
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

	HeapNode<Type>* root;
	HeapNode<Type>* lastNodeInsertedPtr;
	void removeLastInsertedNode(int);
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
	void swapValues(HeapNode<Type>*, HeapNode<Type>*);
	Type pop();
};


template<typename Type>
void Heap<Type>::removeLastInsertedNode(int sizeAfterPop)
{
	HeapNode<Type>* nodePtr = nullptr;
	HeapNode<Type>* nextNodePtr = nullptr;
	HeapNode<Type>* oldLastNodeInsertedPtr = lastNodeInsertedPtr;
	if (log2(sizeAfterPop + 1) == static_cast<int>(log2(sizeAfterPop + 1)))//perfect tree. last inserted is now on level above OR only root node
	{
		nodePtr = root;
		while (nextNodePtr = nodePtr->rightChildPtr)
		{
			nodePtr = nextNodePtr;
		}
		if (lastNodeInsertedPtr != root)
		{
			lastNodeInsertedPtr->parentPtr->leftChildPtr = nullptr;
		}
		lastNodeInsertedPtr = nodePtr;
	}
	else if ((sizeAfterPop) % 2)//complete tree after removal of old last inserted node. removing from leftChild
	{
		nodePtr = lastNodeInsertedPtr;
		while (nodePtr == nodePtr->parentPtr->leftChildPtr)
		{
			nodePtr = nodePtr->parentPtr;
		}
		nodePtr = nodePtr->parentPtr->leftChildPtr;
		while (nextNodePtr = nodePtr->rightChildPtr)
		{
			nodePtr = nextNodePtr;
		}
		lastNodeInsertedPtr->parentPtr->leftChildPtr = nullptr;
		lastNodeInsertedPtr = nodePtr;
	}
	else//incomplete tree after removal of old last inserted node. removing from rightChild
	{
		lastNodeInsertedPtr->parentPtr->rightChildPtr = nullptr;
		lastNodeInsertedPtr = lastNodeInsertedPtr->parentPtr->leftChildPtr;
	}
	delete oldLastNodeInsertedPtr;
	oldLastNodeInsertedPtr = nullptr;
	nodePtr = nullptr;
	nextNodePtr = nullptr;
}
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

	if (node1Ptr == root)
	{
		root = node2Ptr;
	}
	else if (node2Ptr == root)
	{
		root = node1Ptr;
	}

}

template<typename Type>
void Heap<Type>::swapValues(HeapNode<Type>* node1Ptr, HeapNode<Type>* node2Ptr)
{
	Type tempValue = node2Ptr->value;
	node2Ptr->value = node1Ptr->value;
	node1Ptr->value = tempValue;
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




template<typename Type>
Type Heap<Type>::pop()
{
	if (empty())
	{
		throw Exception();
	}
	Type val = root->value;
	HeapNode<Type>* nodePtr = root;
	HeapNode<Type>* nextNodePtr = nullptr;

	removeLastInsertedNode(heapSize - 1);

	while ((nextNodePtr = ((nodePtr->rightChildPtr && nodePtr->leftChildPtr) && (nodePtr->rightChildPtr->value > nodePtr->leftChildPtr->value)) || !nodePtr->rightChildPtr ? nodePtr->leftChildPtr : nodePtr->rightChildPtr) && nextNodePtr->value < nodePtr->value)
	{
		swapValues(nodePtr, nextNodePtr);
		nodePtr = nextNodePtr;
	}

	--heapSize;
	return val;
}


#endif // !HEAP_H
