#include "sort.h"

/**
 *  * length_of_list - Computes the length of a linked list
 *   * @list: Pointer to the head of the linked list
 *    * Return: Length of list
 *
 */

size_t length_of_list(listint_t *list)
{
	size_t length = 0;

	while (list)
	{
		length++;
		list = list->next;
	}
	return (length);
}

/**
 *  * change_nodes - Changes the positions of two nodes in a doubly linked list
 *   * @list: Pointer to the head of the doubly linked list
 *    * @p: Pointer to the node to be moved
 *     *
 *      * Return: Void
 *
 */

void change_nodes(listint_t **list, listint_t **p)
{
	listint_t *first, *second, *third, *fourth;

	first = (*p)->prev;
	second = *p;
	third = (*p)->next;
	fourth = (*p)->next->next;
	second->next = fourth;
	if (fourth)
		fourth->prev = second;
	third->next = second;
	third->prev = second->prev;
	if (first)
		first->next = third;
	else
		*list = third;
	second->prev = third;
	*p = third;
}

/**
 *  * cocktail_sort_list - Sorts a doubly linked list using Cocktail
 *  Shaker sort algorithm
 *   * @list: Pointer to the head of the doubly linked list
 *    * Return: Void
 *
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *p;
	int ordered = 0;

	if (!list || !*list || length_of_list(*list) < 2)
		return;
	p = *list;
	while (!ordered)
	{
		ordered = 1;
		while (p->next)
		{
			if (p->n > p->next->n)
			{
				ordered = 0;
				change_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->next;
		}
		if (ordered)
			break;
		p = p->prev;
		while (p->prev)
		{
			if (p->n < p->prev->n)
			{
				ordered = 0;
				p = p->prev;
				change_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->prev;
		}
	}
}
