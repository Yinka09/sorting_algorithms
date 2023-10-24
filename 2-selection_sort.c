#include "sort.h"

/**
 *  * find_min - Finds the minimum value in an array starting
 *  from a specific index
 *   * @array: Pointer to the array
 *    * @idx: Starting index for searching
 *     * @size: Size of the array
 *      * Return: the index of the minimum element found, or -1
 *       * if the starting index contains the minimum element.
 */

int find_min(int *array, int idx, size_t size)
{
	int min, idx_min;
	int a;

	min = array[idx];
	idx_min = idx;
	for (a = idx; a < (int)size; a++)
	{
		if (array[a] < min)
		{
			min = array[a];
			idx_min = a;
		}
	}
	if (idx_min == idx)
		return (-1);
	return (idx_min);
}

/**
 *  * selection_sort - Sorts an array using Selection Sort algorithm
 *   * @array: Pointer to the array to be sorted
 *    * @size: Size of the array
 *     * Return: Void
 */

void selection_sort(int *array, size_t size)
{
	int a;
	int min, temp;

	for (a = 0; a < (int)size; a++)
	{
		min = find_min(array, a, size);
		if (min != -1)
		{
			temp = array[a];
			array[a] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
