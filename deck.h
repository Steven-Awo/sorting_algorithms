#ifndef DECK_H_
#define DECK_H_

#include <stdlib.h>

/**
 * enum kind_e - A structure for enumerating a card suits.
 * @SPADE: the spade's suit.
 * @HEART: the heart'ss suit.
 * @CLUB: the club's suit.
 * @DIAMOND: the diamond's suit.
 */

typedef enum kind_e

{
	SPADE = 0,
	CLUB,
	HEART,
	DIAMOND
} kind_t;

/**
 * struct card_s - the structure for the playing card
 * @value: the card's value
 * From the "Ace" to the "King"
 * @kind: the kind of card
 */

typedef struct card_s

{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - the structure for the deck of card
 * @card: the card's pointer to the node
 * @prev: the previous's pointer to the list
 * @next: the next's node pointer for the list
 */

typedef struct deck_node_s

{
	const card_t *card;
	struct deck_node_s *next;
	struct deck_node_s *prev;
} deck_node_t;

void sort_deck(deck_node_t **deck);
#endif /* DECK_H */
