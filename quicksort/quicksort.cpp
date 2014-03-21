#include <vector>
#include <iostream>

template <typename T>
int partition(std::vector<T> &array, int left, int right)
{
	T pivot = array[right];
	int i = left;
	for (int j = left; j < right; j++) {
		if (array[j] <= pivot) {
			T temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
		}
	}
	T temp = array[i];
	array[i] = array[right];
	array[right] = temp;
	return i;
}

template <typename T>
void quicksort(std::vector<T> &array, int left, int right)
{
	while (left < right)
	{
		int pivot = partition(array, left, right);
		// recursively calls quicksort on lesser half of array
		if ((pivot-left) < (right-pivot))
		{
			quicksort(array, left, pivot-1);
			left = pivot+1;
		}
		else
		{
			quicksort(array, pivot+1, right);
			right = pivot-1;
		}
	}
}
