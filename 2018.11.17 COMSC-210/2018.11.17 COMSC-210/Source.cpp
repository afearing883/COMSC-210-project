#include "PriorityQueue.h"
#include "List.h"
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
void scheduler()
{
	ifstream inFile;
	inFile.open("schedule.txt");
	string s, processName;
	int priorityLevel = 0;

	QueueA<string> scheduleArray[PRIORITY_LEVELS];
	if (inFile)
	{
		while (getline(inFile, s))
		{
			stringstream(s) >> priorityLevel >> processName;
			scheduleArray[priorityLevel].push(processName);
		}
		for (int i = 0; i < PRIORITY_LEVELS; ++i)
		{
			while (!scheduleArray[i].empty())
			{
				cout << scheduleArray[i].pop() << endl;
			}
		}
	}
	else
	{
		cout << "file not open" << endl;
	}
	inFile.close();
}


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
		cout << pq.pop();
	}
}


int main()
{
	//scheduler();
	priorityQueueTest("schedule.txt");
	List<int> l;
	l.pushBack(3);
	l.pushBack(4);
	l.popBack();
	l.displayList();
	return 0;
}