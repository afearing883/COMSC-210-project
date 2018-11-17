#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include <vector>

const int BASE = 10;


void radishSort(std::vector<int> & vect)
{
	std::vector<std::vector<int>> bucket(BASE);
	bool goAgain = true;
	for (int i = 1; goAgain && i < INT_MAX; i *= 10)
	{
		goAgain = false;
		for (int x : vect)
		{
			bucket.at(abs(x / i % BASE)).push_back(x);
			goAgain || (goAgain = x / (i * 10));
		}

		vect.clear();
		for (std::vector<int> & v : bucket)
		{
			for (int x : v)
				vect.push_back(x);
			v.clear();
		}
	}

	std::vector<int> negsSorted(vect.size());		// handles negatives
	for (int backwardI = vect.size() - 1, i = 0, j = backwardI; backwardI >= 0; --backwardI)
	{
		negsSorted.at(vect.at(backwardI) >= 0 ? j-- : i++) = vect.at(backwardI);
	}
	vect = negsSorted;

	return;
}


#endif