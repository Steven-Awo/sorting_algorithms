#include "deck.h"

int _strcmp(const char *ss1, const char *ss2);

char get_value(deck_node_t *card);

void insertion_sort_deck_kind(deck_node_t **deck);

void insertion_sort_deck_value(deck_node_t **deck);

void sort_deck(deck_node_t **deck);

/**
 * _strcmp - A function that compares two strings.
 * @ss1: The 1st string to be compared with.
 * @ss2: The 2nd string to be compared with.
 * Return: the positive byte's difference if ss1 > ss2
 * or 0 if ss1 == ss2 or negative byte's difference
 * if ss1 < ss2
 */

int _strcmp(const char *ss1, const char *ss2)

{
	while (*ss1 && *ss2 && *ss1 == *ss2)
	{
	ss1++;
	ss2++;
	}
	if (*ss1 != *ss2)
	{
	return (*ss1 - *ss2);
	}
	return (0);
}

/**
 * get_value - A function that gets the numerical value of the
 * card.
 * @card: the pointer to the deck_node_t card.
 * Return: The number value of d card.
 */

char get_value(deck_node_t *card)

{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind - A function that sorts a deck of cards
 * beginning from the spades to the diamonds.
 * @deck: The head's pointer to the deck_node_t of the
 * doubly-linked list.
 */

void insertion_sort_deck_kind(deck_node_t **deck)

{
	deck_node_t *itert, *insertn, *tmpr;

	for (itert = (*deck)->next; itert != NULL; itert = tmpr)
	{
	tmpr = itert->next;
	insertn = itert->prev;
	while (insertn != NULL && insertn->card->kind > itert->card->kind)
	{
	insertn->next = itert->next;
	if (itert->next != NULL)
		itert->next->prev = insertn;
	itert->prev = insertn->prev;
	itert->next = insertn;
	if (insertn->prev != NULL)
		insertn->prev->next = itert;
	else
		*deck = itert;
	insertn->prev = itert;
	insertn = itert->prev;
	}}
}

/**
 * insertion_sort_deck_value - A function that sorts a deck of cards
 * from the spades to the diamonds from the ace to the king.
 * @deck: The head's pointer to the deck_node_t of the
 * doubly-linked list.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *itert, *insertn, *tmpr;

	for (itert = (*deck)->next; itert != NULL; itert = tmpr)
	{
	tmpr = itert->next;
	insertn = itert->prev;
	while (insertn != NULL &&
	       insertn->card->kind == itert->card->kind &&
	       get_value(insertn) > get_value(itert))
	{
	insertn->next = itert->next;
	if (itert->next != NULL)
		itert->next->prev = insertn;
	itert->prev = insertn->prev;
	itert->next = insertn;
	if (insertn->prev != NULL)
		insertn->prev->next = itert;
	else
		*deck = itert;
	insertn->prev = itert;
	insertn = itert->prev;
	}}
}

/**
 * sort_deck - A function that sorts a deck of cards from the ace to the
 * king and from the spades to the diamonds.
 * @deck: The head's pointer to the deck_node_t of the
 * doubly-linked list.
 */

void sort_deck(deck_node_t **deck)

{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
	{
	return;
	}
	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
