#include "sort.h"

/**
 * get_max - A function that gets the max value in the array
 * of only integers.
 * @array: The array of on integers.
 * @size: The array's size.
 * Return: The max int in the array.
 */

int get_max(int *array, int size)

{
	int maximum, x;

	for (maximum = array[0], x = 1; x < size; x++)
	{
	if (array[x] > maximum)
	{
	maximum = array[x];
	}
	}
	return (maximum);
}

/**
 * counting_sort - A function that sorts an array of only ints in an
 * ascending order using the counting sort algorithm.
 * @array: The array of on integers.
 * @size: The array's size.
 * Description: Printing out the counting array but after
 * setting it up.
 */

void counting_sort(int *array, size_t size)

{
	int *counts, *sortedd, maximum, x;

	if (array == NULL || size < 2)
		return;
	sortedd = malloc(sizeof(int) * size);
	if (sortedd == NULL)
		return;
	maximum = get_max(array, size);
	counts = malloc(sizeof(int) * (maximum + 1));
	if (counts == NULL)
	{
	free(sortedd);
	return;
	}
	for (x = 0; x < (maximum + 1); x++)
		counts[x] = 0;
	for (x = 0; x < (int)size; x++)
		counts[array[x]] += 1;
	for (x = 0; x < (maximum + 1); x++)
		counts[x] += counts[x - 1];
	print_array(counts, maximum + 1);
	for (x = 0; x < (int)size; x++)
	{
	sortedd[counts[array[x]] - 1] = array[x];
	counts[array[x]] -= 1;
	}
	for (x = 0; x < (int)size; x++)
		array[x] = sortedd[x];
	free(sortedd);
	free(counts);
}
