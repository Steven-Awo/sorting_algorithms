#include "sort.h"

void merge_subarr(int *subarry, int *buffr, size_t frontr,
		size_t midle, size_t backwds);
void merge_sort_recursive(int *subarry, int *buffr, size_t frontr,
		size_t backwds);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - A function that sorts a subarray of only integers.
 * @subarry: the subarray of an integer array to be sorted.
 * @buffr: the buffer to be stored in the sorted subarray.
 * @frontr: The move frontr index to the wwhole array.
 * @midle: The middle index to the whole array.
 * @backwds: The move backwards index to the array.
 */

void merge_subarr(int *subarry, int *buffr, size_t frontr,
		size_t midle, size_t backwds)

{
	size_t x, y, z = 0;

	printf("Merging...\n[left]: ");
	print_array(subarry + frontr, midle - frontr);
	printf("[right]: ");
	print_array(subarry + midle, backwds - midle);
	for (x = frontr, y = midle; x < midle && y < backwds; z++)
	{
	buffr[z] = (subarry[x] < subarry[y]) ? subarry[x++] : subarry[y++];
	}
	for (; x < midle; x++)
	{
	buffr[z++] = subarry[x];
	}
	for (; y < backwds; y++)
	{
	buffr[z++] = subarry[y];
	}
	for (x = frontr, z = 0; x < backwds; x++)
	{
	subarry[x] = buffr[z++];
	}
	printf("[Done]: ");
	print_array(subarry + frontr, backwds - frontr);
}

/**
 * merge_sort_recursive - A function that implements the merge sort
 * algorithm by recursion.
 * @subarry: the subarray of an integer array to be sorted.
 * @buffr: the buffer to be stored in the sorted result
 * @frontr: The move frontr index to the wwhole array.
 * @backwds: The move backwards index to the subarray.
 */

void merge_sort_recursive(int *subarry, int *buffr, size_t frontr,
		size_t backwds)

{
	size_t midle;

	if (backwds - frontr > 1)
	{
	midle = frontr + (backwds - frontr) / 2;
	merge_sort_recursive(subarry, buffr, frontr, midle);
	merge_sort_recursive(subarry, buffr, midle, backwds);
	merge_subarr(subarry, buffr, frontr, midle, backwds);
	}
}

/**
 * merge_sort - A function that sorts an array of the integers in an
 * ascending order using the merge sort algorithm.
 * @array: An array of only integers.
 * @size: The array's size.
 * Description: To implement the sort algorithm called top-down merge
 */

void merge_sort(int *array, size_t size)

{
	int *buffr;

	if (array == NULL || size < 2)
	{
	return;
	}
	buffr = malloc(sizeof(int) * size);
	if (buffr == NULL)
	{
	return;
	}
	merge_sort_recursive(array, buffr, 0, size);
	free(buffr);
}
