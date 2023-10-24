#include "sort.h"

/**
 *  * pull_max - Finds the maximum value in an integer array
 *   * @array: Pointer to the array
 *    * @size: Size of the array
 *     * Return: The maximum integer in the array.
 *
 */

int pull_max(int *array, int size)
{
	int maximum, x;

	for (maximum = array[0], x = 1; x < size; x++)
	{
		if (array[x] > maximum)
			maximum = array[x];
	}

	return (maximum);
}

/**
 *  * counting_sort - Sorts an integer array using Counting Sort algorithm
 *   * @array: Pointer to the array to be sorted
 *    * @size: Size of the array
 *     * Return: Void
 *
 */

void counting_sort(int *array, size_t size)
{
	int *total, *ordered, maximum, i;

	if (array == NULL || size < 2)
		return;

	ordered = malloc(sizeof(int) * size);
	if (ordered == NULL)
		return;
	maximum = pull_max(array, size);
	total = malloc(sizeof(int) * (maximum + 1));
	if (total == NULL)
	{
		free(ordered);
		return;
	}

	for (i = 0; i < (maximum + 1); i++)
		total[i] = 0;
	for (i = 0; i < (int)size; i++)
		total[array[i]] += 1;
	for (i = 0; i < (maximum + 1); i++)
		total[i] += total[i - 1];
	print_array(total, maximum + 1);

	for (i = 0; i < (int)size; i++)
	{
		ordered[total[array[i]] - 1] = array[i];
		total[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = ordered[i];

	free(ordered);
	free(total);
}
