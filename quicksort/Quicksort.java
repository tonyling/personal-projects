// uses generic T
public class Quicksort<T extends Comparable>{
	// Returns a vector index i in which all elements in indices
	// < i are less than the value of i, and all elements in indices
	// > i are greater than the value of i
	private int partition(T[] array, int left, int right) {
		T pivot = array[right];
		int i   = left;

		for (int j = left; j < right; j++) {
			if (array[j].compareTo(pivot) <= 0) {
				T temp   = array[i];
				array[i] = array[j];
				array[j] = temp;
				i++;
			}
		}

		T temp       = array[i];
		array[i]     = array[right];
		array[right] = temp;
		return i;
	}

	// Calls private quickSort_ method
	public void quickSort (T[] array) {
		this.quickSort_(array, 0, array.length-1);
	}

	// Recursively calls quicksort on the smaller half of the partitioned index
	private void quickSort_(T[] array, int left, int right) {
		while (left < right)
		{
			int pivot = partition(array, left, right);

			// recursively calls quicksort on lesser half of array
			if ((pivot-left) < (right-pivot))
			{
				quickSort_(array, left, pivot-1);
				left = pivot+1;
			}
			else
			{
				quickSort_(array, pivot+1, right);
				right = pivot-1;
			}
		}
	}
}
