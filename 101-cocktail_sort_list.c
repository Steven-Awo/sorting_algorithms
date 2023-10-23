#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tails, listint_t **shakerr);
void swap_node_behind(listint_t **list, listint_t **tails,
		listint_t **shakerr);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - A function that swaps a node that's in a listint_t
 * of the doubly-linked list of only ints with the node that's ahead of it.
 * @list: the head's pointer for a doubly-linked list of only integers.
 * @tails: the tail's pointer for a doubly-linked list
 * @shakerr: the current's pointer for swapping the node of the
 * cocktail shakerr's algo.
 */

void swap_node_ahead(listint_t **list, listint_t **tails, listint_t **shakerr)

{
	listint_t *tmpr = (*shakerr)->next;

	if ((*shakerr)->prev != NULL)
		(*shakerr)->prev->next = tmpr;
	else
		*list = tmpr;
	tmpr->prev = (*shakerr)->prev;
	(*shakerr)->next = tmpr->next;
	if (tmpr->next != NULL)
		tmpr->next->prev = *shakerr;
	else
		*tails = *shakerr;
	(*shakerr)->prev = tmpr;
	tmpr->next = *shakerr;
	*shakerr = tmpr;
}

/**
 * swap_node_behind - A function that swaps a node that's in a listint_t
 * doubly-linked list of only ints with the node right behind it.
 * @list: the head's pointer for a doubly-linked list of only integers.
 * @tails: the tail's pointer for a doubly-linked list
 * @shakerr: the current's pointer for swapping the node of the
 * cocktail shakerr's algo.
 */

void swap_node_behind(listint_t **list, listint_t **tails, listint_t **shakerr)

{
	listint_t *tmpr = (*shakerr)->prev;

	if ((*shakerr)->next != NULL)
		(*shakerr)->next->prev = tmpr;
	else
		*tails = tmpr;
	tmpr->next = (*shakerr)->next;
	(*shakerr)->prev = tmpr->prev;
	if (tmpr->prev != NULL)
		tmpr->prev->next = *shakerr;
	else
		*list = *shakerr;
	(*shakerr)->next = tmpr;
	tmpr->prev = *shakerr;
	*shakerr = tmpr;
}

/**
 * cocktail_sort_list - A function that sorts the listint_t doubly-linked
 * list of only integers in an ascending order by using the cocktail
 * shakerr algorithm.
 * @list: the head's pointer for a doubly-linked list
 */

void cocktail_sort_list(listint_t **list)

{
	listint_t *tails, *shakerr;
	bool shakenn_not_stirredd = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (tails = *list; tails->next != NULL;)
		tails = tails->next;
	while (shakenn_not_stirredd == false)
	{
	shakenn_not_stirredd = true;
	for (shakerr = *list; shakerr != tails; shakerr = shakerr->next)
	{
	if (shakerr->n > shakerr->next->n)
	{
	swap_node_ahead(list, &tails, &shakerr);
	print_list((const listint_t *)*list);
	shakenn_not_stirredd = false;
	}
	}
	for (shakerr = shakerr->prev; shakerr != *list;
		shakerr = shakerr->prev)
	{
	if (shakerr->n < shakerr->prev->n)
	{
	swap_node_behind(list, &tails, &shakerr);
	print_list((const listint_t *)*list);
	shakenn_not_stirredd = false;
	}
	}
	}
}
