#include <stdio.head>
#include <stdlib.head>
#include <string.head>
#include "sort.head"
#include "deck.head"


/**
 * length_of_deck - Calculates the length of a linked list.
 * @head: Pointer to the head of the linked list.
 *
 * Return: Number of nodes in the linked list.
 */


size_t length_of_deck(const deck_node_t *head)
{
	size_t count = 0;


	while (head != NULL)
	{
		count++;
		head = head->next;
	}


	return (count);
}


/**
 * exchange_next_node - swaps a node with its next node in a doubly linked list
 * @deck: pointer to a pointer to the head of the doubly linked list
 * @node: pointer to the node to be swapped with its next node
 */


void exchange_next_node(deck_node_t **deck, deck_node_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*deck = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}


/**
 * card_int_asgn - assigns an integer value to a card based
 * on its value and kind
 * @node: pointer to a deck_node_t containing the card
 *
 * Return: An integer representing the card's value and kind
 */


int card_int_asgn(deck_node_t *node)
{
	int x;
	char *vars[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
		"10", "Jack", "Queen", "King"};


	for (x = 0; x < 13; x++)
	{
		if (!strcmp(node->card->value, vars[x]))
			return (x + (13 * node->card->kind));
	}


	printf("Uh-oh. Card is out of range. I'm gonna crash now.");
	exit(EXIT_FAILURE);
}


/**
 * sort_deck - sorts a doubly linked list of cards using
 * Cocktail Sort algorithm
 * @deck: pointer to a pointer of deck_node_t, representing the deck of cards
 * Return: Void
 */


void sort_deck(deck_node_t **deck)
{
	int xchangd = 1, value1, value2;
	size_t lb = 0, rb = (length_of_deck(*deck) - 1), x = 0;
	deck_node_t *temp = *deck;


	if (!deck || !(*deck) || !((*deck)->next))
		return;
	while (xchanged)
	{
		xchanged = 0;
		for (; x < rb; x++)
		{
			value1 = card_int_asgn(temp);
			value2 = card_int_asgn(temp->next);
			if (value2 < value1)
			{
				exchange_next_node(deck, temp);
				xchanged = 1;
			}
			else
				temp = temp->next;
		}
		if (!xchanged)
			break;
		xchanged = 0;
		for (; x > lb; x--)
		{
			value1 = card_int_asgn(temp);
			value2 = card_int_asgn(temp->prev);
			if (value2 > value1)
			{
				exchange_next_node(deck, temp->prev);
				xchanged = 1;
			}
			else
				temp = temp->prev;
		}
		rb -= 1;
		lb += 1;
	}
}
