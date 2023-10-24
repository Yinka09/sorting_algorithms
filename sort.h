#ifndef _SORTING_H_
#define _SORTING_H_
#include <stdio.h>
#include <stdlib.h>

/** Struct Double Linked List */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 **/
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* 0-bubble_sort.c*/
void bubble_sort(int *array, size_t size);

/* 1-insertion_sort_list.c */
void change(listint_t *x, listint_t *y, listint_t **head);
void insertion_sort_list(listint_t **list);

/* 2-selection_sort.c */
int find_min(int *array, int idx, size_t size);
void selection_sort(int *array, size_t size);

/* 3-quick_sort.c */
void substitute(int *x, int *y);
int _split(int *array, int small, int big, size_t size);
void lomuto_quick_sort(int *array, int small, int big, size_t size);
void quick_sort(int *array, size_t size);

/* 100-shell_sort.c */
void shell_sort(int *array, size_t size);

/* 101-cocktail_sort_list.c */
size_t length_of_list(listint_t *list);
void change_nodes(listint_t **list, listint_t **p);
void cocktail_sort_list(listint_t **list);

/* 102-counting_sort.c */
int pull_max(int *array, int size);
void counting_sort(int *array, size_t size);

/* 103-merge_sort.c */
void auxarry_merge(int *auxarry, int *buf, size_t front, size_t centre,
		size_t back);
void loop_merge_sort(int *auxarry, int *buf, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/* 104-heap_sort.c */
void heapify(int *array, int heap, int x, int size);
void heap_sort(int *array, size_t size);

/* 105-radix_sort.c */
void LSD_counting_sort(int *array, size_t size, size_t lsd);
void radix_sort(int *array, size_t size);

/* 106-bitonic_sort.c */
void change_int(int *m, int *y);
void bit_merge(int *array, int least, int total, int comp, size_t size);
void bit_sort(int *array, int least, int total, int comp, size_t size);
void bitonic_sort(int *array, size_t size);

/* 107-quick_sort_hoare.c */
void replace(int *m, int *n);
int separate(int *array, int least, int large, size_t size);
void recur_hoare_qsort(int *array, int least, int large, size_t size);
void quick_sort_hoare(int *array, size_t size);

/* 1000-sort_deck.c */
size_t length_of_deck(const deck_node_t *head);
void exchange_next_node(deck_node_t **deck, deck_node_t *node);
int card_int_asgn(deck_node_t *node);
void sort_deck(deck_node_t **deck);

/** Given helper functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

#endif
