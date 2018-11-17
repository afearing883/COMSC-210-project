#ifndef HEAP_H
#define HEAP_H
#include "Exception.h"

template<typename Type>
class Heap
{
private:
	int size;
	template<typename Type>
	struct HeapNode
	{
		Type value;
		HeapNode<Type>* leftChildPtr;
		HeapNode<Type>* rightChildPtr;
		HeapNode<Type>* parentPtr;
		HeapNode(const Type& v, HeapNode<Type>* p = nullptr, HeapNode<Type>* l = nullptr, HeapNode<Type>* r = nullptr)
		{
			value = v;
			parentPtr = p;
			leftChildPtr = l;
			rightChildPtr = r;
		}
	};
	HeapNode<Type>* root;
public:
	Heap()
	{
		root = nullptr;
		size = 0;
	}
	void push(const Type& v);
};

void Heap::push(const Type& v)
{

}

#endif // !HEAP_H
