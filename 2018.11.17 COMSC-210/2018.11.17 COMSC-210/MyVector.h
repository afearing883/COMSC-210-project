#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <algorithm>
#include <cstdint>
#include <cstring>
/*
int main() {
	//simple usage
	char source[] = "once upon a midnight dreary...", dest[4];
	std::memcpy(dest, source, sizeof dest);
	for (char c : dest)
	{
		std::cout << c << '\n\';
	}
	std::is_trivially_copyable<MyVector> ...
}

*/


class Exception
{

};

template <typename Type>
class MyVector
{
private:
	int arraySize;
	int arrayCapacity;
	int iback;
	Type *array;
	static const int DEFAULT_SIZE = 10;
public:
	MyVector(int i = DEFAULT_SIZE)
	{
		iback = -1;
		arrayCapacity = std::max(i, 0) + DEFAULT_SIZE;
		arraySize = 0;
		array = new Type[arrayCapacity];
	}
	MyVector(const int i, const Type& value) :MyVector(i)
	{
		for (int j = 0; j < i; ++j)
		{
			array[j] = value;
		}
	}
	MyVector(const MyVector& v) : MyVector(v.capacity())
	{
		for (; arraySize < v.size(); ++arraySize)
		{
			array[arraySize] = v.getAt(arraySize);
		}
		iback = arraySize - 1;
	}
	~MyVector()
	{
		delete[] array;
		array = nullptr;
	}
	bool empty() const
	{
		return !arraySize;
	}
	void clear()
	{
		delete[] array;
		array = new Type[DEFAULT_SIZE];
		iback = -1;
		arrayCapacity = DEFAULT_SIZE;
		arraySize = 0;
	}
	int size() const
	{
		return arraySize;
	}
	int capacity() const
	{
		return arrayCapacity;
	}
	Type &front() const// return value of the first in
	{
		if (empty())
		{
			throw Exception();
		}
		return array[0];
	}
	Type &back() const// return value of the last in
	{
		if (empty())
		{
			throw Exception();
		}
		return array[iback];
	}
	void pushBack(const Type& num)
	{
		if (arraySize == arrayCapacity)
		{
			doubleCapacity();
		}
		++iback;
		array[iback] = num;
		++arraySize;
	}
	Type popBack()
	{
		Type val = back();
		--iback;
		--arraySize;
		return val;
	}

	void reserve(int newCap)
	{

	}
	void doubleCapacity()
	{
		Type *tmpArray = new Type[2 * arrayCapacity];
		for (int i = 0; i <= iback; ++i)
		{
			tmpArray[i] = array[i];
		}
		delete[] array;
		array = tmpArray;
		arrayCapacity *= 2;
	}
	Type &at(const int i)
	{
		if (empty() || iback < i)
		{
			throw Exception();
		}
		return array[i];
	}
	// void setAt(const int i, const Type& value)
	// {
	// 	if (empty() || i < i)
	// 	{
	// 		throw Exception();
	// 	}
	// 	array[i] = value;
	// }


	void insert(const int i, const Type& value)
	{
		if (size() < i)
		{
			throw Exception();
		}
		else if (size() == i)
		{
			pushBack(value);
		}
		else
		{
			++arraySize;
			if (arraySize == arrayCapacity)
			{
				doubleCapacity();
			}

			Type tmp1 = array[i];
			Type tmp2;
			for (int j = i; j < arraySize; ++j) {
				tmp2 = array[j + 1];
				array[j + 1] = tmp1;
				tmp1 = tmp2;
			}
		}

	}
	MyVector& MyVector::operator=(const vector& a)
	{
		Type* p = new Type[a.capacity()];
		if (this == &a)
		{
			return *this;
		}
		if (a.sz <= space)
		{
			for (int i = 0; i < a.sz; ++i)
			{
				elem[i] = a.elem[i];
				space += sz - a.sz;
				space
					sz = a.sz;
				return *this;
			}
		}
		for (int i = 0; i < a.sz; ++i)
		{
			array[i] = a.at[i];
		}
		delete[] array;
		array = p;
		arraySize = a.size();
		arrayCapacity = a.capacity();
		
		return *this;
	}
};


#endif