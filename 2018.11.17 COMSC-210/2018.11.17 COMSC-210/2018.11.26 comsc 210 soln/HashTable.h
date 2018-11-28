#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <vector>

const long long unsigned C = 581869333;
/*
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
			size_t hashIndex; // hash of phone number 1945
			long long unsigned fileIndex; //index of line within file;
		};
		NodeInfo info;
		int counter;
		HashNode()
		{
			counter = 0;
		}
	};
	std::vector<HashNode> list;

	size_t hash(long long unsigned, long long unsigned);
public:
	HashTable(size_t s)
	{
		list.resize(s);
	}
	void push(long long unsigned);
};

size_t HashTable::hash(long long unsigned val, long long unsigned m)
{
	long long unsigned shift = (32 - m) / 2;
	return ((C*val) >> shift)&((1 << m) - 1);//(1 shifted left by m) (-1 flips all the bits except the most significant)
}


void HashTable::push(long long unsigned val)
{

}


#endif // !HASH_TABLE_H



