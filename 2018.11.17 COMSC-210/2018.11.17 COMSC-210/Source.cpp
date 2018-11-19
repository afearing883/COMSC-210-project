#include "PriorityQueue.h"
#include "Heap.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

template<typename Type>
void printArr(Type *arr, const int size, ostream& os = cout)
{
	for (int i = 0; i < size; ++i)
	{
		os << arr[i] << " ";
	}

	os << endl;
	return;
}
template<typename Type>
void printVect(const vector<Type>& v, ostream& os = cout)
{
	for (const Type& i : v)
	{
		os << i << " ";
	}
	os << endl;
}



const int PRIORITY_LEVELS = 4;



void priorityQueueTest(const string& filename)
{
	ifstream inFile(filename);
	string s, name;
	int priorityLevel = 0;
	PriorityQueue<string> pq(PRIORITY_LEVELS);
	if (inFile)
	{
		while (getline(inFile, s))
		{
			stringstream(s) >> priorityLevel >> name;
			pq.push(priorityLevel, name);
		}

	}
	while (!pq.empty())
	{
		cout << pq.pop() << endl;
	}
}


int main()
{
	priorityQueueTest("schedule.txt");
	Heap<int> h;
	h.push(3);
	h.push(17);
	h.push(43);
	h.push(4);
	h.push(2);
	cout << h.pop() << endl;
	cout << h.pop() << endl;
	cout << h.pop() << endl;
	cout << h.pop() << endl;
	return 0;
}