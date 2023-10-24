#include "sort.h"


/**
 * replace - swaps the values of two integers
 * @m: pointer to the first integer
 * @n: pointer to the second integer
 * Return: Void
 */
void replace(int *m, int *n)
{
	int temp;


	temp = *m;
	*m = *n;
	*n = temp;
}


/**
 * separate - partitions an array into two subarrays around a pivot element
 * @array: pointer to the array to be partitioned
 * @least: starting index of the subarray
 * @large: ending index of the subarray
 * @size: size of the array
 * Return: y
 */


int separate(int *array, int least, int large, size_t size)
{
	int axis = array[large];
	int x = least, y = large;


	while (1)
	{
		while (array[x] < axis)
			x++;
		while (array[y] > axis)
			y--;


		if (x < y)
		{
			replace(&array[x], &array[y]);
			print_array(array, size);
			x++;
			y--;
		}
		else
		{
			if (x != y)
				return (y);
			return (y - 1);
		}
	}
}


/**
 * recur_hoare_qsort - sorts an array using Hoare's quicksort
 * algorithm recursively
 * @array: pointer to the array to be sorted
 * @least: starting index of the subarray
 * @large: ending index of the subarray
 * @size: size of the array
 */


void recur_hoare_qsort(int *array, int least, int large, size_t size)
{
	int x;


	if (least < large)
	{
		x = separate(array, least, large, size);
		if (x > least)
			recur_hoare_qsort(array, least, x, size);
		recur_hoare_qsort(array, x + 1, large, size);
	}
}


/**
 * quick_sort_hoare - sorts an array using Hoare's quicksort algorithm
 * @array: pointer to the array to be sorted
 * @size: size of the array
 * Return: Void
 */


void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	recur_hoare_qsort(array, 0, size - 1, size);
}
