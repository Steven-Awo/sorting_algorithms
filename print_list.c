#include <stdio.h>
#include "sort.h"

/**
 * print_list - A function that prints out a list of
 * integers
 * @list: The list that's to be printed
 */

void print_list(const listint_t *list)

{
	int x;

	x = 0;
	while (list)
	{
	if (x > 0)
	{
	printf(", ");
	}
	printf("%d", list->n);
	++x;
	list = list->next;
	}
	printf("\n");
}
