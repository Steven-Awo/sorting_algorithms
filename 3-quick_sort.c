#include "sort.h"

void swap_ints(int *aa, int *bb);
int lomuto_partition(int *array, size_t size, int leftt, int rightt);
void lomuto_sort(int *array, size_t size, int leftt, int rightt);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - A function that order's a subset of the array of int
 * according to the iiy lomuto partition scheme (last element as pivott).
 * @array: The array of the integers.
 * @size: The array's size.
 * @leftt: The index to start off the subset to be ordered.
 * @rightt: The index to end the subset to be ordered.
 * Return: The index of the final or last partition.
 */

int lomuto_partition(int *array, size_t size, int leftt, int rightt)

{
	int *pivott, ontop, beloww;

	pivott = array + rightt;
	for (ontop = beloww = leftt; beloww < rightt; beloww++)
	{
	if (array[beloww] < *pivott)
	{
	if (ontop < beloww)
	{
	swap_ints(array + beloww, array + ontop);
	print_array(array, size);
	}
	ontop++;
	}
	}
	if (array[ontop] > *pivott)
	{
	swap_ints(array + ontop, pivott);
	print_array(array, size);
	}
	return (ontop);
}

/**
 * lomuto_sort - A function that implements the quicksort algorithm by
 * recursion.
 * @array: The array of the integers.
 * @size: The array's size.
 * @leftt: The index to start off the array partition to be ordered.
 * @rightt: The index to end the array partition to be ordered.
 * Description: Uses the Lomuto partition scheme.
 */

void lomuto_sort(int *array, size_t size, int leftt, int rightt)

{
	int d_part;

	if (rightt - leftt > 0)
	{
	d_part = lomuto_partition(array, size, leftt, rightt);
	lomuto_sort(array, size, leftt, d_part - 1);
	lomuto_sort(array, size, d_part + 1, rightt);
	}
}

/**
 * quick_sort - A function that sorts an array of only integers in an
 * ascending order by using the quicksort algorithm.
 * @array: the array of onlyintegers.
 * @size: The array's size.
 * Description: Using the Lomuto's partition scheme. to print out
 * the array one after each swap of the two elements.
 */

void quick_sort(int *array, size_t size)

{
	if (array == NULL || size < 2)
	{
	return;
	}
	lomuto_sort(array, size, 0, size - 1);
}
