#include "sort.h"

/**
 *  * LSD_counting_sort - sorts an array of integers using LSD radix sort
 *   * @array: pointer to the array to be sorted
 *    * @size: size of the array
 *     * @lsd: least significant digit (1, 10, 100, ...)
 *      * Return: Void
 *
 */

void LSD_counting_sort(int *array, size_t size, size_t lsd)
{
	int sum_arry[10] = {0}, *stor_arry, i, j;
	size_t x, y;

	stor_arry = malloc(sizeof(int) * size);

	for (x = 0; x < size; x++)
		sum_arry[(array[x] / lsd) % 10]++;
	for (i = 1; i < 10; i++)
		sum_arry[i] += sum_arry[i - 1];

	for (j = size - 1; j >= 0; j--)
	{
		stor_arry[sum_arry[(array[j] / lsd) % 10] - 1] = array[j];
		sum_arry[(array[j] / lsd) % 10]--;
	}

	for (y = 0; y < size; y++)
		array[y] = stor_arry[y];

	free(stor_arry);
}

/**
 *  * radix_sort - sorts an array of integers using radix sort algorithm
 *   * @array: pointer to the array to be sorted
 *    * @size: size of the array
 *     * Return: Void
 */

void radix_sort(int *array, size_t size)
{
	int maximum;
	size_t a, lsd;

	if (!array || size < 2)
		return;

	maximum = 0;
	for (a = 0; a < size; a++)
		if (array[a] > maximum)
			maximum = array[a];

	for (lsd = 1; maximum / lsd > 0; lsd *= 10)
	{
		LSD_counting_sort(array, size, lsd);
		print_array(array, size);
	}
}
