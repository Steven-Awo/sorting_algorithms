#include "sort.h"

/**
 * swap_nodes - A function that swaps two nodes that's in a
 * listint_t of the doubly-linked list.
 * @h: the pointer to the doubly-linked list heead.
 * @num1: The 1st int to be swapped.
 * @num2: The 2nd int to be swapped.
 */

void swap_nodes(listint_t **h, listint_t **num1, listint_t *num2)

{
	(*num1)->next = num2->next;
	if (num2->next != NULL)
	{
	num2->next->prev = *num1;
	}
	num2->prev = (*num1)->prev;
	num2->next = *num1;
	if ((*num1)->prev != NULL)
	{
	(*num1)->prev->next = num2;
	}
	else
	{
	*h = num2;
	}
	(*num1)->prev = num2;
	*num1 = num2->prev;
}

/**
 * insertion_sort_list - A function that sorts out a doubly linked list
 * of the integers by using the insertion sort algorithm.
 * @list: the pointer to the doubly-linked list of int's heead
 * Description: to print out the list after each and every swap.
 */

void insertion_sort_list(listint_t **list)

{
	listint_t *itert, *inserting, *tmpr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
	return;
	}
	for (itert = (*list)->next; itert != NULL; itert = tmpr)
	{
	tmpr = itert->next;
	inserting = itert->prev;
	while (inserting != NULL && itert->n < inserting->n)
	{
	swap_nodes(list, &inserting, itert);
	print_list((const listint_t *)*list);
	}
	}
}
