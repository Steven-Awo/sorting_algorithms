#include "sort.h"

void swap_ints(int *aa, int *bb);
void max_heapify(int *array, size_t size, size_t bases,
		size_t roots);
void heap_sort(int *array, size_t size);

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
 * max_heapify - A function that turns aa binary's tree into a complete
 * binary heap.
 * @array: An array of only integers that represents a binary tree.
 * @size: The array's/tree's size.
 * @bases: The index for the bases row for the tree.
 * @roots: The root's node for the binary tree.
 */

void max_heapify(int *array, size_t size, size_t bases, size_t roots)

{
	size_t move_left, move_right, largerr;

	move_left = 2 * roots + 1;
	move_right = 2 * roots + 2;
	largerr = roots;
	if (move_left < bases && array[move_left] > array[largerr])
	{
	largerr = move_left;
	}
	if (move_right < bases && array[move_right] > array[largerr])
	{
	largerr = move_right;
	}
	if (largerr != roots)
	{
	swap_ints(array + roots, array + largerr);
	print_array(array, size);
	max_heapify(array, size, bases, largerr);
	}
}

/**
 * heap_sort - A function that sorts an array of only integers in an
 * ascending order by using the algorithm called heap sort.
 * @array: the array of only integers.
 * @size: The array's size.
 * Description: To implement the algorithm sift-down heap sort
 * Printing out the array one after each swap.
 */

void heap_sort(int *array, size_t size)

{
	int x;

	if (array == NULL || size < 2)
	{
	return;
	}
	for (x = (size / 2) - 1; x >= 0; x--)
	{
	max_heapify(array, size, size, x);
	}
	for (x = size - 1; x > 0; x--)
	{
	swap_ints(array, array + x);
	print_array(array, size);
	max_heapify(array, size, x, 0);
	}
}
