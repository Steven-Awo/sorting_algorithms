#include "sort.h"

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
 * bubble_sort - A function that sort's an array of any integers
 * in an ascending order.
 * @array: the array of ints to be sorted.
 * @size: The array's size.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, lent = size;
	bool bubblyy = false;

	if (array == NULL || size < 2)
	{
	return;
	}
	while (bubblyy == false)
	{
	bubblyy = true;
	for (x = 0; x < lent - 1; x++)
	{
	if (array[x] > array[x + 1])
	{
	swap_ints(array + x, array + x + 1);
	print_array(array, size);
	bubblyy = false;
	}
	}
	lent--;
	}
}
