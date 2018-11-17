/***************************************************************
Problem:      Assignment Stacks and Queues
Question:    Basic ADTs
In the class you learned and implemented 4 basic ADTs:
1. Single Linked List
2. Stack:
a. Stack using your Linked List
b. Stack using an array
3. Queue:
a. Queue using your Linked List
b. Queue using an array
4. DeQueue:
a. DeQueue using your Linked List
b. DeQueue using an array
Cleanup your code that you wrote in class, make all classes as templates (for this you will need to have
only one header file for each ADT that includes all the function.. in other words: class’s cpp file contents
should be copied to the .h file)
You must submit the following:
List.h Singly linked list from class fully implemented
StackLL.h Stack using your Linked List
StackA.h Stack using an array
QueueLL.h Queue using your Linked List
QueueA.h Queue using an array
DeQueueLL.h DeQueue using your Linked List
DeQueueA.h DeQueue using an array
This is not new implementation; this is what you worked on in-class.
You grade is split between your work and your review of the other person’s work


Name:  Andrew Fearing
ID: 1549883
Date: 09/30/18

Status:  complete
****************************************************************/


#include <iostream>
#include <vector>
#include "QueueA.h"
#include "Scheduler.h"
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

void scheduler()
{
	ifstream inFile;
	inFile.open("schedule.txt");
	string s, processName;
	int priorityLevel = 0;
	const int PRIORITY_LEVELS = 4;
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


int main()
{
	scheduler();
	return 0;
}