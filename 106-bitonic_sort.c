#include "sort.h"

void swap_ints(int *aa, int *bb);
void bitonic_merge(int *array, size_t size, size_t startts,
		size_t seqq, char floww);
void bitonic_seq(int *array, size_t size, size_t startts,
		size_t seqq, char floww);
void bitonic_sort(int *array, size_t size);

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
 * bitonic_merge - A function that sorts a bitonic's sequence inside an
 * array of only integers.
 * @array: An array of only integers.
 * @size: The array's size.
 * @startts: The beginning index to the sequence in the array to be sorted.
 * @seqq: The sequence's size to be sorted.
 * @floww: The direction to which the sorting will go.
 */

void bitonic_merge(int *array, size_t size, size_t startts,
		size_t seqq, char floww)
{
	size_t x, jumper = seqq / 2;

	if (seqq > 1)
	{
	for (x = startts; x < startts + jumper; x++)
	{
	if ((floww == UP && array[x] > array[x + jumper]) ||
			(floww == DOWN && array[x] < array[x + jumper]))
		swap_ints(array + x, array + x + jumper);
	}
	bitonic_merge(array, size, startts, jumper, floww);
	bitonic_merge(array, size, startts + jumper, jumper, floww);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: An array of only integers.
 * @size: The array's size.
 * @startts: The starting index of a block of the building bitonic sequence.
 * @seqq: The size of a block of the building bitonic sequence.
 * @floww: The direction to sort the bitonic sequence block in.
 */

void bitonic_seq(int *array, size_t size, size_t startts,
		size_t seqq, char floww)

{
	size_t cutt = seqq / 2;
	char *strg = (floww == UP) ? "UP" : "DOWN";

	if (seqq > 1)
	{
	printf("Merging [%lu/%lu] (%s):\n", seqq, size, strg);
	print_array(array + startts, seqq);
	bitonic_seq(array, size, startts, cutt, UP);
	bitonic_seq(array, size, startts + cutt, cutt, DOWN);
	bitonic_merge(array, size, startts, seqq, floww);
	printf("Result [%lu/%lu] (%s):\n", seqq, size, strg);
	print_array(array + startts, seqq);
	}
}

/**
 * bitonic_sort - A function that sorts an array of only integers in an
 * ascending order by using the algorithm bitonic sort.
 * @array: An array of only integers.
 * @size: The array's size.
 * Description: Printing out the array after each is swapped.
 */

void bitonic_sort(int *array, size_t size)

{
	if (array == NULL || size < 2)
	{
	return;
	}
	bitonic_seq(array, size, 0, size, UP);
}
