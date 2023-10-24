#include "sort.h"

/**
 * change_int - swaps the values of two integers
 * @m: pointer to the first integer
 * @y: pointer to the second integer
 *
 * Return: Void
 */


void change_int(int *m, int *y)
{
	int tmp;


	tmp = *m;
	*m = *y;
	*y = tmp;
}


/**
 * bit_merge - merges subarrays in a bitwise manner
 * @array: pointer to the array to be merged
 * @least: starting index of the subarray
 * @total: total number of elements in the subarray
 * @comp: comparison flag (1 for ascending, 0 for descending)
 * @size: size of the array
 * Return: Void
 */
void bit_merge(int *array, int least, int total, int comp, size_t size)
{
	int x, y;


	if (total > 1)
	{
		y = total / 2;
		for (x = least; x < least + y; x++)
		{
			if (((array[x] > array[x + y]) && comp == 1) ||
					(comp == 0 && (array[x] < array[x + y])))
				change_int(&array[x], &array[x + y]);
		}
		bit_merge(array, least, y, comp, size);
		bit_merge(array, least + y, y, comp, size);
	}
}


/**
 * bit_sort - recursively sorts an array using bitwise merge sort algorithm
 * @array: pointer to the array to be sorted
 * @least: starting index of the subarray
 * @total: total number of elements in the subarray
 * @comp: comparison flag (1 for ascending, 0 for descending)
 * @size: size of the array
 * Return: Void
 */


void bit_sort(int *array, int least, int total, int comp, size_t size)
{
	int y;


	if (total > 1)
	{
		y = total / 2;
		printf("Merging [%d/%d] ", total, (int)size);
		if (comp == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + least, total);
		bit_sort(array, least, y, 1, size);
		bit_sort(array, least + y, y, 0, size);
		bit_merge(array, least, total, comp, size);
		printf("Result [%d/%d] ", total, (int)size);
		if (comp == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + least, total);
	}
}


/**
 * bitonic_sort - sorts an array using bitonic sort algorithm
 * @array: pointer to the array to be sorted
 * @size: size of the array
 * Return: Void
 */


void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bit_sort(array, 0, size, 1, size);
}
