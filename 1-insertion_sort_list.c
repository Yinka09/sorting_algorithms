#include "sort.h"

/**
 * change - Swaps two adjacent nodes in a doubly linked list
 * @x: Pointer to the first node
 * @y: Pointer to the second node
 * @head: Pointer to the head of the linked list
 * Return: Void
 **/

void change(listint_t *x, listint_t *y, listint_t **head)
{
	listint_t *var1 = NULL, *var2 = NULL;

	if (x == NULL || y == NULL)
		return;
	var1 = x->prev;
	var2 = y->next;
	/* if nodes are adjacent*/
	if (var1)
		var1->next = y;
	if (var2)
		var2->prev = x;
	x->next = var2;
	x->prev = y;
	y->next = x;
	y->prev = var1;
	if (var1 == NULL)
		*head = y;
}

/**
 *  * insertion_sort_list - Sorts a doubly linked list using Insertion
 *  Sort algorithm
 *   * @list: Pointer to the head of the doubly linked list
 *    * Return: Void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head, *prev;
	int num;

	if (list == NULL || (*list)->next == NULL || (*list) == NULL)
	{
		return;
	}
	head = *list;
	while (head)
	{
		prev = head->prev;
		num = head->n;

		while (prev && prev->n > num)
		{
			change(prev, head, list);
			print_list(*list);
			prev = head->prev;
		}
		head = head->next;
	}
}
