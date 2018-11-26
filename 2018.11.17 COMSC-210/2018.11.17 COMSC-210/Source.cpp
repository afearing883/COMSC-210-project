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
void a()
{
	cout << "calling 'void b()'" << endl;
}

void b()
{
	cout << "calling 'void b()'" << endl;
}


int main()
{
	string s;
	int num = 0;
	getline(cin, s);
	stringstream(s) >> num;
	void(*function_array[150])();
	unsigned char error_id[150];
	function_array[0] = a;
	error_id[0] = 3;
	function_array[1] = b;
	error_id[1] = 8;
	return 0;
}