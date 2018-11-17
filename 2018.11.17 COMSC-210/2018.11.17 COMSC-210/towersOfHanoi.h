#ifndef TOWERS_OF_HANOI_H
#define TOWERS_OF_HANOI_H

#include <iostream>
void solveTowers(int count, char source, char dest, char spare)
{
	if (count)
	{
		solveTowers(count - 1, source, spare, dest);
		std::cout << "move disk " << count << " from " << source << " to " << dest << std::endl;
		solveTowers(count - 1, spare, dest, source);
	}
}

#endif // !TOWERS_OF_HANOI_H
