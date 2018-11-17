#ifndef QUICK_SORT_H
#define QUICK_SORT_H



template<typename Type>
inline void swapValues(Type arr[], int index1, int index2)
{
	Type tempValue;
	tempValue = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = tempValue;
}

template<typename Type>
int partition(Type *arr, int low, int high)
{
	Type pivot;
	int end = high;
	int midpoint = (high + low) / 2;

	if (arr[high] < arr[low])
	{
		swapValues(arr, low, high);
	}
	if (arr[midpoint] > arr[high])
	{
		swapValues(arr, midpoint, high);
	}
	else if (arr[midpoint] < arr[low])
	{
		swapValues(arr, low, midpoint);
	}
	swapValues(arr, midpoint, high);

	pivot = arr[high--];
	int lastHigh = high;

	for (; low < high; low += arr[low] < pivot, high -= arr[high] > pivot)
	{
		if (arr[low] > pivot && arr[high] < pivot)
		{
			swapValues(arr, low, high);
		}
		(arr[high] > pivot && (lastHigh = high));
	}
	midpoint = arr[high] > pivot ? high : lastHigh;
	swapValues(arr, midpoint, end);
	return midpoint;
}

template<typename Type>
void qSort(Type *arr, int low, int high)
{
	if (high > low)
	{
		int pivotIndex = partition(arr, low, high);
		qSort(arr, low, pivotIndex - 1);
		qSort(arr, pivotIndex + 1, high);
	}
}


//==== entry point ===
template<typename Type>
void qSort(Type list[], int arraySize)
{
	qSort(list, 0, arraySize - 1);
}


#endif // !QUICK_SORT_H
