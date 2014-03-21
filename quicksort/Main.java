import java.util.Random;

public class Main{
	public static void main(String[] args) {
		Quicksort<Integer> qs = new Quicksort<Integer>();
		Random rand = new Random(); // default uses System.currentTimeMillis()

		// declare and initialize array of unique numbers
		Integer[] array = new Integer[25];
		for (int i = 0; i < 25; i++) {
			array[i] = i;
		}

		//randomly swap elements around
		for (int i = 0; i < 25; i++) {
			int index    = rand.nextInt(25);
			int temp     = array[index];
			array[index] = array[i];
			array[i]     = temp;
		}
		
		System.out.println("Randomized array of Integers")
		for (int i = 0; i < 25; i++) {
			System.out.println("  " + array[i]);
		}

		System.out.println("Sorted array of Integers")
		qs.quickSort(array);
		for (int i = 0; i < 25; i++) {
			System.out.println("  " + array[i]);
		}

	}
}