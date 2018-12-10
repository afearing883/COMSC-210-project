#include "PriorityQueue.h"
#include "Heap.h"
#include "HashTable.h"
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
const char DELIMITER = ',';
const size_t FILE_ENTRIES = 50000;
const string FILENAME = "usdata50000C.csv";
void fillHashTable(ifstream& inFile, HashTable& ht)
{
	string s;
	stringstream ss;
	getline(inFile, s);//header line
	for (long long unsigned posInFile = inFile.tellg(); getline(inFile, s); posInFile = inFile.tellg())
	{
		ss << s;
		for (size_t entry = 0; entry <= 8 && getline(ss, s, DELIMITER); ++entry)
		{
		}
		ss.clear();
		ss.str("");
		ht.push(s, posInFile);
	}
}

void getInfo(ifstream& inFile, HashTable& ht)
{
	string s;// = "504 - 621 - 8927";

	while (getline(cin, s))
	{
		inFile.clear();
		inFile.seekg(ht.retrieve(s));
		getline(inFile, s);
		cout << s << endl;
	}
}


int main()
{


	return 0;
}