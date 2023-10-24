#include "sort.h"

/**
 *  * heapify - Perform heapify operation on an array
 *   * @array: Pointer to the array
 *    * @heap: Size of the heap
 *     * @x: Index of the current element in the heap
 *      * @size: Size of the array
 *       * Return: Void
 *
 */

void heapify(int *array, int heap, int x, int size)
{
	int large_idx = x, left = 2 * x + 1, right = 2 * x + 2, w;

	if (left < heap && array[left] > array[large_num_idx])
		large_num_idx = left;
	if (right < heap && array[right] > array[large_num_idx])
		large_num_idx = right;
	if (large_num_idx != x)
	{
		w = array[x], array[x] = array[large_num_idx], array[large_num_idx] = w;
		print_array(array, size);
		heapify(array, heap, large_num_idx, size);
	}
}

/**
 *  * heap_sort - Sorts an array of integers in ascending order
 *  using Heap Sort algorithm
 *   * @array: Pointer to the array to be sorted
 *    * @size: Size of the array
 *     * Return: Void
 *
 */

void heap_sort(int *array, size_t size)
{
	int x = size / 2 - 1, tmp;

	if (array == NULL || size < 2)
		return;
	for (; x >= 0; x--)
		heapify(array, size, x, size);
	for (x = size - 1; x >= 0; x--)
	{
		tmp = array[0];
		array[0] = array[x];
		array[x] = tmp;
		if (x > 0)
			print_array(array, size);
		heapify(array, x, 0, size);
	}
}
