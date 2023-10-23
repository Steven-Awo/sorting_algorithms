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
 * shell_sort - A funnction that sorts an array of only integers in an
 * ascending order using the shell sort algorithm.
 * @array: The array of the integers.
 * @size: The array's size.
 * Description: Using the Knuth's interval sequence.
 */

void shell_sort(int *array, size_t size)

{
	size_t gaps, x, y;

	if (array == NULL || size < 2)
	{
	return;
	}
	for (gaps = 1; gaps < (size / 3);)
	{
	gaps = gaps * 3 + 1;
	}
	for (; gaps >= 1; gaps /= 3)
	{
	for (x = gaps; x < size; x++)
	{
	y = x;
	while (y >= gaps && array[y - gaps] > array[y])
	{
	swap_ints(array + y, array + (y - gaps));
	y -= gaps;
	}
	}
	print_array(array, size);
	}
}
