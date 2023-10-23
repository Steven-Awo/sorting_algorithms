#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * print_array - A function that prints out an array of
 * integers
 * @array: The array of ints to be printed
 * @size: the @array's size
 */

void print_array(const int *array, size_t size)

{
	size_t x;

	x = 0;
	while (array && x < size)
	{
	if (x > 0)
	{
	printf(", ");
	}
	printf("%d", array[x]);
	++x;
	}
	printf("\n");
}
