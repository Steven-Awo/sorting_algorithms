#include "sort.h"

int get_max(int *array, int sizee);
void radix_counting_sort(int *array, size_t sizee,
		int sigg, int *buffr);
void radix_sort(int *array, size_t sizee);

/**
 * get_max - A function that gets the maximum value in
 * the array of only integers.
 * @array: An array of only integers.
 * @sizee: The array's size.
 * Return: The biggest integer in the array.
 */

int get_max(int *array, int sizee)

{
	int maxim, x;

	for (maxim = array[0], x = 1; x < sizee; x++)
	{
	if (array[x] > maxim)
	{
	maxim = array[x];
	}
	}
	return (maxim);
}

/**
 * radix_counting_sort - A function that that sorts the significant digits of the array of
 * only integers in by ascending order by using the counting sort algorithm.
 * @array: An array of only integers.
 * @sizee: The array's size.
 * @sigg: The significant digit to be sorted on.
 * @buffr: A buffer that stores the sorted array.
 */

void radix_counting_sort(int *array, size_t sizee, int sigg, int *buffr)

{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t x;

	for (x = 0; x < sizee; x++)
	{
	count[(array[x] / sigg) % 10] += 1;
	}
	for (x = 0; x < 10; x++)
	{
	count[x] += count[x - 1];
	}
	for (x = sizee - 1; (int)x >= 0; x--)
	{
	buffr[count[(array[x] / sigg) % 10] - 1] = array[x];
	count[(array[x] / sigg) % 10] -= 1;
	}
	for (x = 0; x < sizee; x++)
	{
	array[x] = buffr[x];
	}
}

/**
 * radix_sort - A function that sorts an array of only integers in an
 * ascending order by using the algorithm radix sort.
 * @array: An array of the integers.
 * @sizee: The size of the array.
 * Description: to implements the algorithm LSD radix sort. Printing
 * out the array one after each and every significant digit is increased.
 */

void radix_sort(int *array, size_t sizee)

{
	int maxim, sigg, *buffr;

	if (array == NULL || sizee < 2)
	{
	return;
	}
	buffr = malloc(sizeof(int) * sizee);
	if (buffr == NULL)
	{
	return;
	}
	maxim = get_max(array, sizee);
	for (sigg = 1; maxim / sigg > 0; sigg *= 10)
	{
	radix_counting_sort(array, sizee, sigg, buffr);
	print_array(array, sizee);
	}
	free(buffr);
}
