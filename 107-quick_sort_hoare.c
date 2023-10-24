#include "sort.h"

void swap_ints(int *aa, int *bb);

int hoare_partition(int *array, size_t size,
		int leftt, int rightt);

void hoare_sort(int *array, size_t size,
		int leftt, int rightt);

void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - A function that swaps two integers in an
 * array.
 * @aa: The 1st int to be swapped.
 * @bb: The 2nd int to be swapped.
 */

void swap_ints(int *aa, int *bb)

{
	int tmpr;

	tmpr = *aa;
	*aa = *bb;
	*bb = tmpr;
}

/**
 * hoare_partition - A function that orders a subset of array of
 * only integers according to hoare partition scheme.
 * @array: The array of only integers.
 * @size: The size of the array.
 * @leftt: The index that starts off the subset to be order.
 * @rightt: The index that ends the subset to be order.
 * Return: abovee.
 * Description: Using the last element in the partition as pivott.
 */

int hoare_partition(int *array, size_t size, int leftt, int rightt)

{
	int pivott, abovee, beloww;

	pivott = array[rightt];
	for (abovee = leftt - 1, beloww = rightt + 1; abovee < beloww;)
	{
	do {
		abovee++;
	} while (array[abovee] < pivott);
	do {
		beloww--;
	} while (array[beloww] > pivott);
	if (abovee < beloww)
	{
	swap_ints(array + abovee, array + beloww);
	print_array(array, size);
	}
	}
	return (abovee);
}

/**
 * hoare_sort - An function that implements the quicksort algorithm by
 * recursion.
 * @array: An array of only integers to be sorted.
 * @size: The size of the array.
 * @leftt: The index that starts off the array's partition to be order.
 * @rightt: The index that ends the array's partition to be order.
 * Description: Using the Hoare's partition scheme.
 */

void hoare_sort(int *array, size_t size, int leftt, int rightt)

{
	int part;

	if (rightt - leftt > 0)
	{
	part = hoare_partition(array, size, leftt, rightt);
	hoare_sort(array, size, leftt, part - 1);
	hoare_sort(array, size, part, rightt);
	}
}

/**
 * quick_sort_hoare - A function that sorts an array of only integers in
 * ascending order by using the quicksort algorithm.
 * @array: An array of only integers.
 * @size: The array's size.
 * Description: Using the Hoare's partition scheme and printing
 * the array one after each is swapped btw two elements.
 */

void quick_sort_hoare(int *array, size_t size)

{
	if (array == NULL || size < 2)
	{
	return;
	}
	hoare_sort(array, size, 0, size - 1);
}
