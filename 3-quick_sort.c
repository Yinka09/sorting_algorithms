#include "sort.h"

/**
 *  * substitute - Swaps the values of two integers
 *   * @x: Pointer to the first integer
 *    * @y: Pointer to the second integer
 *     * Return: Void
 */

void substitute(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 *  * _split - Partitions an array using the last element as the pivot
 *   * @array: Pointer to the array to be partitioned
 *    * @small: Index of the smaller element
 *     * @big: Index of the larger element
 *      * @size: Size of the array
 *       * Return: the index of the pivot element after partition.
 */

int _split(int *array, int small, int big, size_t size)
{
	int axis = array[big];
	int x = small - 1, y;

	for (y = small; y <= big; y++)
	{
		if (array[y] <= axis)
		{
			x++;
			if (x != y)
			{
				substitute(&array[x], &array[y]);
				print_array(array, size);
			}
		}
	}
	return (x);
}

/**
 *  * lomuto_quick_sort - Sorts an array using Lomuto partition scheme
 *   * @array: Pointer to the array to be sorted
 *    * @small: Index of the smaller element
 *     * @big: Index of the larger element
 *      * @size: Size of the array
 *       * Return: Void
 */

void lomuto_quick_sort(int *array, int small, int big, size_t size)
{
	int x;

	if (small < big)
	{
		x = _split(array, small, big, size);
		lomuto_quick_sort(array, small, x - 1, size);
		lomuto_quick_sort(array, x + 1, big, size);
	}
}

/**
 *  * quick_sort - Sorts an array using Quick Sort algorithm
 *   * @array: Pointer to the array to be sorted
 *    * @size: Size of the array
 *     * Return: Void
 */

void quick_sort(int *array, size_t size)
{
	lomuto_quick_sort(array, 0, size - 1, size);
}
