#ifndef MERGE_SORT_H
#define MERGE_SORT_H
#include <algorithm>

template<typename Type>
void merge(Type items[], int low, const int middle1, int middle2, const int high)
{
	int size = high - low + 1;
	int initialLow = low;
	Type* workingArray = new Type[size];

	for (int workingIndex = 0; workingIndex < size; ++workingIndex)
	{
		workingArray[workingIndex] = (middle2 > high) || ((low <= middle1) && (items[low] < items[middle2])) ? items[low++] : items[middle2++];
	}
	//for (int i = 0; i < size; ++i)
	//{
	//	items[initialLow + i] = workingArray[i];
	//}
	//memcpy(items + initialLow, workingArray, size*sizeof(Type));
	std::copy(workingArray, workingArray + size, items + initialLow);
	delete[] workingArray;
}

template<typename Type>
void mergeSort(Type items[], int low, int high)
{
	if ((high - low) >= 1)
	{
		int middle1 = (low + high) / 2;
		int middle2 = middle1 + 1;

		mergeSort(items, low, middle1);
		mergeSort(items, middle2, high);

		merge(items, low, middle1, middle2, high);
	}
}
#endif // !MERGE_SORT_H
