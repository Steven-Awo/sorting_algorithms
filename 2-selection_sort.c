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
 * selection_sort - A function that sort an array of only int in an ascending
 * order using this selection sorting algorithm.
 * @array: the array of ints to be sorted.
 * @size: The array's size.
 * Description: Printing out the array after each of the swap swap.
 */

void selection_sort(int *array, size_t size)

{
	int *minm;
	size_t x, y;

	if (array == NULL || size < 2)
	{
	return;
	}
	for (x = 0; x < size - 1; x++)
	{
	minm = array + x;
	for (y = x + 1; y < size; y++)
	{
	minm = (array[y] < *minm) ? (array + y) : minm;
	}
	if ((array + x) != minm)
	{
	swap_ints(array + x, minm);
	print_array(array, size);
	}
	}
}
