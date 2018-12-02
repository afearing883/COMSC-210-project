#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <vector>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <cctype>
#include "Exception.h"
const long long unsigned C = 581869333;
/*
const unsigned int C = 581869333;
unsigned int hash_M(unsigned n, unsigned m)

{
	unsigned shift = (32 - m) / 2;
	return((C*n) >> shift)&((1 << m) - 1);//(1 shifted left by m) (-1 flips all the bits except the most significant)
}


//dealing with signed ints
int hash_M(int n, int M)
{
	int hash_value = n % M;
	return (hash_value >= 0) ? hash_value : hash_value + M;
}
*/
class HashTable
{
private:
	struct HashNode
	{
		struct NodeInfo
		{
			long long unsigned value; //phone number 555-487-1945
			size_t hashVal; // hash of phone number 1945
			long long unsigned fileIndex; //index of line within file;
			NodeInfo()
			{
				value = 0;
				fileIndex = 0;
			}
		};
		NodeInfo info;
		int counter;
		bool occupied;
		HashNode()
		{
			counter = 0;
			occupied = false;
		}
	};
	std::vector<HashNode> list;
	size_t hashDigits; // 10. want middle 4
	size_t hash(const std::string&);
	size_t findNextEmpty(size_t);
	std::string readNumber(const std::string&);
	size_t findValue(const size_t, long long unsigned);
public:
	HashTable(size_t s, size_t d)
	{
		list.resize(s);
		hashDigits = static_cast<int>(log10(s)) + 1;

	}
	void push(std::string, long long unsigned);//input: phone number and position in file. stores phone number, hash, and position in file.
	long long unsigned retrieve(std::string);//input: phone number. returns position of phone number line in file
};

size_t HashTable::hash(const std::string& s)
{
	size_t h = std::string::npos;
	std::stringstream(s.substr((s.size() - hashDigits) / 2, hashDigits)) >> h;
	h %= list.size();// or just make a larger heap. idk
	return h;
}



std::string HashTable::readNumber(const std::string& s)
{
	std::string newNumber;
	for (char c : s)
	{
		if (isalnum(c))
		{
			newNumber.append(1, c);
		}

	}
	return newNumber;
}

size_t HashTable::findNextEmpty(size_t currentPos)
{
	size_t newOffset = 2;
	for (; list.at(currentPos).occupied; currentPos += newOffset, currentPos %= list.size(), ++newOffset)
	{
	}
	return currentPos;
}

size_t HashTable::findValue(const size_t h, long long unsigned val)
{
	size_t currentPos = h;
	size_t newOffset = 2;
	bool found = false;
	for (unsigned hashMatchCount = 0; (found = (val != list.at(currentPos).info.value)) && hashMatchCount != list.at(h).counter; hashMatchCount += (h == list.at(currentPos).info.hashVal), currentPos += newOffset, currentPos %= list.size(), ++newOffset)
	{
	}
	return found ? currentPos : std::string::npos;
}
void HashTable::push(std::string val, long long unsigned filePos)
{
	val = readNumber(val);
	size_t h = hash(val);
	++list.at(h).counter;
	size_t pos = findNextEmpty(h);
	list.at(pos).occupied = true;
	std::stringstream(val) >> list.at(pos).info.value;
	list.at(pos).info.fileIndex = filePos;
	list.at(pos).info.hashVal = h;

}



long long unsigned HashTable::retrieve(std::string val)
{
	val = readNumber(val);
	long long unsigned valInt = 0;
	std::stringstream(val) >> valInt;
	size_t h = hash(val);
	size_t pos = findValue(h, valInt);
	if (pos == std::string::npos)
	{
		throw Exception();
	}
	--list.at(h).counter;
}

#endif // !HASH_TABLE_H



